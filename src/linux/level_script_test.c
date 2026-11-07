#include "level_script.h"
#include "native_rng.h"
#include "native_camera.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void word(unsigned char *p, unsigned value)
{
    p[0]=(unsigned char)value;p[1]=(unsigned char)(value>>8);
}

static void dword(unsigned char *p, unsigned value)
{
    word(p,value);word(p+2,value>>16);
}

/* Two functions with real headers, byte-addressed locals, optional conditions
 * and a virtual pair after code_end (the layout rejected before Abilene). */
static size_t fixture(unsigned char data[1024], const unsigned char *a, size_t as,
                        const unsigned char *b, size_t bs,
                        const unsigned char *conditions, size_t cs)
{
    memset(data,0,1024);memcpy(data,"SOOL",4);word(data+8,2);
    size_t offset=26;
    for (unsigned i=0;i<2;i++) {
        const unsigned char *code=i?b:a;size_t size=i?bs:as;
        size_t cond=i?0:cs;
        dword(data+10+i*4,(unsigned)offset);
        unsigned char *fn=data+offset;
        word(fn,18);word(fn+2,24);word(fn+4,(unsigned)(24+size+cond));
        word(fn+6,1);word(fn+8,cond?(unsigned)(24+size):UINT16_MAX);
        word(fn+10,0);word(fn+12,(unsigned)(24+size));word(fn+14,1);word(fn+16,24);
        memcpy(fn+24,code,size);
        if (cond) memcpy(fn+24+size,conditions,cond);
        word(fn+24+size+cond,0);word(fn+26+size+cond,0);
        offset+=24+size+cond+4;
    }
    dword(data+4,(unsigned)offset);return offset;
}

static void test_inventory_snapshot(void)
{
    FILE *trace=tmpfile();assert(trace);
    for (unsigned scenario=0;scenario<4;scenario++) {
        unsigned char body[64];size_t at=0;
        for (unsigned n=5;n;n--) {
            unsigned i=n-1u;body[at++]=0x0a;
            word(body+at,scenario==2 && i==4?3:i&1u);at+=2;
            word(body+at,scenario==3 && i==4?256:scenario==1?64:64+i*3u);at+=2;
        }
        body[at++]=5;word(body+at,0x33);at+=2;body[at++]=0x41;body[at++]=0;
        const unsigned char end[]={0};unsigned char data[1024];
        size_t size=fixture(data,body,at,end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.native.player_lives=5;script.native.native_word_44=2;script.native.player_money=317;
        script.native.player_dynamite=7;script.native.player_cards=1;
        uint16_t before[2][256];
        for (unsigned i=0;i<2;i++) memcpy(before[i],script.contexts[i].vm.locals,sizeof(before[i]));
        ll_level_script_update(&script);
        if (scenario>=2) {
            assert(script.blocked_count==1 && script.contexts[0].vm.stack_size==11);
            for (unsigned i=0;i<2;i++) assert(!memcmp(before[i],script.contexts[i].vm.locals,sizeof(before[i])));
        } else {
            assert(!script.blocked_count && script.contexts[0].vm.stack_size==5);
            if (scenario==1) {
                assert(script.contexts[0].vm.locals[64]==5 && script.contexts[1].vm.locals[64]==2);
            } else {
                const uint16_t values[5]={5,2,317,7,1};
                for (unsigned i=0;i<5;i++) assert(script.contexts[i&1u].vm.locals[64+i*3u]==values[i]);
            }
        }
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_camera_shake_and_latch(void)
{
    FILE *trace=tmpfile();assert(trace);
    for (unsigned scenario=0;scenario<6;scenario++) {
        unsigned char body[]={5,0xf4,1,5,0x4a,1,0x3d,5,1,1,5,0x2b,0,0x51,5,0x58,0,0x3d,0};
        if (scenario==1) word(body+1,(uint16_t)-500);
        const unsigned char end[]={0};unsigned char data[1024];
        size_t size=fixture(data,body,sizeof(body),end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.native.camera_follow_instance_plus_one=scenario==4?0:1;
        script.native.camera_vertical_mode=(uint8_t)(scenario==2?0:scenario==3?3:1);
        script.native.camera_lock=(uint8_t)(scenario==5);
        script.native.camera_follow_height=(int16_t)(scenario==1?-5999:5999);
        script.native.camera_follow_reference[1]=INT32_MAX-100;
        ll_level_script_update(&script);
        assert(!script.blocked_count && script.native.level_event_latch==1 && !script.native.player_word);
        assert(script.native.camera_follow_height==(scenario==0?6000:scenario==1?-6000:5999));
        int32_t wrapped=(int32_t)(INT32_MIN+399);
        assert(script.native.camera_follow_reference[1]==(scenario>=2 && scenario<=4?wrapped:INT32_MAX-100));
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_scripted_x_approach(void)
{
    static const struct {
        int32_t start,finish;
        int16_t target,speed;
        uint8_t projection;
        unsigned previous_updates;
        uint16_t complete;
    } cases[]={
        {0,100,10,100,1,0,0},{1000,900,0,100,1,0,0},
        {950,950,10,100,1,0,1},{1000,1000,10,100,1,0,1},
        {900,900,10,100,1,0,1},{899,999,10,100,1,0,0},
        {100,100,0,100,1,0,1},{101,1,0,100,1,0,0},
        {0,0,10,0,1,0,0},{0,0,10,-1,1,0,1},
        {0,67,10,101,2,0,0},{0,151,10,101,1,1,0},
        {-3277000,-3276900,-32768,100,1,0,0},
        {0,0,400,100,1,0,1} /* Native signed-word delta chooses the wrong side at large distances. */
    };
    FILE *trace=tmpfile();assert(trace);
    for (unsigned i=0;i<sizeof(cases)/sizeof(cases[0]);i++) {
        unsigned char body[]={5,0,0,5,0,0,5,8,0,0x52,5,0x58,0,0x3d,0};
        word(body+1,(uint16_t)cases[i].speed);word(body+4,(uint16_t)cases[i].target);
        const unsigned char end[]={0};unsigned char data[1024];
        size_t size=fixture(data,body,sizeof(body),end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        LL_LevelScriptObject *object=&script.objects[150];
        object->present=1;object->kind=1;object->pose=&object->private_pose;
        object->pose->position[0]=cases[i].start;object->pose->position[1]=-273;object->pose->position[2]=932;
        script.contexts[0].instance=150;script.native.projection_mode=cases[i].projection;
        script.updates=cases[i].previous_updates;ll_level_script_update(&script);
        assert(!script.blocked_count && script.native.player_word==cases[i].complete);
        assert(object->pose->position[0]==cases[i].finish && object->pose->position[1]==-273 && object->pose->position[2]==932);
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_scene_and_profile_requests(void)
{
    FILE *trace=tmpfile();assert(trace);
    for (unsigned scenario=0;scenario<3;scenario++) {
        unsigned char body[]={5,3,0,5,0x12,0,0x3d,5,9,0,5,0x58,0,0x3d,0};
        word(body+1,scenario==1?0:scenario==2?4:3);
        const unsigned char end[]={0};unsigned char data[1024];
        size_t size=fixture(data,body,sizeof(body),end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        ll_level_script_update(&script);
        if (scenario==1 || scenario==2) {
            assert(script.blocked_count==1 && !script.scene_requested && !script.native.player_word);
            assert(script.contexts[0].vm.stack_size==2);
        } else {
            assert(!script.blocked_count && script.scene_requested && script.requested_scene==3 && script.native.player_word==9);
            LL_LevelScriptContext before[2]={script.contexts[0],script.contexts[1]};
            unsigned calls=script.calls;
            for (unsigned i=0;i<8;i++) ll_level_script_update(&script);
            assert(script.updates==1 && script.calls==calls && !memcmp(before,script.contexts,sizeof(before)));
        }
        ll_level_script_close(&script);
    }
    for (unsigned scenario=0;scenario<3;scenario++) {
        unsigned char body[]={5,0,1,5,0x51,0,0x3d,5,0x1e,0,0x3c,5,0xb9,0,0x3c,
            5,0x3e,0,0x50,5,0x58,0,0x3d,0};
        if (scenario==1) word(body+1,3);
        if (scenario==2) word(body+1,1);
        const unsigned char end[]={0};unsigned char data[1024];
        size_t size=fixture(data,body,sizeof(body),end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.native.control_profile=script.native.saved_control_profile=2;
        ll_level_script_update(&script);
        if (scenario==1) assert(script.blocked_count==1 && script.native.control_profile==2);
        else {
            assert(!script.blocked_count && script.native.control_profile==(scenario==2?1:0));
            assert(script.native.player_word==script.native.control_profile && script.native.previous_control_profile==2);
            assert(script.native.saved_control_profile==script.native.control_profile && !script.native.timer_manager_registered);
        }
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_reload_and_display_override(void)
{
    FILE *trace=tmpfile();assert(trace);
    for (unsigned scenario=0;scenario<4;scenario++) {
        unsigned char body[]={5,1,1,5,0xbf,0,0x51,5,18,0,0x28,0x3b,
            5,0xb9,0,0x3c,5,1,0,5,0x48,0,0x3d,0};
        word(body+1,scenario==1?0x100u:scenario==2?0xffffu:0x101u);
        const unsigned char end[]={0};unsigned char data[1024];size_t size=fixture(data,body,sizeof(body),end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.native.player_lives=scenario==3?0:5;
        ll_level_script_update(&script);
        assert(script.contexts[0].vm.locals[18]==1 && script.native.force_full_display==(scenario==1?0:scenario==2?255:1));
        if (scenario==3) {
            assert(script.blocked_count==1 && !script.scene_requested && !script.scene_reload);
            assert(strstr(script.contexts[0].error,"game-over"));
        } else {
            assert(!script.blocked_count && script.scene_requested && script.scene_reload && !script.requested_scene);
            unsigned updates=script.updates,calls=script.calls;LL_LevelScriptContext before=script.contexts[0];
            for (unsigned i=0;i<8;i++) ll_level_script_update(&script);
            assert(script.updates==updates && script.calls==calls && !memcmp(&before,&script.contexts[0],sizeof(before)));
        }
        ll_level_script_close(&script);
    }
    /* Both original handlers can run in one burst; reset never overwrites an explicit scene word. */
    const unsigned char body[]={5,3,0,5,0x12,0,0x3d,5,1,0,5,0x48,0,0x3d,0},end[]={0};
    unsigned char data[1024];size_t size=fixture(data,body,sizeof(body),end,sizeof(end),NULL,0);
    LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));ll_level_script_update(&script);
    assert(!script.blocked_count && script.scene_requested && script.scene_reload && script.requested_scene==3);
    ll_level_script_close(&script);fclose(trace);
}

static void test_payload_flag_query(void)
{
    FILE *trace=tmpfile();assert(trace);
    for (unsigned scenario=0;scenario<6;scenario++) {
        unsigned char body[]={5,0,0,5,150,0,5,0x83,0,0x52,5,0x58,0,0x3d,0};
        uint16_t mask=scenario==0?0xffffu:scenario==1?0x20u:0x40u;
        word(body+1,mask);
        const unsigned char end[]={0};unsigned char data[1024];
        size_t size=fixture(data,body,sizeof(body),end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        LL_LevelScriptObject *object=&script.objects[150];
        object->present=(uint8_t)(scenario!=3);object->kind=(uint8_t)(scenario==4?5:1);
        object->pose=scenario==5?NULL:&object->private_pose;object->native_payload_flags=0x10028u;
        ll_level_script_update(&script);
        if (scenario<3) assert(!script.blocked_count && script.native.player_word==(scenario==0?0x28u:scenario==1?0x20u:0u));
        else assert(script.blocked_count==1 && strstr(script.contexts[0].error,"payload flag query"));
        assert(object->native_payload_flags==0x10028u);ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_sprite_sequence_release(void)
{
    const unsigned char release[]={5,255,255,5,0x6a,0,0x3d,0},end[]={0};
    unsigned char data[1024];size_t size=fixture(data,release,sizeof(release),end,sizeof(end),NULL,0);
    FILE *trace=tmpfile();assert(trace);
    for (unsigned kind=5;kind<=7;kind+=2) {
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        LL_LevelScriptObject *sprite=&script.objects[150];sprite->present=1;sprite->kind=(uint8_t)kind;
        sprite->pose=&sprite->private_pose;sprite->native_wrapper_word=0xabcd;
        sprite->visible=1;
        sprite->sprite_primitives_present=sprite->sprite_animation_active=1;sprite->sprite_animation_owner=2;
        script.contexts[0].instance=150;script.contexts[1].vm.host_animation_wait=1;
        ll_level_script_update(&script);
        assert(!script.blocked_count && !sprite->sprite_primitives_present && !sprite->sprite_animation_active &&
            !sprite->sprite_animation_owner);
        assert(sprite->native_wrapper_word==(kind==5?0xab00:0xabcd));
        assert(sprite->visible==(kind==7));
        assert(script.contexts[1].vm.host_animation_wait); /* Releasing a sequence does not invoke its completion callback. */
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_inventory_updates(void)
{
    static const struct { uint16_t kind;int16_t before,amount,after; } cases[]={
        {0,32767,1,-32768},{0,-32768,-1,32767},{1,3,1,3},{1,2,5,3},
        {1,0,-1,-1},{1,4,-1,3},{1,-32768,-1,3},{2,-32768,-1,32767},
        {3,2,-5,0},{3,32767,1,0},{4,0,1,1},{4,32767,1,-32768},{65535,0,1,0}};
    FILE *trace=tmpfile();assert(trace);
    for (unsigned i=0;i<sizeof(cases)/sizeof(cases[0]);i++) {
        unsigned char command[]={5,0,0,5,0,0,5,0x35,0,0x3e,0};
        word(command+1,(uint16_t)cases[i].amount);word(command+4,cases[i].kind);
        const unsigned char end[]={0};unsigned char data[1024];
        size_t size=fixture(data,command,sizeof(command),end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.native.money_timer=99;script.native.player_invincible=1;
        if (cases[i].kind==0) script.native.player_dynamite=cases[i].before;
        if (cases[i].kind==1) script.native.native_word_44=(uint16_t)cases[i].before;
        if (cases[i].kind==2) script.native.player_lives=cases[i].before;
        if (cases[i].kind==3) script.native.player_money=cases[i].before;
        if (cases[i].kind==4) script.native.player_cards=cases[i].before;
        ll_level_script_update(&script);assert(!script.blocked_count);
        assert(script.native.player_dynamite==(cases[i].kind==0?cases[i].after:0));
        assert((int16_t)script.native.native_word_44==(cases[i].kind==1?cases[i].after:3));
        assert(script.native.player_lives==(cases[i].kind==2?cases[i].after:5));
        assert(script.native.player_money==(cases[i].kind==3?cases[i].after:0));
        assert(script.native.player_cards==(cases[i].kind==4?cases[i].after:0));
        assert(script.native.dynamite_dirty==(cases[i].kind==0) && script.native.player_health_dirty==(cases[i].kind==1));
        assert(script.native.money_dirty==(cases[i].kind==3) && script.native.cards_dirty==(cases[i].kind==4));
        assert(script.native.money_timer==(cases[i].kind==3?0u:99u) && !script.native.native_flags);
        ll_level_script_close(&script);
    }
    const unsigned char reset[]={5,2,0,5,4,0,5,0x35,0,0x3e,
        5,7,0,5,3,0,5,0x35,0,0x3e,5,3,0,5,0,0,5,0x35,0,0x3e,5,0xb9,0,0x3c,0},end[]={0};
    unsigned char data[1024];size_t size=fixture(data,reset,sizeof(reset),end,sizeof(end),NULL,0);
    LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);
    assert(!script.blocked_count && !script.native.player_dynamite && script.native.native_word_44==3);
    assert(script.native.player_money==7 && script.native.player_cards==2 && script.native.money_dirty && script.native.cards_dirty);
    ll_level_script_close(&script);
    fclose(trace);
}

static void test_coordinate_queries(void)
{
    const unsigned ids[3]={0x0c,0x24,0x25};
    const int32_t coordinates[2][3]={{-199,-99,INT32_MIN},{3276800,199,99}};
    const uint16_t expected[2][3]={{65535,0,(uint16_t)-21474836},{32768,1,0}};
    FILE *trace=tmpfile();assert(trace);
    for (unsigned sample=0;sample<2;sample++) for (unsigned axis=0;axis<3;axis++) {
        unsigned char query[]={5,150,0,5,0,0,0x51,5,0x58,0,0x3d,0};
        word(query+4,ids[axis]);
        const unsigned char end[]={0};unsigned char data[1024];
        size_t size=fixture(data,query,sizeof(query),end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.objects[150].present=1;script.objects[150].pose=&script.objects[150].private_pose;
        memcpy(script.objects[150].pose->position,coordinates[sample],sizeof(coordinates[sample]));
        ll_level_script_update(&script);
        assert(!script.blocked_count && script.native.player_word==expected[sample][axis]);
        assert(!memcmp(script.objects[150].pose->position,coordinates[sample],sizeof(coordinates[sample])));
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_model_intensity(void)
{
    assert(ll_native_material_flat(0x24fe8040u,256)==0x24fe8040u);
    assert(ll_native_material_flat(0x24fe8040u,128)==0x247f4020u);
    assert(ll_native_material_flat(0x24fe8040u,512)==0x24fc0080u);
    assert(ll_native_material_flat(0x24010101u,-1)==0x24ffffffu);
    assert(ll_native_material_textured(0x24000000u,256)==0x24808080u);
    assert(ll_native_material_textured(0x24000000u,128)==0x24404040u);
    assert(ll_native_material_textured(0x24000000u,-1)==0xffffffffu);
    assert(ll_native_material_textured(0x24000000u,1024)==0x26020200u);
    FILE *trace=tmpfile();assert(trace);
    const uint16_t coefficients[4]={128,65535,32767,128};
    for (unsigned scenario=0;scenario<4;scenario++) {
        unsigned char command[]={5,0,0,5,150,0,5,0x30,0,0x3e,0};
        word(command+1,coefficients[scenario]);
        const unsigned char end[]={0};unsigned char data[1024];
        size_t size=fixture(data,command,sizeof(command),end,sizeof(end),NULL,0);
        LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.bib.model_count=1;script.bib.models=calloc(1,sizeof(*script.bib.models));
        assert(script.bib.models);
        script.bib.models[0].group_count=1;
        script.bib.models[0].groups=calloc(1,sizeof(*script.bib.models[0].groups));
        assert(script.bib.models[0].groups);
        script.bib.models[0].groups[0].type=scenario==3?4:2;
        script.bib.models[0].groups[0].element_count=1;
        script.model_materials=calloc(1,sizeof(*script.model_materials));assert(script.model_materials);
        script.model_materials[0]=(LL_NativeMaterial){256,1};
        for (unsigned i=150;i<153;i++) {
            script.objects[i].present=1;
            script.objects[i].private_material=(LL_NativeMaterial){256,1};
            script.objects[i].material=i==152?&script.objects[i].private_material:script.model_materials;
        }
        script.contexts[0].instance=152; /* Explicit target150, independent of context binding. */
        ll_level_script_update(&script);
        if (scenario==3) {
            assert(script.blocked_count==1 && script.model_materials[0].multiplier==256);
            assert(strstr(script.contexts[0].error,"Gouraud"));
        } else {
            assert(!script.blocked_count && script.model_materials[0].multiplier==(int16_t)coefficients[scenario]);
            assert(script.objects[151].material->multiplier==(int16_t)coefficients[scenario]);
        }
        assert(script.objects[152].material->multiplier==256);
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_ballistic_queries(void)
{
    const unsigned char motion[]={5,0,0,5,60,0,5,206,255,5,26,255,5,0x18,0,0x40,
        5,1,1,5,0x19,0,0x3d,0};
    const unsigned char step[]={5,30,0,5,10,0,5,150,0,5,1,0,5,0x0f,0,0x54,5,0x58,0,0x3d,0};
    unsigned char data[1024];size_t size=fixture(data,motion,sizeof(motion),step,sizeof(step),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    LL_LevelScriptObject *object=&script.objects[150];object->present=object->kind=1;
    object->pose=&object->private_pose;object->pose->position[0]=1000;
    object->pose->position[1]=-1000;object->pose->position[2]=200;
    object->reduced=object->draw_suppressed=1; /* Explicit script queries remain independent of presentation. */
    script.contexts[0].instance=150;script.contexts[1].instance=151;
    ll_level_script_update(&script);
    assert(!script.blocked_count && !script.native.player_word && object->motion_positive_bounce==1);
    assert(object->pose->position[0]==775 && object->pose->position[1]==-1035 && object->pose->position[2]==265);
    assert(object->motion[0]==-220 && object->motion[1]==-20 && object->motion[2]==50);
    script.contexts[1].body_done=0;ll_level_script_update(&script);
    assert(object->pose->position[0]==455 && object->pose->position[1]==-1035 && object->pose->position[2]==350);
    assert(object->motion[0]==-205 && object->motion[1]==25 && object->motion[2]==35);
    int32_t held[3];memcpy(held,object->pose->position,sizeof(held));
    ll_level_script_update(&script);assert(!memcmp(held,object->pose->position,sizeof(held))); /* No automatic extra step. */
    script.updates=4;object->pose->position[1]=101;
    object->motion[0]=100;object->motion[1]=20;object->motion[2]=-30;object->motion_word=3;
    script.contexts[1].body_done=0;ll_level_script_update(&script);
    assert(!script.native.player_word && object->motion_word==2 && object->motion[0]==17 &&
        object->motion[1]==-7 && object->motion[2]==17);
    script.updates=6;object->pose->position[1]=100;object->motion_word=0;
    object->motion[1]=-50;script.contexts[1].body_done=0;ll_level_script_update(&script);
    assert(script.native.player_word==1 && object->pose->position[1]==65 &&
        !object->motion[0] && !object->motion[1] && !object->motion[2]);
    word(script.code_data+script.program.functions[1].offset+34,UINT16_MAX);
    script.updates=8;object->pose->position[1]=-101;
    script.contexts[1].body_done=0;ll_level_script_update(&script);
    assert(!script.native.player_word && object->pose->position[1]==-99 && object->motion[1]==30);
    script.contexts[1].body_done=0;ll_level_script_update(&script);
    assert(script.native.player_word==1 && object->pose->position[1]==-99 && !object->motion[1]);
    script.code_data[script.program.functions[1].offset+31]=3;
    script.code_data[script.program.functions[1].offset+32]=1; /* Absent instance259. */
    memcpy(held,object->pose->position,sizeof(held));script.contexts[1].body_done=0;ll_level_script_update(&script);
    assert(script.contexts[1].blocked && !memcmp(held,object->pose->position,sizeof(held)));
    ll_level_script_close(&script);fclose(trace);
}

static void test_collision_callbacks(void)
{
    const unsigned char register_link[]={7,18,0,5,151,0,5,0xf5,0,0x3e,0};
    const unsigned char query[]={5,151,0,5,0x8e,0,0x51,5,0x58,0,0x3d,0};
    unsigned char data[1024];size_t size=fixture(data,register_link,sizeof(register_link),query,sizeof(query),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    for (unsigned replay=0;replay<2;replay++) {
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        for (unsigned instance=150;instance<153;instance++) {
            LL_LevelScriptObject *object=&script.objects[instance];
            object->present=1;object->kind=1;object->native_callback_enabled=1;
            object->pose=&object->private_pose;object->bounds=object->private_bounds;
        }
        LL_LevelScriptObject *owner=&script.objects[150],*target=&script.objects[151];
        const int32_t a[6]={-100,-1000,-100,100,0,100},b[6]={-20,-200,-20,20,0,20};
        memcpy(owner->bounds,a,sizeof(a));memcpy(target->bounds,b,sizeof(b));
        target->pose->position[1]=-800;target->collision_previous_position[1]=-1100;
        script.contexts[0].instance=script.contexts[1].instance=150;
        ll_level_script_update(&script);
        assert(!script.blocked_count && !script.native.collision_blocked_count);
        assert(owner->collision_registered && owner->collision_links[0].callback_mode==4);
        assert(target->pose->position[1]==-800 && target->native_payload_flags==0x28);
        assert(script.native.player_word==0); /* SOOL queries precede this callback. */
        script.contexts[1].body_done=0;ll_level_script_update(&script);
        assert(script.native.player_word==0x80 && target->pose->position[1]==-1000);
        if (replay) {
            target->pose=NULL;ll_level_script_update(&script);
            assert(owner->collision_blocked && script.native.collision_blocked_count==1);
            assert(strstr(owner->collision_error,"bounded model root"));
            ll_level_script_update(&script);assert(script.native.collision_blocked_count==1);
        } else {
            /* Rebinding a SOOL context never transfers the old wrapper's links. */
            script.contexts[1].instance=152;script.contexts[1].body_done=0;
            owner->pose->position[0]=10;ll_level_script_update(&script);
            assert(!script.native.player_word && target->pose->position[0]==10);
            owner->native_callback_enabled=0;owner->pose->position[0]=20;
            ll_level_script_update(&script);assert(target->pose->position[0]==10);
            owner->native_callback_enabled=1;owner->pose->position[0]=30;
            ll_level_script_update(&script);assert(target->pose->position[0]==20);
            target->native_payload_flags|=0x8000;
            script.contexts[0].vm.locals[18]=7;script.contexts[0].body_done=0;
            ll_level_script_update(&script);
            assert(!owner->collision_links[0].active && target->native_payload_flags==0x8000);
            script.contexts[0].vm.locals[18]=4;script.contexts[0].body_done=0;
            ll_level_script_update(&script);
            assert(script.contexts[0].blocked && strstr(script.contexts[0].error,"mode4..6"));
        }
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_script_damage(void)
{
    const unsigned char end[]={0};unsigned char data[1024];
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    const struct {
        uint16_t mode, amount, health, callback;
        uint8_t invincible, busy, dead, airborne, rejected;
    } cases[]={
        {1,1,2,1,0,0,0,0,0},{1,0,3,1,0,0,0,0,0},
        {1,65534,5,1,0,0,0,0,0},{1,32767,3,1,0,0,0,0,0},
        {1,1,3,1,1,0,0,0,0},{2,1,3,2,0,1,0,0,0},
        {1,1,3,0,0,0,1,0,0},{0,1,2,3,0,0,0,0,0},
        {4,1,2,1,0,0,0,1,0},{4,1,3,0,0,0,0,0,1}
    };
    for (unsigned i=0;i<sizeof(cases)/sizeof(cases[0]);i++) {
        unsigned char call[]={5,0,0,5,0,0,5,0x23,0,0x52,0x3b,0};
        word(call+1,cases[i].amount);word(call+4,cases[i].mode);
        size_t size=fixture(data,call,sizeof(call),end,sizeof(end),NULL,0);
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.player.present=1;script.player.hurt_callback=(uint8_t)(cases[i].busy?2:0);
        script.native.player_instance_plus_one=151;script.native.native_word_44=3;script.native.player_lives=5;
        script.native.player_invincible=cases[i].invincible;
        script.objects[150].present=1; /* Disabled controller isolates the native damage entry. */
        script.objects[150].native_payload_flags=cases[i].airborne?0:0x20;
        if (cases[i].dead) script.objects[150].native_payload_flags|=0x100;
        ll_level_script_update(&script);
        assert(script.blocked_count==cases[i].rejected && !script.player.blocked);
        assert(script.native.native_word_44==cases[i].health && script.player.hurt_callback==cases[i].callback);
        assert(script.native.player_lives==(cases[i].amount==32767?4:5));
        assert(script.native.player_health_dirty==(!cases[i].invincible && !cases[i].busy && !cases[i].dead && !cases[i].rejected));
        assert(!script.audio.plays);ll_level_script_close(&script);
    }
    /* AX is not defined by the native byte-return ABI: refuse a consumer
     * before changing health, rather than publishing a fabricated word. */
    const unsigned char observed[]={5,1,0,5,1,0,5,0x23,0,0x52,5,0x58,0,0x3d,0};
    size_t size=fixture(data,observed,sizeof(observed),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.player.present=1;script.native.player_instance_plus_one=151;
    script.native.native_word_44=3;script.objects[150].present=1;
    ll_level_script_update(&script);
    assert(script.contexts[0].blocked && strstr(script.contexts[0].error,"AX return"));
    assert(script.native.native_word_44==3 && !script.player.hurt_callback);
    ll_level_script_close(&script);
    /* A POP in the separate condition stream does not discard a body result. */
    const unsigned char separate_pop[]={0x3b,1};
    size=fixture(data,observed,10,end,sizeof(end),separate_pop,sizeof(separate_pop));
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.player.present=1;script.native.player_instance_plus_one=151;
    script.native.native_word_44=3;script.objects[150].present=1;
    ll_level_script_update(&script);
    assert(script.contexts[0].blocked && strstr(script.contexts[0].error,"AX return"));
    assert(script.native.native_word_44==3 && !script.player.hurt_callback);
    ll_level_script_close(&script);fclose(trace);
}

static void test_level_audio(void)
{
    enum { BANK=8+28+0x8000, HEADER=BANK+8, FRAMES=HEADER+64, BIZ_SIZE=FRAMES+48 };
    unsigned char *biz=calloc(BIZ_SIZE,1);assert(biz);
    dword(biz,8);dword(biz+4,BANK);dword(biz+20,1);
    dword(biz+BANK,1);dword(biz+BANK+4,8);
    memcpy(biz+HEADER,"VAGp",4);memcpy(biz+HEADER+32,"test",5);
    biz[HEADER+18]=0x3e;biz[HEADER+19]=0x80;
    biz[FRAMES]=biz[FRAMES+16]=8;
    memset(biz+FRAMES+2,0x77,14);memset(biz+FRAMES+18,0x77,14);biz[FRAMES+33]=7;
    /* Play a positional original-bank sound, read its actual voice handle,
     * query activity/free slots, then stop it through the script dispatcher. */
    const unsigned char play[]={
        0x10,5,200,0,5,0xc8,0,0x3d,5,600&255,600>>8,5,0xd0,0,0x3d,
        5,1,0,5,0,8,5,0xff,0x1f,5,0x9c,0xff,5,200,0,5,150,0,5,0x99,0,0x56,
        5,18,0,0x28,0x3b,7,18,0,5,0x9a,0,0x51,5,20,0,0x28,0x3b,
        5,0x9b,0,0x50,5,22,0,0x28,0x3b,
        7,18,0,5,0xc9,0,0x3d,7,18,0,5,0x9a,0,0x51,5,24,0,0x28,0x3b,0};
    const unsigned char end[]={0};unsigned char data[1024];
    size_t size=fixture(data,play,sizeof(play),end,sizeof(end),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    assert(ll_level_script_set_biz(&script,biz,BIZ_SIZE));
    script.objects[150].present=1;script.objects[150].pose=&script.objects[150].private_pose;
    script.native.depth=4000;script.native.projection=804;
    ll_level_script_update(&script);
    assert(!script.blocked_count && script.contexts[0].body_done && script.audio.plays==1);
    assert(script.contexts[0].vm.locals[18]==1 && script.contexts[0].vm.locals[20]==1);
    assert(script.contexts[0].vm.locals[22]==63 && script.contexts[0].vm.locals[24]==0);
    assert(script.audio.base==200 && script.audio.multiplier==600 && script.audio.rate[0]==15900);
    ll_level_script_close(&script);
    /* Offscreen owners are culled before sample resolution. A missing
     * owner or sample in a disabled driver is likewise a native silent path. */
    const unsigned char culled[]={5,1,0,5,0,4,5,0xff,0x1f,5,0,0,5,0xff,0xff,5,150,0,
        5,0x99,0,0x56,5,0x58,0,0x3d,0};
    for (unsigned disabled=0;disabled<2;disabled++) {
        size=fixture(data,culled,sizeof(culled),end,sizeof(end),NULL,0);
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        assert(ll_level_script_set_biz(&script,biz,BIZ_SIZE));
        script.audio.enabled=(uint8_t)!disabled;
        script.native.depth=4000;script.native.projection=804;
        script.objects[150].present=!disabled;script.objects[150].pose=&script.objects[150].private_pose;
        script.objects[150].pose->position[0]=100000;
        ll_level_script_update(&script);
        assert(!script.blocked_count && !script.audio.plays && !script.native.player_word);
        ll_level_script_close(&script);
    }
    const unsigned char pan[]={5,151,0,5,150,0,5,0x98,0,0x52,5,0x58,0,0x3d,0};
    const int32_t horizontal[]={1000,-1000,0};const uint16_t expected[]={0,2048,1024};
    for (unsigned i=0;i<3;i++) {
        size=fixture(data,pan,sizeof(pan),end,sizeof(end),NULL,0);
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        for (unsigned instance=150;instance<152;instance++) {
            script.objects[instance].present=1;script.objects[instance].pose=&script.objects[instance].private_pose;
        }
        script.objects[151].pose->position[0]=horizontal[i];
        script.native.depth=4000;script.native.projection=804;
        ll_level_script_update(&script);assert(!script.blocked_count && script.native.player_word==expected[i]);
        ll_level_script_close(&script);
    }
    fclose(trace);free(biz);
}

static void test_animation_runtime(void)
{
    const unsigned char forward[]={5,0,0,5,0x1b,0,0x3d,0};
    const unsigned char reverse[]={5,0,0,5,5,0,0x3d,
        5,150,0,5,0x73,0,0x51,5,18,0,0x28,0x3b,
        5,150,0,5,0x74,0,0x51,5,20,0,0x28,0x3b,0};
    unsigned char data[1024],raw[24]={0};
    size_t size=fixture(data,forward,sizeof(forward),reverse,sizeof(reverse),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.bib.valid=1;script.bib.raw_data=raw;script.bib.raw_size=sizeof(raw);script.bib.selector_count=1;
    script.bib.animations=calloc(1,sizeof(*script.bib.animations));assert(script.bib.animations);
    LL_BibAnimationTable *table=script.bib.animations;
    table->record_count=2;table->record_type=2;table->loop_displacement[0]=1000;
    table->records=calloc(2,sizeof(*table->records));assert(table->records);
    for (unsigned i=0;i<2;i++) {
        unsigned at=i*12;word(raw+at,10);word(raw+at+4,0x4038);
        word(raw+at+6,i?500:100);word(raw+at+8,i?40:20);word(raw+at+10,i?900:300);
        table->records[i]=(LL_BibAnimationRecord){at,12,10,raw+at};
    }
    LL_LevelScriptObject *object=&script.objects[150];
    object->present=1;object->kind=1;object->pose=&object->private_pose;
    object->root_rotation=object->private_root_rotation;
    object->root_rotation[0]=object->root_rotation[4]=object->root_rotation[8]=4096;
    object->pose->position[0]=10000;object->visible=object->update_enabled=object->native_callback_enabled=1;
    script.contexts[0].instance=script.contexts[1].instance=150;
    script.contexts[1].body_done=1;
    ll_level_script_update(&script);
    assert(!script.blocked_count && object->animation_root_motion && !object->animation_root_axis);
    assert(object->pose->position[0]==10000 && object->animation_motion_reference==100);
    ll_level_script_update(&script);
    assert(object->pose->position[0]==10116 && object->pose->position[1]==0 && object->pose->position[2]==0);
    script.updates=8;ll_level_script_update(&script);
    assert(object->pose->position[0]==10962); /* Last -> first seam, before wrapping. */
    ll_level_script_update(&script);
    assert(object->pose->position[0]==11091 && object->animation_motion_cycles==1);
    object->native_callback_enabled=0;script.updates=20;ll_level_script_update(&script);
    assert(object->pose->position[0]==11091); /* No root update while disabled. */
    object->native_callback_enabled=1;ll_level_script_update(&script);
    assert(object->pose->position[0]==12480 && object->animation_motion_cycles==2);
    script.contexts[1].body_done=0;ll_level_script_update(&script);
    assert(!script.blocked_count && object->animation_reverse && !object->animation_once);
    assert(object->animation_frame==1 && !object->animation_next_frame);
    assert(script.contexts[1].vm.locals[18]==0 && script.contexts[1].vm.locals[20]==1);
    assert(!script.contexts[1].vm.host_animation_wait);
    int32_t origin=object->pose->position[0];
    ll_level_script_update(&script);assert(object->pose->position[0]==origin-117);
    script.updates=31;ll_level_script_update(&script);
    assert(object->pose->position[0]==origin-1092 && object->animation_motion_cycles==1);
    /* A rotated root receives the extracted local delta, not a second
     * copy of the same displacement on its visible skeleton. */
    object->root_rotation[0]=object->root_rotation[8]=-4096;
    int32_t previous=object->pose->position[0],reference=object->animation_motion_reference;
    ll_level_script_update(&script);
    assert(object->pose->position[0]-previous==reference-object->animation_motion_reference);
    ll_level_script_close(&script);
    const unsigned char done[]={5,150,0,5,0x74,0,0x51,5,0x58,0,0x3d,0};
    const unsigned char end[]={0};size=fixture(data,done,sizeof(done),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));script.objects[150].present=1;
    ll_level_script_update(&script);assert(!script.blocked_count && script.native.player_word==1);
    ll_level_script_close(&script);fclose(trace);
}

static void test_enemy_projectile(void)
{
    const unsigned char shoot[]={0x10,5,2,0,5,1,0,5,0x40,0,0x3e,
        5,2,0,5,0x09,3,5,1,0,5,150,0,5,0x33,0,0x54,5,18,0,0x28,0x3b,
        5,151,0,5,0,0,7,18,0,5,0x34,0,0x53,5,20,0,0x28,0x3b,
        5,152,0,5,1,0,7,18,0,5,0x34,0,0x53,0x3b,0};
    const unsigned char contact[]={0x32,5,0,0,5,151,0,5,0x35,0,0x52,5,0x58,0,0x3d,0};
    unsigned char data[1024],raw[176]={0},sprite_data[24]={0};
    size_t size=fixture(data,shoot,sizeof(shoot),contact,sizeof(contact),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.bib.valid=1;script.bib.raw_data=raw;script.bib.raw_size=sizeof(raw);script.bib.selector_count=3;
    script.bib.sections=calloc(3,sizeof(*script.bib.sections));assert(script.bib.sections);
    for (unsigned i=1;i<=2;i++) {
        unsigned at=128+(i-1u)*24u;script.bib.sections[i]=(LL_BibSelector){at,at,24,1};
        word(raw+at+2,1);raw[at+4]=1;dword(raw+at+12,4);
        word(raw+at+20,(uint16_t)(int16_t)-8);word(raw+at+22,(uint16_t)(int16_t)-8);
    }
    dword(raw+0x1c,2);dword(raw+0x24,2);dword(raw+68,1);
    word(raw+80,2);word(raw+92,1);word(raw+96,2);word(raw+98,1);
    word(raw+108,10);word(raw+110,0x4008);word(raw+112,100);
    script.bib.model_count=1;script.bib.models=calloc(1,sizeof(*script.bib.models));assert(script.bib.models);
    LL_Bib3dxModel *model=script.bib.models;model->vertex_count=3;
    model->vertices=calloc(3,sizeof(*model->vertices));assert(model->vertices);
    model->vertices[1].position[0]=20;model->vertices[1].position[1]=-100;model->vertices[1].position[2]=200;
    model->data_offsets[1]=64;model->data_sizes[1]=8;model->data_offsets[2]=80;model->data_sizes[2]=24;
    script.bib.animations=calloc(3,sizeof(*script.bib.animations));assert(script.bib.animations);
    LL_BibAnimationTable *animation=script.bib.animations;
    animation->record_count=1;animation->record_type=2;
    animation->records=calloc(1,sizeof(*animation->records));assert(animation->records);
    animation->records[0]=(LL_BibAnimationRecord){108,8,10,raw+108};
    script.biz.valid=1;script.biz.raw_data=sprite_data;script.biz.raw_size=sizeof(sprite_data);
    script.biz.counts[0]=script.biz.counts[1]=script.biz.counts[2]=1;script.biz.sprite_offset=4;
    word(sprite_data+8,4);word(sprite_data+10,16);
    LL_LevelScriptObject *shooter=&script.objects[150];
    shooter->present=1;shooter->kind=1;shooter->pose=&shooter->private_pose;
    shooter->pose->position[0]=1000;shooter->pose->position[2]=4000;
    shooter->root_rotation=shooter->private_root_rotation;
    shooter->root_rotation[2]=shooter->root_rotation[4]=4096;shooter->root_rotation[6]=-4096;
    shooter->animation_active=shooter->animation_pose_present=1;
    LL_LevelScriptObject *target=&script.objects[151];
    target->present=1;target->wrapper_flags=4;target->pose=&target->private_pose;target->bounds=target->private_bounds;
    target->pose->position[0]=944;target->pose->position[1]=-100;target->pose->position[2]=3879;
    ll_level_script_update(&script);
    assert(!script.blocked_count && script.projectiles.shots_fired==1 && script.projectiles.enemy_shots_fired==1);
    assert(script.contexts[0].vm.locals[18]==0 && script.contexts[0].vm.locals[20]==1);
    LL_LevelProjectile *slot=&script.projectiles.slots[0];
    assert(slot->flash.pose->position[0]==1200 && slot->flash.pose->position[1]==-100 && slot->flash.pose->position[2]==3880);
    assert(slot->velocity[0]==-256 && slot->velocity[1]==0 && slot->velocity[2]==-1);
    assert(!slot->flags && slot->target_count==1 && slot->targets[0]==151 && slot->targets[1]==152);
    assert(target->wrapper_flags==5 && script.projectiles.enemy_hit_instance==151 && !script.native.collision_event_latch);
    ll_level_script_update(&script);
    assert(!script.blocked_count && script.native.player_word==1 && !script.projectiles.enemy_hit_instance);
    ll_level_script_close(&script);
    const unsigned char bad_target[]={5,151,0,5,5,0,5,0,0,5,0x34,0,0x53,0};
    const unsigned char end[]={0};size=fixture(data,bad_target,sizeof(bad_target),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));script.projectiles.initialized=1;
    ll_level_script_update(&script);assert(script.blocked_count==1 && script.contexts[0].vm.stack_size==4);
    assert(!script.projectiles.slots[0].targets[4]);
    ll_level_script_close(&script);fclose(trace);
}

static void test_health_words(void)
{
    const unsigned char read_health[]={5,0x44,0,0x50,5,0x58,0,0x3d,0};
    const unsigned char reset[]={5,0xb9,0,0x3c,0};
    const unsigned char end[]={0};unsigned char data[1024];
    size_t size=fixture(data,read_health,sizeof(read_health),end,sizeof(end),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    assert(script.native.native_word_44==3 && script.native.player_lives==5);
    script.native.native_word_44=0;script.native.player_word=99;
    ll_level_script_update(&script);
    assert(!script.blocked_count && !script.native.player_word);
    ll_level_script_close(&script);
    size=fixture(data,reset,sizeof(reset),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.native.native_word_44=0;script.native.player_lives=2;
    script.native.player_health_dirty=1;script.native.player_invincible=1;script.native.native_flags=1;
    ll_level_script_update(&script);
    assert(!script.blocked_count && script.native.native_word_44==3 && script.native.player_lives==2);
    assert(script.native.player_health_dirty && script.native.player_invincible && !script.native.native_flags);
    ll_level_script_close(&script);fclose(trace);
}

static void test_projectile_box(void)
{
    const unsigned char query[]={5,0,0,5,0,0,5,0,0,5,0x39,0,0x53,5,0x58,0,0x3d,0};
    const unsigned char end[]={0};unsigned char data[1024],raw[28]={0};
    size_t size=fixture(data,query,sizeof(query),end,sizeof(end),NULL,0);
    dword(raw,4);
    const int32_t box[6]={100,-200,300,200,-100,400};
    for (unsigned i=0;i<6;i++) dword(raw+4+i*4,(uint32_t)box[i]);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    for (unsigned scenario=0;scenario<5;scenario++) {
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.bib.valid=1;script.bib.raw_data=raw;script.bib.raw_size=sizeof(raw);script.bib.selector_count=1;
        script.bib.sections=calloc(1,sizeof(*script.bib.sections));assert(script.bib.sections);
        script.bib.animations=calloc(1,sizeof(*script.bib.animations));assert(script.bib.animations);
        script.bib.sections[0]=(LL_BibSelector){0,0,sizeof(raw),1};
        script.projectiles.initialized=1;
        LL_LevelProjectile *slot=&script.projectiles.slots[0];
        slot->flags=scenario==2?0:1;slot->target_count=scenario==2?0:2;
        slot->ball.pose=&slot->ball.private_pose;slot->ball.bounds=slot->ball.private_bounds;
        slot->ball.pose->position[0]=70;slot->ball.pose->position[1]=-150;slot->ball.pose->position[2]=350;
        const int32_t bounds[6]={-30,-30,-60,30,30,60};memcpy(slot->ball.bounds,bounds,sizeof(bounds));
        if (scenario==1) slot->ball.pose->position[0]--; /* One unit outside inclusive edge. */
        if (scenario==3) script.bib.selector_count=0; /* Missing BIB box is native false. */
        if (scenario==4) script.projectiles.initialized=0;
        ll_level_script_update(&script);
        if (scenario==4) {
            assert(script.blocked_count==1 && script.contexts[0].vm.stack_size==4);
            assert(slot->flags==1 && slot->target_count==2);
        } else {
            unsigned hit=scenario==0 || scenario==2;
            assert(!script.blocked_count && script.native.player_word==hit);
            assert(slot->flags==(hit?0:1) && slot->target_count==(hit?(scenario==2?65535:1):2));
            assert(!script.native.collision_event_latch && !script.projectiles.enemy_hit_instance);
        }
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_display_fade(void)
{
    const unsigned char start[]={5,0,0,5,0x10e&255,1,0x3d,5,0x4c,0,0x50,5,0x58,0,0x3d,0};
    const unsigned char end[]={0};unsigned char data[1024];
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    for (unsigned direction=0;direction<2;direction++) {
        unsigned char code[sizeof(start)];memcpy(code,start,sizeof(code));code[1]=(unsigned char)direction;
        size_t size=fixture(data,code,sizeof(code),end,sizeof(end),NULL,0);
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        ll_level_script_update(&script);
        assert(!script.blocked_count && script.native.player_word==1);
        assert(script.native.fade_direction==(direction?1:2) && script.native.fade_alpha==(direction?247:8));
        for (unsigned i=1;i<31;i++) ll_level_script_update(&script);
        assert(script.native.fade_direction && script.native.fade_alpha==(direction?7:248));
        ll_level_script_update(&script);
        assert(!script.native.fade_direction && script.native.fade_alpha==(direction?0:255));
        ll_level_script_update(&script);assert(script.native.fade_alpha==(direction?0:255));
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_scene_sprite_removal(void)
{
    const unsigned char remove[]={5,150,0,5,0x27,0,0x51,5,0x58,0,0x3d,0};
    const unsigned char end[]={0};unsigned char data[1024];
    size_t size=fixture(data,remove,sizeof(remove),end,sizeof(end),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.objects[150].present=1;script.objects[150].pose=&script.objects[150].private_pose;
    script.native.scene_sprite_slots[1]=78;script.native.scene_sprite_slots[3]=79;
    script.native.player_word=999;
    ll_level_script_update(&script);
    assert(!script.blocked_count && !script.native.player_word);
    assert(!script.native.scene_sprite_slots[1] && script.native.scene_sprite_slots[3]==79);
    ll_level_script_close(&script);fclose(trace);
}

static void test_checkpoint_command(void)
{
    const unsigned char reset[]={5,0,0,5,0x48,0,0x3d,0};
    const unsigned char end[]={0};unsigned char data[1024];
    size_t size=fixture(data,reset,sizeof(reset),end,sizeof(end),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    for (unsigned scenario=0;scenario<3;scenario++) {
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.native.player_instance_plus_one=151;script.native.player_lives=scenario==2?0:2;
        script.native.native_word_44=1;script.native.native_flags=7;script.native.level_event_latch=1;
        script.native.player_reset_position_active=scenario==1;
        script.objects[150].present=1;script.objects[150].native_payload_flags=0x120;
        const unsigned hud_slots[4]={0,3,4,1};
        for (unsigned i=0;i<4;i++) {
            script.native.object_registry[hud_slots[i]]=(uint16_t)(152u+i);
            script.objects[151u+i].present=1;
        }
        ll_level_script_update(&script);
        if (!scenario) {
            assert(!script.blocked_count && script.native.native_flags==2 && !script.native.level_event_latch);
            assert(script.objects[150].native_payload_flags==0x20 && script.native.native_word_44==1);
            assert(script.native.player_lives==2);
            for (unsigned i=0;i<4;i++) assert(script.objects[151u+i].visible);
        } else {
            assert(script.blocked_count==1 && script.contexts[0].vm.stack_size==2);
            assert(script.native.native_flags==7 && script.native.level_event_latch==1);
            assert(script.objects[150].native_payload_flags==0x120);
            assert(strstr(script.contexts[0].error,scenario==1?"path anchor":"game-over"));
        }
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_follow_camera(void)
{
    unsigned char data[1024];const unsigned char end[]={0};
    size_t size=fixture(data,end,sizeof(end),end,sizeof(end),NULL,0);
    FILE *trace=tmpfile();assert(trace);
    LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    LL_LevelNativeSetup *camera=&script.native;
    camera->camera_callback_enabled=1;camera->camera_vertical_mode=1;
    camera->camera_follow_instance_plus_one=151;camera->player_instance_plus_one=151;
    camera->camera_follow_reference[2]=-4000;
    camera->camera_speed=128;camera->camera_limit=100;
    camera->camera_lead_range=2000;camera->camera_lead_enabled=1;camera->camera_side_direction=1;
    camera->camera_bounds[0]=camera->camera_bounds[2]=-1000000;
    camera->camera_bounds[1]=camera->camera_bounds[3]=1000000;
    camera->camera_z_bounds[0]=-800000;camera->camera_z_bounds[1]=800000;
    LL_LevelScriptObject *target=&script.objects[150];
    target->present=1;target->pose=&target->private_pose;target->root_rotation=target->private_root_rotation;
    int32_t angles[3]={0,1024,0};int16_t matrix[3][3];
    ll_native_model_rotation(angles,matrix);memcpy(target->root_rotation,matrix,sizeof(matrix));
    script.player.present=1;script.player.mode=2;
    target->pose->position[0]=100;
    ll_level_script_update(&script);
    assert(!camera->camera_blocked && !script.player.blocked && camera->camera_output_active);
    assert(camera->camera_follow_reference[0]==0 && camera->camera_lead_offset==100);
    assert(camera->camera_render_reference[0]==100 && camera->camera_follow_target[0]==100);
    assert(camera->camera_motion_mode==0 && camera->camera_view_yaw<0);
    target->pose->position[0]=1000;ll_level_script_update(&script);
    assert(camera->camera_motion_mode==7 && camera->camera_follow_reference[0]==900);
    assert(camera->camera_lead_offset==200 && camera->camera_render_reference[0]==1100);
    camera->camera_bounds[1]=1100;target->pose->position[0]=1132;
    ll_level_script_update(&script);
    assert(camera->camera_motion_mode==7 && camera->camera_view_yaw==-128);
    assert(camera->camera_follow_reference[0]==1032 && camera->camera_lead_offset==300);
    assert(camera->camera_render_reference[0]==1100); /* Clamp a copy, retain internal state. */
    target->pose->position[0]=1000;ll_level_script_update(&script);
    assert(camera->camera_motion_mode==0 && camera->camera_follow_reference[0]==1032);
    assert(camera->camera_lead_offset==300); /* Reversing leaves mode7 before moving the reference. */
    camera->camera_motion_mode=0;camera->camera_follow_reference[0]=0;
    camera->camera_lead_enabled=0;camera->camera_lead_offset=0;
    camera->camera_word=1;camera->camera_idle_counter=0;camera->camera_speed=1023;
    script.player.mode=1;
    ll_level_script_update(&script);
    assert(camera->camera_motion_mode==8 && camera->camera_follow_reference[0]==0);
    ll_level_script_update(&script);
    assert(camera->camera_motion_mode==8 && camera->camera_follow_reference[0]==100);
    script.player.mode=2;ll_level_script_update(&script);
    assert(camera->camera_motion_mode==0 && camera->camera_follow_reference[0]==200);
    camera->camera_motion_mode=2;camera->camera_lead_offset=0;
    target->pose->position[0]=1100;ll_level_script_update(&script);
    assert(camera->camera_follow_reference[0]==300 && camera->camera_view_yaw==0);
    camera->camera_motion_mode=3;camera->camera_follow_yaw=123;camera->camera_follow_pitch=17;
    target->pose->position[0]=1200;ll_level_script_update(&script);
    assert(camera->camera_follow_reference[0]==400 && camera->camera_view_yaw==123 && camera->camera_view_pitch==17);
    camera->camera_motion_mode=4;camera->camera_speed=128;
    camera->camera_follow_reference[0]=camera->camera_follow_reference[1]=0;
    target->pose->position[0]=1000;target->pose->position[1]=200;
    ll_level_script_update(&script);
    assert(camera->camera_view_pitch>0 && camera->camera_view_yaw==-128);
    assert(camera->camera_follow_reference[1]==0 && camera->camera_clamp_active && camera->camera_clamp_target_x==1000);
    target->pose->position[0]=2000;ll_level_script_update(&script);
    assert(camera->camera_clamp_active && camera->camera_clamp_target_x==1000);
    camera->camera_lock=1;camera->camera_motion_mode=3;camera->camera_follow_reference[0]=5000;
    ll_level_script_update(&script);
    assert(camera->camera_render_reference[0]>1100); /* Lock suppresses clamping. */
    camera->camera_vertical_mode=2;script.player.mode=4;
    ll_level_script_update(&script);assert(camera->camera_vertical_mode==2);
    script.player.mode=5;ll_level_script_update(&script);assert(camera->camera_vertical_mode==2);
    script.player.mode=6;ll_level_script_update(&script);assert(camera->camera_vertical_mode==1);
    assert(!camera->camera_blocked && !script.player.blocked);
    ll_level_script_close(&script);
    const unsigned char transition[]={5,180,0,5,0,0,5,0xe8,3,5,0,0,5,0,0,
        5,150,0,5,0x5e,1,0x42,0};
    size=fixture(data,transition,sizeof(transition),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    camera=&script.native;camera->camera_mode=1;camera->camera_motion_mode=3;camera->camera_vertical_mode=1;
    camera->camera_follow_reference[0]=camera->camera_follow_reference[1]=100;
    camera->camera_follow_reference[2]=-1000;camera->camera_follow_yaw=123;
    camera->camera_lead_offset=300;camera->camera_clamp_active=1;camera->camera_clamp_target_x=100;
    camera->camera_bounds[0]=camera->camera_bounds[2]=-10000;
    camera->camera_bounds[1]=camera->camera_bounds[3]=10000;
    camera->camera_z_bounds[0]=-800000;camera->camera_z_bounds[1]=800000;
    script.objects[150].present=1;script.objects[150].pose=&script.objects[150].private_pose;
    ll_level_script_update(&script);
    assert(!script.blocked_count && !camera->camera_blocked && camera->camera_transition_remaining==24);
    assert(camera->camera_lead_offset==300 && !camera->camera_clamp_active);
    assert(camera->camera_follow_reference[0]==96 && camera->camera_lookat[0]==96);
    assert(camera->camera_render_reference[0]==396 && camera->camera_follow_yaw==123);
    for (unsigned i=0;i<24;i++) ll_level_script_update(&script);
    assert(camera->camera_transition_complete && camera->camera_motion_mode==3 && camera->camera_lead_offset==300);
    assert(camera->camera_follow_reference[0]==0 && camera->camera_lookat[0]==0 && camera->camera_render_reference[0]==300);
    ll_level_script_close(&script);
    const unsigned char setters[]={5,0xff,0xff,5,0x3a,1,0x3d,
        5,0x00,0x80,5,0x3b,1,0x3d,5,0xff,0xff,5,0x3d,1,0x3d,
        5,2,0,5,0x3f,1,0x3d,0};
    size=fixture(data,setters,sizeof(setters),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.native.camera_follow_distance=4000;
    ll_level_script_update(&script);
    assert(!script.blocked_count);
    assert(script.native.camera_lead_range==0 && script.native.camera_follow_height==-6000 && script.native.depth==20000);
    assert(script.native.camera_side==2 && script.native.camera_side_yaw==2048 && script.native.camera_side_direction==-1);
    assert(script.native.camera_follow_reference[2]==8000);
    ll_level_script_close(&script);fclose(trace);
}

static void test_absolute_camera(void)
{
    const unsigned char transition[]={5,200,0,5,0x9d,0xff,5,100,0,5,2,0,5,0xff,0xff,5,1,0,
        5,0x60,1,0x42,0};
    const unsigned char query[]={5,0,0,5,0x46,0,0x51,5,0x58,0,0x3d,1};
    const unsigned char end[]={0};unsigned char data[1024];
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    for (unsigned side=0;side<2;side++) {
        size_t size=fixture(data,transition,sizeof(transition),end,sizeof(end),query,sizeof(query));
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        LL_LevelNativeSetup *camera=&script.native;
        camera->camera_bounds[0]=camera->camera_bounds[2]=-10000;
        camera->camera_bounds[1]=camera->camera_bounds[3]=10000;
        camera->camera_z_bounds[0]=-10000;camera->camera_z_bounds[1]=10000;
        camera->camera_follow_reference[0]=4;camera->camera_follow_reference[1]=-3;
        camera->camera_lead_offset=7;camera->camera_follow_distance=4000;
        camera->camera_follow_pitch=2;camera->camera_follow_yaw=3;camera->camera_motion_mode=3;
        camera->camera_side=(uint16_t)(side?2:1);camera->camera_side_yaw=(int16_t)(side?2048:0);
        camera->camera_follow_instance_plus_one=151;
        ll_level_script_update(&script);
        assert(!script.blocked_count && !camera->camera_blocked && camera->camera_transition_absolute);
        assert(camera->camera_transition_remaining==4 && !camera->camera_transition_complete);
        assert(!camera->camera_follow_instance_plus_one && !camera->camera_transition_target && !camera->camera_lead_offset);
        assert(camera->camera_follow_reference[0]==28 && camera->camera_follow_reference[1]==-23 && camera->camera_follow_reference[2]==40);
        assert(camera->camera_view_pitch==21 && camera->camera_view_yaw==(side?392:-18));
        assert(!script.native.player_word);
        for (unsigned i=0;i<4;i++) ll_level_script_update(&script);
        assert(!camera->camera_transition_active && camera->camera_transition_complete && !camera->camera_transition_remaining);
        /* Signed divisions/SAR retain an undershoot; there is no final snap. */
        assert(camera->camera_follow_reference[0]==96 && camera->camera_follow_reference[1]==-103 && camera->camera_follow_reference[2]==200);
        assert(camera->camera_follow_pitch==99 && camera->camera_follow_yaw==(side?1948:-99));
        assert(!script.native.player_word); /* Query phase precedes the final camera callback. */
        assert(camera->camera_lookat[2]==(side?-3800:4200) && camera->camera_motion_mode==3);
        assert(!memcmp(camera->camera_follow_target,camera->camera_lookat,sizeof(camera->camera_lookat)));
        ll_level_script_update(&script);
        assert(camera->camera_render_reference[0]==96 && camera->camera_view_pitch==99 && script.native.player_word==1);
        ll_level_script_close(&script);
    }
    size_t size=fixture(data,transition,sizeof(transition),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    LL_LevelNativeSetup *camera=&script.native;
    camera->camera_bounds[0]=10;camera->camera_bounds[1]=20;
    camera->camera_bounds[2]=-10;camera->camera_bounds[3]=10;
    camera->camera_z_bounds[0]=-5;camera->camera_z_bounds[1]=5;
    camera->camera_follow_reference[0]=-100;camera->camera_follow_distance=4000;
    ll_level_script_update(&script);
    /* Unlike ordinary following, 547b0 publishes the retained reference itself. */
    assert(camera->camera_follow_reference[0]==10 && camera->camera_render_reference[0]==10);
    assert(camera->camera_follow_reference[1]==-2 && camera->camera_follow_reference[2]==1);
    for (unsigned i=0;i<4;i++) ll_level_script_update(&script);
    assert(camera->camera_follow_reference[0]==20 && camera->camera_follow_reference[1]==-10 && camera->camera_follow_reference[2]==5);
    ll_level_script_close(&script);
    unsigned char negative_speed[sizeof(transition)];memcpy(negative_speed,transition,sizeof(transition));
    word(negative_speed+1,65535);
    size=fixture(data,negative_speed,sizeof(negative_speed),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.native.camera_lock=1;
    ll_level_script_update(&script);assert(!script.blocked_count && !script.native.camera_transition_active);
    ll_level_script_close(&script);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);assert(!script.blocked_count && script.native.camera_transition_remaining==4);
    ll_level_script_close(&script);
    size=fixture(data,transition,sizeof(transition),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    camera=&script.native;
    camera->camera_bounds[0]=camera->camera_bounds[2]=camera->camera_z_bounds[0]=INT32_MIN;
    camera->camera_bounds[1]=camera->camera_bounds[3]=camera->camera_z_bounds[1]=INT32_MAX;
    camera->camera_follow_reference[0]=INT32_MAX;
    ll_level_script_update(&script);
    assert(!script.blocked_count && camera->camera_reference_step[0]==20);
    assert(camera->camera_follow_reference[0]==INT32_MIN+19); /* SHL12 wraps before IDIV/SAR. */
    ll_level_script_close(&script);fclose(trace);
}

static void test_camera_limits_transition(void)
{
    const unsigned char setters[]={5,150,0,5,0,0,5,0xec,0xff,5,10,0,5,0xf6,0xff,
        5,0x61,1,0x41,5,150,0,5,0x70,0x17,5,0x5f,1,0x3e,0};
    const unsigned char end[]={0};unsigned char data[1024];
    size_t size=fixture(data,setters,sizeof(setters),end,sizeof(end),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    LL_LevelNativeSetup *camera=&script.native;
    camera->camera_callback_enabled=1;camera->depth=4000;
    camera->camera_bounds[0]=-1000;camera->camera_bounds[1]=1000;
    camera->camera_bounds[2]=-1000;camera->camera_bounds[3]=0;
    ll_level_script_update(&script);
    assert(!script.blocked_count && camera->depth==4150 && camera->camera_bounds[2]==-1150);
    camera->camera_lock=1;
    for (unsigned i=0;i<6;i++) ll_level_script_update(&script);
    assert(camera->depth==5050 && camera->camera_bounds[2]==-2000);
    for (unsigned i=0;i<7;i++) ll_level_script_update(&script);
    assert(camera->depth==6000 && camera->camera_bounds[2]==-2000);
    ll_level_script_close(&script);
    unsigned char negatives[sizeof(setters)];memcpy(negatives,setters,sizeof(setters));
    word(negatives+1,(uint16_t)(int16_t)-5);word(negatives+20,65535);word(negatives+23,65535);
    size=fixture(data,negatives,sizeof(negatives),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    camera=&script.native;camera->camera_callback_enabled=1;camera->depth=4000;
    camera->camera_bounds[2]=-1000;
    ll_level_script_update(&script);
    assert(!script.blocked_count && camera->depth==4500 && camera->camera_bounds[2]==-995);
    assert(camera->camera_depth_target==10000 && camera->camera_depth_step==500);
    ll_level_script_close(&script);fclose(trace);
}

static void test_script_input(void)
{
    const unsigned char query[]={5,0,0,5,0,0,0x51,5,18,0,0x28,0x3b,
        5,0,0,5,1,0,0x51,5,20,0,0x28,0x3b,
        5,0,0,5,1,0,0x51,5,22,0,0x28,0x3b,0x32,0x04,24,0};
    const unsigned char other[]={5,0,0,5,1,0,0x51,5,0x58,0,0x3d,0x32,0x04,24,0};
    unsigned char data[1024];size_t size=fixture(data,query,sizeof(query),other,sizeof(other),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    const uint16_t held[4]={0x8020,0x8020,0,0x20},pressed[4]={0x8020,0,0,0x20};
    for (unsigned i=0;i<4;i++) {
        ll_level_script_set_input(&script,held[i]);ll_level_script_update(&script);
        assert(!script.blocked_count && script.contexts[0].vm.locals[18]==held[i]);
        assert(script.contexts[0].vm.locals[20]==pressed[i] && script.contexts[0].vm.locals[22]==pressed[i]);
        assert(script.native.player_word==pressed[i]);
    }
    ll_level_script_close(&script);fclose(trace);
}

static void hit_player_with_targeted_ball(LL_LevelScript *script)
{
    unsigned target=script->native.player_instance_plus_one-1u;
    LL_LevelProjectile *shot=&script->projectiles.slots[0];
    shot->flags=1;shot->target_count=1;shot->targets[0]=(uint16_t)target;shot->first_frame=1;
    memset(shot->velocity,0,sizeof(shot->velocity));
    memcpy(shot->ball.pose->position,script->objects[target].pose->position,sizeof(shot->ball.pose->position));
    ll_level_script_update(script);
    assert(!shot->flags); /* An invulnerable player still consumes the ball. */
}

/* Change only the synthetic fixture's command word, then run it through SOOL. */
static void queue_test_controller(LL_LevelScript *script, uint16_t entry)
{
    const LL_SoolFunction *function=&script->program.functions[0];
    unsigned char *body=script->code_data+function->offset+function->state_offsets[0];
    assert(body[0]==5 && body[7]==0xba);
    word(body+1,entry);
    memset(&script->contexts[0].vm,0,sizeof(script->contexts[0].vm));
    script->contexts[0].body_done=0;
}

static void test_player(void)
{
    static const uint16_t directions[8]={0x20,0x30,0x10,0x90,0x80,0xc0,0x40,0x60};
    for (unsigned i=0;i<8;i++) assert(ll_level_player_direction(directions[i]|0x4000u)==i);
    assert(ll_level_player_direction(0)==8 && ll_level_player_direction(0xa0)==8);
    int32_t speed=0,displacement=0;
    ll_level_player_accelerate(&speed,&displacement,23,10,1);
    assert(speed==20 && displacement==30);
    ll_level_player_accelerate(&speed,&displacement,23,10,1);
    assert(speed==23 && displacement==46);
    ll_level_player_accelerate(&speed,&displacement,0,13,1);
    assert(speed==0 && displacement==10);
    speed=-4;
    assert(!ll_level_player_accelerate(&speed,&displacement,0,6,1) && speed==0);
    assert(ll_level_player_accelerate(&speed,&displacement,0,6,1) && displacement==0);
    unsigned char data[1024],path[112]={0},sprite_data[24]={0};
    const unsigned char controller[]={5,4,0,5,255,255,5,0xba,0,0x3e,
        5,4,0,5,0,0,5,0xba,0,0x3e,0}; /* BA4 must preserve the first command's pending entry. */
    const unsigned char pool[]={5,21,0,5,20,0,5,0x40,0,0x3e,0};
    size_t size=fixture(data,controller,sizeof(controller),pool,sizeof(pool),NULL,0);
    FILE *trace=tmpfile();assert(trace);
    LL_LevelScript script={0};assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    word(path+2,1);dword(path+4,20);dword(path+16,12);dword(path+20,10000);
    dword(path+40,10000);
    script.bib.valid=1;script.bib.raw_data=path;script.bib.raw_size=sizeof(path);
    script.bib.selector_count=22;
    script.bib.sections=calloc(22,sizeof(*script.bib.sections));assert(script.bib.sections);
    script.bib.sections[0]=(LL_BibSelector){0,0,52,1};
    script.bib.sections[20]=(LL_BibSelector){52,52,24,1};
    script.bib.sections[21]=(LL_BibSelector){76,76,36,1};
    word(path+54,1);path[56]=1;dword(path+64,4);word(path+72,(uint16_t)-8);word(path+74,(uint16_t)-8);
    word(path+78,2);path[80]=1;
    for (unsigned i=0;i<2;i++) { dword(path+88+i*12,4);word(path+96+i*12,(uint16_t)-4); }
    script.biz.valid=1;script.biz.raw_data=sprite_data;script.biz.raw_size=sizeof(sprite_data);
    script.biz.counts[0]=script.biz.counts[1]=script.biz.counts[2]=1;script.biz.sprite_offset=4;
    word(sprite_data+8,4);word(sprite_data+10,16);
    script.bib.animations=calloc(22,sizeof(*script.bib.animations));assert(script.bib.animations);
    for (unsigned i=1;i<20;i++) {
        LL_BibAnimationTable *table=&script.bib.animations[i];
        table->selector=i;table->record_count=1;table->record_type=1;
        table->records=calloc(1,sizeof(*table->records));assert(table->records);
        table->records[0].sample_count=10;
    }
    LL_BibAnimationTable *jump_animation=&script.bib.animations[16];
    free(jump_animation->records);jump_animation->record_count=3;
    jump_animation->records=calloc(3,sizeof(*jump_animation->records));assert(jump_animation->records);
    for (unsigned i=0;i<3;i++) jump_animation->records[i].sample_count=2;
    int16_t facing=0;
    assert(ll_level_player_facing(&script.bib,0,0,5000,1024,0,0x20,&facing)==1 && facing==1024);
    assert(ll_level_player_facing(&script.bib,0,0,5000,1024,0,0x80,&facing)==1 && facing==3072);
    assert(ll_level_player_facing(&script.bib,0,0,5000,1024,2048,0x80,&facing)==1 && facing==1024);
    assert(ll_level_player_facing(&script.bib,0,0,5000,1024,0,0x10,&facing)==0);
    unsigned char junction_data[92]={0};
    word(junction_data+2,2);dword(junction_data+4,48);
    dword(junction_data+16,12);dword(junction_data+20,10000);
    dword(junction_data+24,1);dword(junction_data+28,24);
    dword(junction_data+40,24);dword(junction_data+44,10000);
    dword(junction_data+48,1);dword(junction_data+52,0);
    dword(junction_data+68,10000);dword(junction_data+88,10000);
    LL_BibFile junction=script.bib;
    LL_BibSelector junction_section={0,0,sizeof(junction_data),1};
    junction.raw_data=junction_data;junction.raw_size=sizeof(junction_data);
    junction.sections=&junction_section;junction.selector_count=1;
    assert(ll_level_player_facing(&junction,0,0,599,1024,0,0x10,&facing)==1 && facing==3072);
    /* Native endpoint lookup uses<601, but reversing uses<600. */
    assert(ll_level_player_facing(&junction,0,0,600,1024,0,0x10,&facing)==1 && facing==1024);
    assert(ll_level_player_facing(&junction,0,0,601,1024,0,0x10,&facing)==0);
    LL_LevelScriptObject *object=&script.objects[150];
    object->present=1;object->kind=1;object->player_control_index=1;
    object->update_enabled=1;object->native_callback_enabled=1;object->native_payload_flags=0x20;
    object->pose=&object->private_pose;object->pose->position[0]=5000;
    object->bounds=object->private_bounds;object->root_rotation=object->private_root_rotation;
    object->path.attached=1;object->path.distance=5000;object->path.yaw=1024;
    object->path.previous_position[0]=5000;
    script.native.player_instance_plus_one=151;script.native.projection_mode=1;
    script.player.present=1;script.player.initialized=1;script.player.mode=1;
    ll_level_script_set_input(&script,0x80f0);
    assert(script.input_actions==0x8000);
    ll_level_script_set_input(&script,0x20);
    ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.mode==2 && script.player.event==4);
    assert(object->animation_selector==5 && object->animation_pose_present);
    assert(object->pose->position[0]==5030 && object->pose->position[1]==0 && object->pose->position[2]==0);
    assert(script.player.speed==20 && script.player.displacement==30);
    assert(script.player.pressed_actions==0x20 && object->path.distance==5030);
    ll_level_script_update(&script);
    assert(!script.player.blocked && object->pose->position[0]==5076);
    assert(script.player.pressed_actions==0 && script.player.speed==23);
    ll_level_script_set_input(&script,0x4020);
    ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.mode==3 && script.player.event==5);
    assert(script.player.speed==43 && script.player.displacement==76 && object->animation_selector==6);
    assert(object->pose->position[0]==5152);
    ll_level_script_update(&script);ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.speed==66 && script.player.displacement==132);
    ll_level_script_set_input(&script,0);
    ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.mode==1 && script.player.event==0);
    assert(script.player.speed==40 && script.player.displacement==93 && object->animation_selector==1);
    ll_level_script_update(&script);ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.speed==0);
    int32_t stopped=object->pose->position[0];
    ll_level_script_update(&script);assert(object->pose->position[0]==stopped);
    object->native_payload_flags|=0x400; /* native right-input restriction */
    ll_level_script_set_input(&script,0x20);ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.actions==0 && object->pose->position[0]==stopped);
    object->native_payload_flags&=~0x400u;
    ll_level_script_set_input(&script,0x8000);ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.mode==4 && script.player.event==15);
    assert(script.player.vertical_speed==-113 && script.player.vertical_displacement==-232);
    assert(object->pose->position[1]==-232 && !(object->native_payload_flags&0x40020u));
    assert(object->animation_selector==16 && script.player.speed==0);
    ll_level_script_update(&script);
    assert(script.player.event==15 && script.player.mode==4);
    ll_level_script_update(&script);
    assert(script.player.event==18 && script.player.mode==4 && object->animation_selector==19);
    int minimum_y=object->pose->position[1],saw_apex_pause=0,saw_ground_flag=0,saw_landing=0;
    for (unsigned i=3;i<24;i++) {
        ll_level_script_update(&script);
        if (object->pose->position[1]<minimum_y) minimum_y=object->pose->position[1];
        if (script.player.mode==4 && script.player.vertical_speed==0) saw_apex_pause=1;
        if (script.player.mode==5 && (object->native_payload_flags&0x20u)) saw_ground_flag=1;
        if (script.player.mode==6) saw_landing=1;
        assert(!script.player.blocked && object->pose->position[1]<=0);
    }
    assert(minimum_y==-1240 && saw_apex_pause && saw_ground_flag && saw_landing);
    assert(script.player.mode==1 && object->pose->position[1]==0 && script.player.vertical_speed==0);
    assert((object->native_payload_flags&0x60u)==0x20u && script.player.event==0);
    /* Holding jump never rearms the native latch. */
    for (unsigned i=0;i<10;i++) ll_level_script_update(&script);
    assert(script.player.mode==1 && object->pose->position[1]==0);
    ll_level_script_set_input(&script,0);ll_level_script_update(&script);
    assert(object->native_payload_flags&0x40000u);
    ll_level_script_set_input(&script,0xc020);ll_level_script_update(&script);
    assert(script.player.mode==4 && script.player.vertical_speed==-143);
    assert(script.player.vertical_displacement==-292 && script.player.displacement==30 && script.player.air_motion==2);
    int running_min=object->pose->position[1];
    for (unsigned i=0;i<7;i++) {
        ll_level_script_update(&script);
        if (object->pose->position[1]<running_min) running_min=object->pose->position[1];
    }
    assert(script.player.speed==79 && script.player.displacement==158);
    ll_level_script_set_input(&script,0);ll_level_script_update(&script);
    assert(script.player.air_motion==0 && script.player.displacement==158);
    if (object->pose->position[1]<running_min) running_min=object->pose->position[1];
    ll_level_script_update(&script);assert(script.player.displacement==119);
    for (unsigned i=0;i<40 && script.player.mode!=1;i++) {
        ll_level_script_update(&script);
        if (object->pose->position[1]<running_min) running_min=object->pose->position[1];
    }
    assert(!script.player.blocked && running_min==-1925 && script.player.mode==1);
    assert(object->pose->position[1]==0);
    /* The native fall-entry impulse is64; its first two substeps are69/74. */
    object->native_payload_flags&=~0x20u;object->pose->position[1]=-10000;
    memcpy(object->path.previous_position,object->pose->position,sizeof(object->path.previous_position));
    ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.mode==5 && script.player.event==18);
    assert(script.player.vertical_speed==74 && script.player.vertical_displacement==143 && object->pose->position[1]==-9857);
    for (unsigned i=0;i<15;i++) ll_level_script_update(&script);
    assert(script.player.mode==5 && script.player.vertical_speed==145 && script.player.vertical_displacement==290);
    for (unsigned i=0;i<100 && script.player.mode!=1;i++) ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.mode==1 && object->pose->position[1]==0);
    stopped=object->pose->position[0];
    ll_level_script_set_input(&script,0x2000);ll_level_script_update(&script);
    assert(!script.player.blocked && !script.blocked_count && script.projectiles.initialized);
    assert(script.player.mode==7 && script.player.event==7 && script.player.shot_pending);
    assert(script.projectiles.shots_fired==0 && object->pose->position[0]==stopped);
    ll_level_script_update(&script);
    LL_LevelProjectile *shot=&script.projectiles.slots[0];
    assert(script.projectiles.shots_fired==1 && shot->flags==2 && shot->flash_active);
    assert(shot->flash.pose->position[0]==stopped+800 && shot->flash.pose->position[1]==-925);
    assert(shot->velocity[0]==256 && shot->velocity[1]==0 && shot->velocity[2]==-1);
    assert(shot->ball.pose->position[0]==shot->flash.pose->position[0]+256);
    assert(shot->ball.bounds[0]==-30 && shot->ball.bounds[5]==60 && !shot->first_frame);
    const int16_t identity[9]={4096,0,0,0,4096,0,0,0,4096};
    const int32_t translation[3]={0,0,0};int32_t quad[4][3];
    assert(ll_level_script_world_sprite_vertices(&script,&shot->ball,identity,translation,quad));
    assert(quad[0][0]==shot->ball.pose->position[0]-40 && quad[1][0]==quad[0][0]+70);
    assert(quad[0][1]==shot->ball.pose->position[1]-23 && quad[2][1]==shot->ball.pose->position[1]+17);
    assert(quad[0][2]==shot->ball.pose->position[2]+17);
    for (unsigned i=0;i<3;i++) ll_level_script_update(&script);
    assert(script.projectiles.shots_fired==1); /* No arbitrary held-fire timer. */
    for (unsigned i=0;i<3;i++) ll_level_script_update(&script);
    assert(script.projectiles.shots_fired==2 && !script.player.blocked);
    ll_level_script_set_input(&script,0x2010);ll_level_script_update(&script);
    assert(script.player.event==9 && script.player.aim_index==2 && script.player.aim_angle==1024);
    uint32_t shots=script.projectiles.shots_fired;
    ll_level_script_update(&script);assert(script.projectiles.shots_fired==shots+1);
    LL_LevelProjectile *up=&script.projectiles.slots[shots];
    assert(up->velocity[0]==0 && up->velocity[1]==-256 && up->velocity[2]==0);
    assert(up->ball.pose->position[1]==-2156);
    unsigned up_flashes=0;
    for (unsigned i=0;i<10;i++) if (script.projectiles.slots[i].flash_active &&
        script.projectiles.slots[i].flash.pose->position[1]==-1900) up_flashes++;
    assert(up_flashes==1);
    ll_level_script_set_input(&script,0x2080);ll_level_script_update(&script);
    assert(script.player.event==11 && object->bounds[1]==script.player.base_bounds[1]+800);
    int16_t yaw;assert(ll_native_model_yaw(object->root_rotation,&yaw) && yaw==1023);
    ll_level_script_set_input(&script,0);ll_level_script_update(&script);
    assert(script.player.mode==8 && script.player.event==14 && !script.player.shot_pending);
    for (unsigned i=0;i<8;i++) ll_level_script_update(&script);
    assert(script.player.mode==1 && script.player.event==0 && object->bounds[1]==script.player.base_bounds[1]);
    /* Same native inclusive AABB hit, with the wrapper's ID in the event
     * latch. A visual registry word must not replace that ID. */
    LL_LevelScriptObject *target=&script.objects[151];
    target->present=1;target->wrapper_flags=4;target->native_wrapper_word=999;
    target->pose=&target->private_pose;target->bounds=target->private_bounds;
    shot->flags=2;shot->first_frame=1;
    for (unsigned a=0;a<3;a++) target->pose->position[a]=shot->ball.pose->position[a]+shot->velocity[a];
    ll_level_script_update(&script);
    assert(!shot->flags && target->wrapper_flags==5 && script.native.collision_event_latch==151);
    /* First movement skips the viewport/Z limits, then the next checks do
     * retire the descriptor and restore its root to zero. */
    shot->flags=2;shot->first_frame=1;shot->ball.pose->position[2]=21000;
    ll_level_script_update(&script);assert(shot->flags==2 && !shot->first_frame);
    ll_level_script_update(&script);assert(!shot->flags && shot->ball.pose->position[2]==0);
    ll_level_script_set_input(&script,0xa000);ll_level_script_update(&script);
    assert(script.player.mode==4 && script.player.vertical_speed==-143 && !script.player.blocked);
    ll_level_script_set_input(&script,0);
    for (unsigned i=0;i<48;i++) ll_level_script_update(&script);
    assert(script.player.mode==1);
    const uint8_t expected_aim[2][9]={{0,1,2,3,4,4,5,5,0},{4,3,2,1,0,5,5,4,0}};
    const int16_t expected_angle[2][9]={{0,512,1024,1536,2048,2048,0,0,0},
        {2048,1536,1024,512,0,0,0,2048,0}};
    for (unsigned side=0;side<2;side++) {
        int32_t angles[3]={0,side?3072:1024,0};int16_t matrix[3][3];
        ll_native_model_rotation(angles,matrix);memcpy(object->root_rotation,matrix,sizeof(matrix));
        for (unsigned i=0;i<9;i++) {
            script.player.shot_pending=0;
            ll_level_script_set_input(&script,(uint16_t)(0x2000u|(i<8?directions[i]:0)));
            ll_level_script_update(&script);
            assert(!script.player.blocked && script.player.mode==7);
            assert(script.player.aim_index==expected_aim[side][i] && script.player.aim_angle==expected_angle[side][i]);
            assert(script.player.event==7u+expected_aim[side][i]);
        }
    }
    /* A full ball pool must not evict an existing shot. Flash allocation
     * remains independent and can still use its first free descriptor. */
    for (unsigned i=0;i<10;i++) {
        LL_LevelProjectile *slot=&script.projectiles.slots[i];
        slot->flags=2;slot->flash_active=0;
        memset(slot->velocity,0,sizeof(slot->velocity));
        memset(slot->ball.pose->position,0,sizeof(slot->ball.pose->position));
        slot->ball.pose->position[0]=(int32_t)(111+i);
    }
    shots=script.projectiles.shots_fired;script.player.shot_pending=1;
    ll_level_script_set_input(&script,0x2000);ll_level_script_update(&script);
    assert(script.projectiles.shots_fired==shots && script.projectiles.shots_dropped==1);
    assert(script.projectiles.slots[0].flash_active);
    for (unsigned i=0;i<10;i++) assert(script.projectiles.slots[i].ball.pose->position[0]==(int32_t)(111+i));
    /* At native clock77, elapsed8 equals the two durations: the strict>
     * boundary keeps the final frame. Completion still draws that frame
     * once before the next draw callback sees the cleared active flag. */
    script.player.present=0;script.updates=31;
    shot->flash_active=1;shot->flash_started=69;
    ll_level_script_update(&script);
    assert(shot->flash_active && shot->flash_visible && shot->flash.sprite_frame==1);
    ll_level_script_update(&script);assert(!shot->flash_active && shot->flash_visible);
    ll_level_script_update(&script);assert(!shot->flash_active && !shot->flash_visible);
    /* Enable eight distinguishable native samples to verify the controller
     * callbacks, independently of the graphics-only BIZ fixture above. */
    script.audio.ready=script.audio.enabled=script.audio.device_active=1;
    script.audio.sample_count=8;script.audio.base=200;
    for (unsigned i=0;i<8;i++) {
        script.audio.pcm[i]=calloc(56,sizeof(int16_t));assert(script.audio.pcm[i]);
        script.audio.samples[i].sample_count=56;script.audio.samples[i].sample_rate=16000;
    }
    script.player.present=1;script.player.mode=5;script.player.air_motion=0;
    ll_level_script_set_input(&script,0);
    script.player.vertical_speed=0;script.player.fall_sound_ticks=0;
    object->native_payload_flags&=~0x20u;object->pose->position[1]=-20000;
    memcpy(object->path.previous_position,object->pose->position,sizeof(object->path.previous_position));
    for (unsigned i=0;i<39;i++) ll_level_script_update(&script);
    assert(!script.audio.plays && script.player.fall_sound_ticks==39);
    ll_level_script_update(&script);
    assert(!script.player.blocked && script.audio.plays==1 && script.player.fall_sound_ticks==40);
    assert(script.audio.mixer.voices[0].pcm==script.audio.pcm[2] && script.audio.rate[0]==15950);
    ll_level_script_update(&script);assert(script.audio.plays==1);
    object->pose->position[1]=0;object->path.previous_position[1]=0;object->native_payload_flags|=0x20;
    ll_level_script_update(&script);
    assert(script.player.mode==6 && script.audio.plays==2 && script.player.fall_sound_ticks==42);
    assert(script.audio.mixer.voices[1].pcm==script.audio.pcm[3]);
    assert(script.audio.rate[1]==15516 && script.audio.volume[1]==3668);
    ll_level_script_update(&script);
    assert(script.player.mode==1 && !script.player.fall_sound_ticks);
    /* Native internal sounds use bank indices even when SOOL's ID base is
     * nonzero. Idle events2,3,2,1 use samples4,5,6,7, respectively. */
    script.audio.pitch_offset=25;script.player.idle_variation=0;script.updates=300;
    const uint8_t idle_events[4]={2,3,2,1};
    for (unsigned i=0;i<4;i++) {
        script.player.idle_started=0;script.player.animation_cycles=0;object->animation_started=0;
        ll_level_script_update(&script);
        assert(!script.player.blocked && script.player.event==idle_events[i]);
        assert(script.audio.plays==3u+i && script.audio.mixer.voices[i+2u].pcm==script.audio.pcm[i+4u]);
        assert(script.audio.rate[i+2u]==(i==3?16075:15925));
    }
    /* Quiet68e30 uses the same121-tick immunity, without cry or blink. */
    script.player.hurt_callback=3;script.player.quiet_hurt_started=0;
    script.player.idle_started=(uint32_t)((uint64_t)script.updates*60u/24u);
    uint32_t quiet_sounds=script.audio.plays;
    uint8_t quiet_visible=object->visible;
    ll_level_script_update(&script);uint32_t quiet_started=script.player.quiet_hurt_started;
    assert(quiet_started && script.player.hurt_callback==3 && object->visible==quiet_visible && !(object->native_payload_flags&0x8000u));
    script.updates=(uint32_t)(((uint64_t)(quiet_started+120u)*24u+59u)/60u)-1u;
    ll_level_script_update(&script);assert(script.player.hurt_callback==3 && script.audio.plays==quiet_sounds);
    ll_level_script_update(&script);assert(!script.player.hurt_callback && !script.player.quiet_hurt_started);
    assert(object->visible==quiet_visible && script.audio.plays==quiet_sounds && !(object->native_payload_flags&0x8000u));
    object->wrapper_flags=3;script.player.idle_started=(uint32_t)((uint64_t)script.updates*60u/24u);
    uint32_t sounds=script.audio.plays;
    hit_player_with_targeted_ball(&script);
    assert(!script.player.blocked && script.native.native_word_44==2 && script.native.player_lives==5);
    assert(script.player.hurt_callback==1 && script.native.player_health_dirty && script.audio.plays==sounds);
    hit_player_with_targeted_ball(&script);
    assert(script.native.native_word_44==2 && script.player.hurt_callback==2 && script.audio.plays==sounds+1u);
    assert(script.audio.mixer.voices[sounds].pcm==script.audio.pcm[1]);
    assert(script.audio.rate[sounds]==15900 && script.audio.volume[sounds]==8191 && script.audio.pan[sounds]==1024);
    assert(!(object->native_payload_flags&0x8000u)); /* Pending69020 does not blink yet. */
    ll_level_script_update(&script);
    uint32_t hurt_started=script.player.hurt_started;
    assert(hurt_started && (object->native_payload_flags&0x8000u));
    assert(object->visible==((((uint32_t)((uint64_t)script.updates*60u/24u))&8u)!=0));
    script.updates=(uint32_t)(((uint64_t)(hurt_started+120u)*24u+59u)/60u)-1u;
    hit_player_with_targeted_ball(&script);
    assert(script.native.native_word_44==2 && script.player.hurt_callback==2);
    hit_player_with_targeted_ball(&script);
    assert(script.native.native_word_44==1 && script.player.hurt_callback==1 && object->visible);
    assert(!(object->native_payload_flags&0x8000u)); /* Expiry precedes the next pool update. */
    script.updates+=50;ll_level_script_update(&script); /* Pending hurt sound first. */
    ll_level_script_update(&script);script.updates+=50;ll_level_script_update(&script);
    assert(!script.player.hurt_callback);
    script.native.player_invincible=1;script.native.player_health_dirty=0;
    hit_player_with_targeted_ball(&script);
    assert(script.native.native_word_44==1 && !script.native.player_health_dirty && script.player.hurt_callback==1);
    ll_level_script_update(&script);ll_level_script_update(&script);script.updates+=50;ll_level_script_update(&script);
    script.native.player_invincible=0;
    hit_player_with_targeted_ball(&script);assert(script.native.native_word_44==0 && script.native.player_lives==5);
    ll_level_script_update(&script);ll_level_script_update(&script);script.updates+=50;ll_level_script_update(&script);
    hit_player_with_targeted_ball(&script);
    assert(script.native.native_word_44==3 && script.native.player_lives==4 && (script.native.native_flags&1u));
    assert(object->native_payload_flags&0x100u);
    ll_level_script_update(&script);
    assert(!script.player.blocked && script.native.player_lives==4);
    /* A path death sets the payload flag without consuming health first.
     * 469ef0 accounts for it once, irrespective of the effects preference. */
    script.native.native_flags=0;script.audio.effects_enabled=0;
    sounds=script.audio.plays;
    ll_level_script_update(&script);
    assert(!script.player.blocked && script.native.player_lives==3 && script.audio.plays==sounds+1u);
    assert(script.audio.mixer.voices[sounds].pcm==script.audio.pcm[2] && script.audio.rate[sounds]==15550);
    ll_level_script_update(&script);assert(script.native.player_lives==3 && script.audio.plays==sounds+1u);
    /* 469ef0/469dd0: automatic walk is a distinct pair of callbacks.
     * Its entry preserves bounds/speed and its exit suppresses one frame of input. */
    script.native.native_flags=0;script.player.hurt_callback=0;
    script.player.hurt_started=script.player.quiet_hurt_started=0;
    script.player.mode=1;script.player.speed=0;script.player.yaw=1024;script.player.fall_sound_ticks=9;
    object->native_payload_flags=0x40060;object->visible=1;object->bounds[0]=-777;
    object->path.segment=0;object->path.yaw=1024;object->path.pitch=0;object->path.flags=0;
    object->path.distance=object->path.previous_distance=5000;
    object->pose->position[0]=5000;object->pose->position[1]=object->pose->position[2]=0;
    memcpy(object->path.previous_position,object->pose->position,sizeof(object->path.previous_position));
    int32_t auto_angles[3]={0,1024,0};int16_t auto_rotation[3][3];
    ll_native_model_rotation(auto_angles,auto_rotation);memcpy(object->root_rotation,auto_rotation,sizeof(auto_rotation));
    dword(path+8,1);unsigned auto_shots=script.projectiles.shots_fired;
    ll_level_script_set_input(&script,0xe020);ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.mode==11 && script.player.event==4 &&
        script.player.speed==20 && script.player.displacement==30 && object->pose->position[0]==5030);
    assert(object->bounds[0]==-777 && !(object->native_payload_flags&0x40) && script.player.fall_sound_ticks==9);
    object->native_payload_flags|=0x200;ll_level_script_set_input(&script,0x80);ll_level_script_update(&script);
    assert(script.player.mode==11 && script.player.actions==0x80 && script.player.yaw==1024 && object->pose->position[0]==5076);
    dword(path+8,0);ll_level_script_set_input(&script,0xa080);ll_level_script_update(&script);
    assert(script.player.mode==1 && !script.player.actions && !script.player.pressed_actions &&
        !script.player.speed && script.player.displacement==10 && object->pose->position[0]==5086);
    assert(object->bounds[0]==script.player.base_bounds[0] && !script.player.fall_sound_ticks && script.projectiles.shots_fired==auto_shots);
    object->native_payload_flags&=~0x200u;ll_level_script_set_input(&script,0x80);ll_level_script_update(&script);
    assert(script.player.mode==2 && script.player.yaw==3072 && object->pose->position[0]<5086);
    /* Automatic run keeps the incoming heading; its exit defers idle until
     * the next frame while retaining run acceleration this frame. */
    script.player.mode=1;script.player.speed=0;script.player.yaw=1024;
    object->native_payload_flags=0x40020;object->pose->position[0]=5000;
    memcpy(object->path.previous_position,object->pose->position,sizeof(object->path.previous_position));
    memcpy(object->root_rotation,auto_rotation,sizeof(auto_rotation));dword(path+8,2);
    ll_level_script_set_input(&script,0);ll_level_script_update(&script);
    assert(script.player.mode==12 && script.player.event==5 && script.player.speed==20 && script.player.displacement==30);
    uint32_t auto_started=object->animation_started;
    for (unsigned i=0;i<4;i++) ll_level_script_update(&script);
    object->native_payload_flags|=0x200;ll_level_script_set_input(&script,0xe080);ll_level_script_update(&script);
    assert(script.player.mode==12 && script.player.actions==0xe080 && script.player.speed==66 &&
        object->animation_started==auto_started && script.player.yaw==1024);
    object->native_payload_flags&=~0x20u;object->pose->position[1]=-100;
    ll_level_script_update(&script);assert(script.player.mode==12 && object->pose->position[1]==-100);
    object->native_payload_flags|=0x20u;object->pose->position[1]=object->path.previous_position[1]=0;
    dword(path+8,0);ll_level_script_set_input(&script,0xa080);ll_level_script_update(&script);
    assert(script.player.mode==13 && script.player.event==5 && script.player.actions==0xa080 &&
        script.player.speed==66 && script.player.displacement==132 && script.projectiles.shots_fired==auto_shots);
    ll_level_script_set_input(&script,0);ll_level_script_update(&script);
    assert(script.player.mode==1 && script.player.event==0 && script.player.speed==40 && script.player.displacement==93);
    /* Type1 replaces an active hurt callback with68d80. Its blink timer
     * must remain independent of the retained quiet-immunity timer. */
    dword(path+8,1);script.player.hurt_callback=3;script.player.hurt_started=0;
    script.player.quiet_hurt_started=123;object->native_payload_flags=0x40060;
    ll_level_script_update(&script);
    assert(script.player.mode==11 && script.player.hurt_callback==2 && script.player.hurt_started &&
        script.player.quiet_hurt_started==123 && (object->native_payload_flags&0x8000u));
    assert(!script.player.blocked && !script.blocked_count);
    /* BA8 is an empty main controller, retaining horizontal motion and pose.
     * Its first argument deliberately names an absent instance65535. */
    script.player.precontrol_mode=0;script.player.mode=2;script.player.hurt_callback=0;
    script.player.speed=23;script.player.yaw=1024;script.player.fall_sound_ticks=17;
    object->native_payload_flags=0x40020;object->visible=1;object->bounds[0]=-777;
    object->pose->position[0]=5000;object->pose->position[1]=object->pose->position[2]=0;
    memcpy(object->path.previous_position,object->pose->position,sizeof(object->path.previous_position));
    dword(path+8,0);unsigned retained_event=script.player.event,retained_selector=object->animation_selector;
    unsigned retained_start=object->animation_started;
    queue_test_controller(&script,8);ll_level_script_set_input(&script,0xe080);ll_level_script_update(&script);
    assert(!script.blocked_count && script.player.mode==14 && script.player.suspended_motion==2);
    assert(script.player.speed==23 && script.player.displacement==46 && object->pose->position[0]==5046);
    assert(script.player.yaw==1024 && object->pose->position[1]==0 && object->bounds[0]==-777);
    assert(script.player.event==retained_event && object->animation_selector==retained_selector &&
        object->animation_started==retained_start && script.player.fall_sound_ticks==17);
    queue_test_controller(&script,8);ll_level_script_update(&script);
    assert(script.player.suspended_motion==2 && object->pose->position[0]==5092);
    queue_test_controller(&script,0);ll_level_script_set_input(&script,0);ll_level_script_update(&script);
    assert(script.player.mode==1 && !script.player.speed && script.player.displacement==10 &&
        !script.player.fall_sound_ticks && object->bounds[0]==script.player.base_bounds[0]);
    /* BA15 trap bounce preserves jump release, resets the fall counter and
     * begins WORD4bddf8=-125 immediately, with decelerating air control. */
    script.player.fall_sound_ticks=17;object->bounds[0]=-777;
    object->native_payload_flags=0x40020;queue_test_controller(&script,15);ll_level_script_update(&script);
    assert(script.player.mode==4 && script.player.event==15 && script.player.vertical_speed==-113 &&
        script.player.vertical_displacement==-232 && object->pose->position[1]==-232);
    assert(!script.player.fall_sound_ticks && !script.player.air_motion && !script.player.speed &&
        (object->native_payload_flags&0x40000u) && !(object->native_payload_flags&0x20u));
    assert(object->bounds[0]==-777);
    for (unsigned i=0;i<50;i++) ll_level_script_update(&script);
    assert(!script.player.blocked && script.player.mode==1 && object->pose->position[1]==0);
    /* BA3 is the separate67830 entry: clears release, keeps fall count,
     * and uses the walking air callback for this first motion tick. */
    script.player.fall_sound_ticks=17;object->native_payload_flags=0x40020;
    queue_test_controller(&script,3);ll_level_script_update(&script);
    assert(script.player.mode==4 && script.player.vertical_speed==-143 &&
        script.player.vertical_displacement==-292 && object->pose->position[1]==-292);
    assert(!(object->native_payload_flags&0x40000u) && script.player.fall_sound_ticks==17 &&
        script.player.speed==20 && script.player.displacement==30 && !script.player.air_motion);
    for (unsigned i=0;i<50;i++) ll_level_script_update(&script);
    queue_test_controller(&script,1);ll_level_script_set_input(&script,0x20);ll_level_script_update(&script);
    assert(script.player.mode==2 && script.player.event==4);
    queue_test_controller(&script,2);ll_level_script_set_input(&script,0x4020);ll_level_script_update(&script);
    assert(script.player.mode==3 && script.player.event==5);
    /* Ordinary pre-control can replace BA before the main callback runs. */
    dword(path+8,1);object->native_payload_flags=0x40020;
    queue_test_controller(&script,15);ll_level_script_set_input(&script,0);ll_level_script_update(&script);
    assert(script.player.mode==11 && script.player.precontrol_mode==1 && object->pose->position[1]==0);
    queue_test_controller(&script,8);ll_level_script_update(&script);
    assert(script.player.mode==14 && script.player.precontrol_mode==1 && script.player.suspended_motion==11);
    dword(path+8,0);queue_test_controller(&script,15);ll_level_script_update(&script);
    assert(script.player.mode==1 && !script.player.precontrol_mode && object->pose->position[1]==0);
    dword(path+8,2);ll_level_script_update(&script);
    assert(script.player.mode==12 && script.player.precontrol_mode==2);
    queue_test_controller(&script,8);ll_level_script_update(&script);
    dword(path+8,0);ll_level_script_update(&script);
    assert(script.player.mode==14 && script.player.precontrol_mode==2 && script.player.suspended_motion==12);
    /* Undefined switch values leave even a pending entry unchanged. */
    queue_test_controller(&script,65535);ll_level_script_update(&script);
    assert(script.player.mode==14 && script.player.precontrol_mode==2 && !script.blocked_count);
    queue_test_controller(&script,12);ll_level_script_update(&script);
    assert(script.blocked_count==1 && strstr(script.contexts[0].error,"BA controller") && !script.player.blocked);
    ll_level_script_close(&script);fclose(trace);
}

static void run_tests(void)
{
    unsigned char data[1024];
    /* Immutable native path: variable-size records and relative links.
     * A reference inside a record must not be accepted as a segment. */
    unsigned char path_data[104]={0};
    word(path_data+2,2);dword(path_data+4,48);
    for (unsigned i=0;i<2;i++) {
        unsigned char *record=path_data+8+24*i;
        dword(record+8,12);dword(record+12,100);dword(record+16,1);
        dword(record+20,i?0:24);
    }
    dword(path_data+68,100);
    LL_BibSelector path_section={0,0,sizeof(path_data),1};
    LL_BibFile path_bib={0};
    path_bib.valid=1;path_bib.raw_data=path_data;path_bib.raw_size=sizeof(path_data);
    path_bib.selector_count=1;path_bib.sections=&path_section;
    unsigned target_index=99;
    assert(ll_bib_get_path_link(&path_bib,0,0,0,&target_index) && target_index==1);
    assert(ll_bib_get_path_link(&path_bib,0,1,0,&target_index) && target_index==0);
    LL_BibPathSegment first_segment,second_segment;
    assert(ll_bib_get_path_segment(&path_bib,0,0,&first_segment));
    assert(ll_bib_get_path_segment(&path_bib,0,1,&second_segment));
    assert(first_segment.table_offset==0 && second_segment.table_offset==24);
    assert(first_segment.start_reference==0 && first_segment.end_reference==12);
    assert(second_segment.start_reference==first_segment.start_reference);
    /* FUN_00457570 keeps the first segment on equal squared distances.
     * FUN_00457740 preserves player Y, and falls back to segment start
     * when projection lies outside its signed16 distance interval. */
    int32_t initial_position[3]={50,42,0};
    unsigned selected_index=99;
    assert(ll_bib_select_path_segment(&path_bib,0,initial_position,&selected_index));
    assert(selected_index==0);
    LL_BibPathAnchor anchor;
    assert(ll_bib_prepare_path_anchor(&path_bib,0,initial_position,&anchor));
    assert(anchor.segment_index==0 && anchor.distance==50);
    assert(anchor.position[0]==50 && anchor.position[1]==42 && anchor.position[2]==0);
    initial_position[0]=150;
    assert(ll_bib_prepare_path_anchor(&path_bib,0,initial_position,&anchor));
    assert(anchor.segment_index==0 && anchor.distance==0);
    assert(anchor.position[0]==0 && anchor.position[1]==42 && anchor.position[2]==0);
    unsigned next_segment=99;
    assert(ll_level_path_next_segment(&path_bib,0,0,initial_position,3072,&next_segment)==2);
    assert(next_segment==1);
    initial_position[0]=50;
    assert(ll_level_path_next_segment(&path_bib,0,0,initial_position,3072,&next_segment)==1);
    assert(next_segment==0);
    /* A separate linked segment below the player is a floor candidate.
     * Shared endpoint identity would exclude it even at matching positions. */
    dword(path_data+36,24);dword(path_data+40,36);
    dword(path_data+84,100);dword(path_data+92,100);dword(path_data+96,100);
    assert(ll_level_path_floor_segment(&path_bib,0,0,initial_position,&next_segment)==1);
    assert(next_segment==1);
    initial_position[1]=100;next_segment=99;
    assert(ll_level_path_floor_segment(&path_bib,0,0,initial_position,&next_segment)==0);
    assert(next_segment==99);
    initial_position[1]=42;
    LL_LevelPathStep path_step;
    assert(ll_level_path_update(&path_bib,0,0,initial_position,initial_position,
        1024,0x40,0,0,&path_step));
    assert(path_step.segment==0 && !path_step.orientation_reset);
    assert(path_step.constraint.distance==50 && path_step.constraint.position[0]==50);
    assert(path_step.constraint.position[1]==0 && path_step.constraint.payload_flags==0x60);
    LL_BibPathSegment obstacle={0},current_path={0};
    current_path.start_reference=0;current_path.end_reference=12;current_path.start[1]=100;
    obstacle.start_reference=24;obstacle.end_reference=36;
    obstacle.end[0]=100;obstacle.length=100;
    int32_t contact_position[3]={50,-10,0},previous_position[3]={50,100,0};
    int32_t corrected[3]={123,456,789};
    assert(ll_level_path_obstacle(&current_path,&obstacle,contact_position,
        previous_position,corrected)==1);
    assert(corrected[0]==123 && corrected[1]==456);
    contact_position[1]=100;
    assert(ll_level_path_obstacle(&current_path,&obstacle,contact_position,
        previous_position,corrected)==2);
    assert(corrected[0]==50 && corrected[1]==1800);
    previous_position[0]=-10;
    assert(ll_level_path_obstacle(&current_path,&obstacle,contact_position,
        previous_position,corrected)==2);
    assert(corrected[0]==100 && corrected[1]==100);
    contact_position[1]=1800;
    assert(ll_level_path_obstacle(&current_path,&obstacle,contact_position,
        previous_position,corrected)==0);
    dword(path_data+28,25);target_index=99;
    assert(!ll_bib_get_path_link(&path_bib,0,0,0,&target_index) && target_index==99);
    dword(path_data+24,65537);
    LL_BibPathView invalid_view;
    assert(!ll_bib_get_path_view(&path_bib,0,&invalid_view));
    LL_BibPathSegment slope={0};
    slope.length=1000;slope.end[0]=1000;slope.end[1]=500;
    int32_t query[3]={500,999,100},projected[3],distance;
    assert(ll_bib_project_path_segment(&slope,query,projected,&distance));
    assert(distance==500 && projected[0]==500 && projected[1]==250 && projected[2]==0);
    query[0]=-1;
    assert(ll_bib_project_path_segment(&slope,query,projected,&distance));
    assert(distance==-1 && projected[0]==-1 && projected[1]==-1);
    LL_LevelPathConstraint constrained;
    query[0]=500;query[1]=300;
    assert(ll_level_path_constrain(&slope,query,0x40,0,0,&constrained));
    assert(constrained.position[1]==250 && constrained.payload_flags==0x60);
    slope.flags=4;
    assert(ll_level_path_constrain(&slope,query,0,0,0,&constrained));
    assert(constrained.position[1]==300 && constrained.payload_flags==0x100 &&
        constrained.path_flags==1);
    assert(ll_level_path_constrain(&slope,query,0,0,1,&constrained));
    assert(constrained.position[1]==250 && constrained.path_flags==0);
    slope.length=0;projected[0]=123;distance=456;
    assert(!ll_bib_project_path_segment(&slope,query,projected,&distance));
    assert(projected[0]==123 && distance==456);
    const unsigned char end[]={0};
    /* Store member1 byte20 before its first execution. Then suspend with a
     * live operand. A condition stream must not consume that operand or PC. */
    const unsigned char body[]={5,0x34,0x12,5,1,0,5,20,0,0x29,0x3b,
        5,0x78,0x56,0x32,0x3b,5,7,0,5,0x58,0,0x3d,0};
    const unsigned char other[]={7,20,0,5,0x58,0,0x3d,0};
    const unsigned char conditions[]={5,9,0,5,0xa1,0,0x3d,1};
    size_t size=fixture(data,body,sizeof(body),other,sizeof(other),conditions,sizeof(conditions));
    FILE *trace=tmpfile();assert(trace);
    LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    assert(script.program.functions[0].code_end==24+sizeof(body));
    assert(script.program.functions[0].size==24+sizeof(body)+sizeof(conditions)+4);
    /* Runtime owns copies, including parser data. */
    data[0]='X';assert(script.program.data[0]=='S');
    ll_level_script_update(&script);
    assert(script.contexts[0].vm.suspended && script.contexts[0].vm.stack_size==1);
    assert(script.contexts[0].vm.stack[0]==0x5678);
    assert(script.contexts[1].vm.locals[20]==0x1234);
    assert(script.native.player_word==0x1234 && script.native.object_mode==9);
    ll_level_script_update(&script);
    assert(script.contexts[0].body_done && script.contexts[0].vm.stack_size==0);
    assert(script.native.player_word==7 && script.blocked_count==0);
    ll_level_script_close(&script);

    ll_native_rng_reset();
    assert(ll_native_rng_word()==22539 && ll_native_rng_word()==1810 &&
           ll_native_rng_word()==27890);
    ll_native_rng_reset();
    const unsigned char bounded_random[]={5,100,0,5,0x0b,0,0x51,
        5,0x58,0,0x3d,0};
    size=fixture(data,bounded_random,sizeof(bounded_random),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);
    assert(script.native.player_word==39 && script.supported_calls==2 && !script.blocked_count);
    ll_level_script_close(&script);

    /* Variable host calls replace their identifier/arguments with the native
     * return word. FUN_0040bdc0 observes the command-controlled global flag. */
    const unsigned char variable_flags[]={
        5,0x38,0,0x50,5,0x58,0,0x3d,
        5,0,0,5,0x5b,0,0x3d,
        5,0x38,0,0x50,5,0x58,0,0x3d,0
    };
    size=fixture(data,variable_flags,sizeof(variable_flags),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);
    assert(script.native.player_word==1 && script.supported_calls==5 && !script.blocked_count);
    assert(script.native.native_flags==5);
    ll_level_script_close(&script);

    /* Quarantine unknown command, preserving stack and exact fault offset;
     * do not execute the following setter, retry, or stop unrelated contexts. */
    const unsigned char unknown[]={5,0x34,0x12,0x3c,5,2,0,5,0x58,0,0x3d,0};
    const unsigned char setter[]={5,42,0,5,0x58,0,0x3d,0};
    size=fixture(data,unknown,sizeof(unknown),setter,sizeof(setter),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);
    assert(script.blocked_count==1 && script.contexts[0].blocked);
    assert(script.contexts[0].vm.stack_size==1 && script.contexts[0].vm.stack[0]==0x1234);
    assert(script.contexts[0].vm.last_instruction_offset==27);
    assert(script.native.player_word==42);
    uint32_t calls=script.calls;
    for (unsigned i=0;i<100;i++) ll_level_script_update(&script);
    assert(script.calls==calls && script.blocked_count==1);
    ll_level_script_close(&script);

    /* Native unsigned clamp after sign extension: -1 ->200, 0 ->10. */
    const unsigned char clamp[]={5,0xff,0xff,5,0x3e,1,0x3d,0};
    size=fixture(data,clamp,sizeof(clamp),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);assert(script.native.camera_limit==200);
    ll_level_script_close(&script);
    data[26+25]=data[26+26]=0;
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);assert(script.native.camera_limit==10);
    ll_level_script_close(&script);

    /* A remote state request must not restart another body in the same tick.
     * It becomes visible before bodies on the next update. */
    const unsigned char remote[]={5,1,0,5,1,0,0x38,0};
    const unsigned char two_states[]={0,5,42,0,5,0x58,0,0x3d,0};
    size=fixture(data,remote,sizeof(remote),two_states,sizeof(two_states),NULL,0);
    size_t second=data[14]|((size_t)data[15]<<8);
    word(data+second,20);word(data+second+14,2);word(data+second+18,25);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.contexts[1].body_done=1;
    ll_level_script_update(&script);assert(script.native.player_word==0);
    ll_level_script_update(&script);assert(script.native.player_word==42);
    ll_level_script_close(&script);

    const unsigned char self_transition[]={5,1,0,0x37,5,99,0,5,0x58,0,0x3d,0,
        5,42,0,5,0x58,0,0x3d,0};
    size=fixture(data,self_transition,sizeof(self_transition),end,sizeof(end),NULL,0);
    word(data+26,20);word(data+26+14,2);word(data+26+18,36);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);assert(script.native.player_word==0);
    assert(script.contexts[0].vm.suspended && script.contexts[0].vm.resume_pc==26+28);
    ll_level_script_update(&script);assert(script.native.player_word==42);
    ll_level_script_close(&script);

    /* Separate condition branches may jump beyond state code_end. Compare
     * the current state, skip the disabled arm, terminate at opcode1. */
    const unsigned char branch[]={0x0e,0,0,0,0,5,1,0,5,1,0,0x0f,1};
    size=fixture(data,end,sizeof(end),end,sizeof(end),branch,sizeof(branch));
    word(data+26+24+sizeof(end)+3,24+sizeof(end)+sizeof(branch)-1);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    ll_level_script_update(&script);assert(!script.blocked_count);
    assert(!script.contexts[0].vm.has_pending_transition);
    ll_level_script_close(&script);

    /* initial_state ffff finishes the body (native flag2), not the whole
     * context (flag1). Its conditions can request the first ordinary state. */
    const unsigned char activate[]={5,0,0,5,1,0,0x0f,1};
    size=fixture(data,setter,sizeof(setter),end,sizeof(end),activate,sizeof(activate));
    word(data+26+10,UINT16_MAX);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    assert(!(script.contexts[0].vm.state_flags&1u));
    ll_level_script_update(&script);assert(script.native.player_word==0);
    assert(script.contexts[0].vm.has_pending_transition);
    ll_level_script_update(&script);assert(script.native.player_word==42);
    ll_level_script_close(&script);

    /* Cross-function and trailing-table bounds: valid code does not justify
     * reading into the next function or accepting a truncated virtual pair. */
    LL_SoolProgram program={0};
    assert(ll_sool_program_open(&program,data,size));ll_sool_program_close(&program);
    word(data+26+4,1023);
    assert(!ll_sool_program_open(&program,data,size));ll_sool_program_close(&program);
    size=fixture(data,end,sizeof(end),end,sizeof(end),branch,sizeof(branch));
    word(data+26+8,24); /* conditions cannot overlap state code */
    assert(!ll_sool_program_open(&program,data,size));ll_sool_program_close(&program);
    size=fixture(data,end,sizeof(end),end,sizeof(end),NULL,0);
    word(data+26+12,1023); /* state code cannot cross into next function */
    assert(!ll_sool_program_open(&program,data,size));ll_sool_program_close(&program);
    size=fixture(data,end,sizeof(end),end,sizeof(end),NULL,0);
    dword(data+4,(unsigned)size-1);
    assert(!ll_sool_program_open(&program,data,size-1));ll_sool_program_close(&program);
    /* FUN_00408f40 returns a strict interval predicate, not either bound.
     * Instance150 deliberately exceeds the two-function context directory. */
    const unsigned char interval[]={5,150,0,5,20,0,5,10,0,5,0x0e,0,0x53,
        5,0x58,0,0x3d,0};
    const int32_t positions[]={999,1000,1001,1999,2000,2001};
    const unsigned expected[]={0,0,1,1,0,0};
    for (unsigned i=0;i<sizeof(positions)/sizeof(positions[0]);i++) {
        size=fixture(data,interval,sizeof(interval),end,sizeof(end),NULL,0);
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        LL_LevelScriptObject *target=&script.objects[150];
        target->present=1;target->kind=1;target->pose=&target->private_pose;
        target->pose->position[0]=positions[i];
        ll_level_script_update(&script);
        assert(!script.blocked_count);
        assert(script.contexts[0].body_done);
        assert(script.native.player_word==expected[i]);
        ll_level_script_close(&script);
    }
    /* FUN_00408cc0 uses signed idiv100, then returns AX. Negative
     * coordinates must truncate toward zero rather than round downward. */
    const unsigned char coordinate[]={5,150,0,5,0x0c,0,0x51,5,0x58,0,0x3d,0};
    const int32_t signed_x[]={-101,-100,-99,-1,0,99,100,101};
    const int16_t quotients[]={-1,-1,0,0,0,0,1,1};
    for (unsigned i=0;i<sizeof(signed_x)/sizeof(signed_x[0]);i++) {
        size=fixture(data,coordinate,sizeof(coordinate),end,sizeof(end),NULL,0);
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        LL_LevelScriptObject *target=&script.objects[150];
        target->present=1;target->kind=1;target->pose=&target->private_pose;
        target->pose->position[0]=signed_x[i];
        ll_level_script_update(&script);
        assert(!script.blocked_count && script.contexts[0].body_done);
        assert(script.native.player_word==(uint16_t)quotients[i]);
        ll_level_script_close(&script);
    }
    /* Distance attenuation is an integer ramp including the range endpoint.
     * Resolve instance IDs directly even when no such SOOL context exists. */
    const unsigned char attenuation[]={5,0xe8,3,5,100,0,5,151,0,5,150,0,
        5,0x97,0,0x54,5,0x58,0,0x3d,0};
    const int32_t separations[]={0,5000,10000,10100};
    const uint16_t amplitudes[]={1000,500,0,0};
    for (unsigned i=0;i<4;i++) {
        size=fixture(data,attenuation,sizeof(attenuation),end,sizeof(end),NULL,0);
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        for (unsigned instance=150;instance<=151;instance++) {
            LL_LevelScriptObject *target=&script.objects[instance];
            target->present=1;target->kind=1;target->pose=&target->private_pose;
        }
        script.objects[151].pose->position[0]=separations[i];
        ll_level_script_update(&script);
        assert(!script.blocked_count && script.contexts[0].body_done);
        assert(script.native.player_word==amplitudes[i]);
        ll_level_script_close(&script);
    }
    /* Native96 has signed gain/scale and returns the unscaled peak outside
     * its radius, rather than the linear97 query's zero. */
    unsigned char scaled[]={5,0,1,5,0xf4,1,5,100,0,5,151,0,5,150,0,
        5,0x96,0,0x55,5,0x58,0,0x3d,0};
    const int16_t signed_amplitudes[2][4]={{500,250,0,500},{0,-250,-500,-500}};
    for (unsigned negative=0;negative<2;negative++) for (unsigned i=0;i<4;i++) {
        word(scaled+4,negative?(uint16_t)(int16_t)-500:500);
        size=fixture(data,scaled,sizeof(scaled),end,sizeof(end),NULL,0);
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        for (unsigned instance=150;instance<=151;instance++) {
            script.objects[instance].present=1;script.objects[instance].pose=&script.objects[instance].private_pose;
        }
        script.objects[151].pose->position[0]=separations[i];
        ll_level_script_update(&script);
        assert(!script.blocked_count && script.native.player_word==(uint16_t)signed_amplitudes[negative][i]);
        ll_level_script_close(&script);
    }
    /* Screen-root placement uses viewport scaling and signed16 storage,
     * not world-coordinate multiplication by100. Native SAR rounds -15
     * scaled by480/256 down to-29. Preserve the offscreen position. */
    const unsigned char screen_position[]={5,10,0,5,0xf1,0xff,5,0xb8,1,
        5,0x41,0,0x3f,0};
    size=fixture(data,screen_position,sizeof(screen_position),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.contexts[0].instance=150;
    script.objects[150].present=1;script.objects[150].kind=7;
    script.objects[150].pose=&script.objects[150].private_pose;
    ll_level_script_update(&script);
    assert(!script.blocked_count && script.contexts[0].body_done);
    assert(script.objects[150].pose->position[0]==550);
    assert(script.objects[150].pose->position[1]==-29);
    assert(script.objects[150].pose->position[2]==10);
    ll_level_script_close(&script);
    /* Execute e8 through SOOL, then verify its registered callback constrains
     * the root on the following tick instead of merely recording metadata. */
    dword(path_data+24,1);dword(path_data+28,24);
    const unsigned char attach_path[]={5,0,0,5,0xe8,0,0x3d,5,42,0,5,0x58,0,0x3d,0};
    size=fixture(data,attach_path,sizeof(attach_path),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.bib=path_bib;
    script.bib.sections=malloc(sizeof(path_section));assert(script.bib.sections);
    *script.bib.sections=path_section;
    script.bib.animations=calloc(1,sizeof(*script.bib.animations));assert(script.bib.animations);
    script.native.path_capacity=10;script.contexts[0].instance=150;
    LL_LevelScriptObject *path_object=&script.objects[150];
    path_object->present=1;path_object->kind=1;path_object->pose=&path_object->private_pose;
    path_object->root_rotation=path_object->private_root_rotation;
    path_object->pose->position[0]=50;path_object->pose->position[1]=42;
    ll_level_script_update(&script);
    assert(!script.blocked_count && script.native.player_word==42);
    assert(path_object->path.attached && script.native.path_count==1);
    assert(path_object->path.segment==0 && path_object->path.distance==50);
    assert(path_object->pose->position[1]==42);
    ll_level_script_update(&script);
    assert(!script.blocked_count && path_object->path.attached);
    assert(path_object->pose->position[0]==50 && path_object->pose->position[1]==0);
    assert(path_object->path.distance==50 && path_object->path.previous_distance==50);
    ll_level_script_close(&script);
    const unsigned char follow_setup[]={5,0xa8,0xe4,5,0,0,5,0,0,5,0,0,5,150,0,
        5,0x37,1,0x41,0};
    size=fixture(data,follow_setup,sizeof(follow_setup),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.objects[150].present=1;script.objects[150].kind=1;
    script.objects[150].pose=&script.objects[150].private_pose;
    script.native.camera_vertical_mode=1;
    script.objects[150].pose->position[0]=1000;
    script.objects[150].pose->position[1]=2000;
    script.objects[150].pose->position[2]=3000;
    ll_level_script_update(&script);
    assert(!script.blocked_count);
    assert(script.native.camera_follow_instance_plus_one==151);
    assert(script.native.camera_follow_distance==1 && script.native.camera_follow_height== -6000);
    assert(script.native.camera_follow_target[0]==1000 && script.native.camera_follow_target[1]== -4000);
    assert(script.native.camera_follow_reference[0]==1000 &&
        script.native.camera_follow_reference[1]== -4000 && script.native.camera_follow_reference[2]==2999);
    ll_level_script_close(&script);
    const unsigned char absolute_camera[]={5,0,0,5,0,0,5,3,0,5,0xec,0xff,5,20,0,
        5,0x36,1,0x41,0};
    size=fixture(data,absolute_camera,sizeof(absolute_camera),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.native.camera_bounds[0]= -1000;script.native.camera_bounds[1]=1000;
    script.native.camera_bounds[2]= -1000;script.native.camera_bounds[3]=1000;
    script.native.camera_follow_distance=1000;script.native.camera_lead_offset=300;
    script.native.camera_z_bounds[0]=-800000;script.native.camera_z_bounds[1]=800000;
    script.native.camera_follow_instance_plus_one=151;
    ll_level_script_update(&script);
    assert(!script.blocked_count && script.native.camera_reference_active);
    assert(script.native.camera_follow_instance_plus_one==0 && script.native.camera_lead_offset==0);
    assert(script.native.camera_follow_reference[0]==1000 &&
        script.native.camera_follow_reference[1]== -1000 && script.native.camera_follow_reference[2]==300);
    assert(script.native.camera_lookat[0]==1000 &&
        script.native.camera_lookat[1]== -1000 && script.native.camera_lookat[2]==1300);
    ll_level_script_close(&script);
    const unsigned char camera_transition[]={5,180,0,5,0,0,5,0xe8,3,5,0,0,5,0,0,
        5,150,0,5,0x5e,1,0x42,0};
    const unsigned char transition_query[]={5,150,0,5,0x46,0,0x51,5,0x58,0,0x3d,1};
    size=fixture(data,camera_transition,sizeof(camera_transition),end,sizeof(end),
        transition_query,sizeof(transition_query));
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.native.camera_mode=1;script.native.camera_vertical_mode=1;
    script.native.camera_follow_reference[0]=100;
    script.native.camera_follow_reference[1]=100;
    script.native.camera_follow_reference[2]= -1000;
    script.objects[150].present=1;script.objects[150].kind=1;
    script.objects[150].pose=&script.objects[150].private_pose;
    ll_level_script_update(&script);
    assert(!script.blocked_count && script.native.camera_transition_remaining==24);
    assert(!script.native.camera_transition_complete);
    assert(script.native.player_word==0);
    script.objects[150].pose->position[0]=100;
    ll_level_script_update(&script);
    assert(script.native.camera_transition_remaining==23);
    assert(script.native.camera_follow_reference[0]==192 && script.native.camera_follow_reference[1]==92);
    assert(script.native.camera_lookat[0]==100);
    for (unsigned i=0;i<23;i++) ll_level_script_update(&script);
    assert(!script.blocked_count && !script.native.camera_blocked && script.native.camera_transition_complete);
    assert(script.native.player_word==0); /* SOOL conditions run before the camera callback. */
    ll_level_script_update(&script);
    assert(script.native.player_word==1);
    assert(script.native.camera_transition_remaining==0);
    assert(script.native.camera_follow_reference[0]==100 && script.native.camera_follow_reference[1]==0);
    assert(script.native.camera_follow_reference[2]== -1000 && script.native.camera_lookat[0]==100);
    ll_level_script_close(&script);
    const int16_t pitch_inputs[]={68,32767,-32768,32767};
    const int16_t pitch_outputs[]={68,800,-800,123};
    for (unsigned i=0;i<4;i++) {
        unsigned char pitch_setter[]={5,0,0,5,0x39,1,0x3d,0};
        word(pitch_setter+1,(uint16_t)pitch_inputs[i]);
        size=fixture(data,pitch_setter,sizeof(pitch_setter),end,sizeof(end),NULL,0);
        assert(ll_level_script_open(&script,data,size,NULL,0,trace));
        script.native.camera_follow_pitch=123;
        script.native.camera_lock=(uint8_t)(i==3);
        ll_level_script_update(&script);
        assert(!script.blocked_count && script.contexts[0].body_done);
        assert(script.native.camera_follow_pitch==pitch_outputs[i]);
        ll_level_script_close(&script);
    }
    /* Keep interpolation within the selected range, including loop wrap
     * and a final once-only frame held while its owner resumes. */
    size=fixture(data,end,sizeof(end),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.bib.valid=1;script.bib.raw_data=data;script.bib.raw_size=size;
    script.bib.selector_count=1;
    script.bib.animations=calloc(1,sizeof(*script.bib.animations));assert(script.bib.animations);
    LL_BibAnimationTable *table=script.bib.animations;
    table->record_count=5;table->record_type=1;
    table->records=calloc(5,sizeof(*table->records));assert(table->records);
    for (unsigned i=0;i<5;i++) table->records[i].sample_count=10;
    LL_LevelScriptObject *animated=&script.objects[150];
    animated->present=1;animated->animation_active=1;
    animated->animation_first=2;animated->animation_last=3;
    ll_level_script_update(&script); /* native clock62 of a320-unit frame */
    assert(animated->animation_frame==2 && animated->animation_next_frame==3);
    assert(animated->animation_fraction==62u*65536u/320u);
    script.updates=4;
    ll_level_script_update(&script); /* clock372, frame3, next wraps to2 */
    assert(animated->animation_frame==3 && animated->animation_next_frame==2);
    assert(animated->animation_fraction==52u*65536u/320u);
    script.updates=8;
    ll_level_script_update(&script); /* clock682 wraps to frame2 */
    assert(animated->animation_frame==2 && animated->animation_next_frame==3);
    assert(animated->animation_fraction==42u*65536u/320u);
    animated->animation_once=1;script.updates=4;
    ll_level_script_update(&script);
    assert(animated->animation_frame==3 && animated->animation_next_frame==3);
    assert(animated->animation_fraction==0);
    script.updates=20;
    ll_level_script_update(&script);
    assert(animated->animation_frame==3 && animated->animation_fraction==0);
    ll_level_script_close(&script);
    const unsigned char stop_animation[]={5,0,0,5,0x15,0,0x3d,0};
    size=fixture(data,stop_animation,sizeof(stop_animation),end,sizeof(end),NULL,0);
    assert(ll_level_script_open(&script,data,size,NULL,0,trace));
    script.contexts[0].instance=150;
    animated=&script.objects[150];
    animated->present=1;animated->animation_pose_present=1;
    animated->animation_active=1;animated->animation_first=2;animated->animation_last=3;
    animated->animation_selector=120;animated->animation_frame=3;animated->animation_fraction=42;
    ll_level_script_update(&script);
    assert(!script.blocked_count && !animated->animation_active && animated->animation_pose_present);
    assert(animated->animation_frame==3 && animated->animation_fraction==42);
    ll_level_script_close(&script);
    fclose(trace);
}

static unsigned char *read_asset(const char *path, size_t *size)
{
    FILE *file=fopen(path,"rb");assert(file);
    assert(!fseek(file,0,SEEK_END));long length=ftell(file);
    assert(length>0 && length<=64*1024*1024 && !fseek(file,0,SEEK_SET));
    unsigned char *data=malloc((size_t)length);assert(data);
    assert(fread(data,1,(size_t)length,file)==(size_t)length);
    fclose(file);*size=(size_t)length;return data;
}

static void attach_original_pause(LL_LevelScript *script, const char *path)
{
    if (!path) return;
    size_t size;unsigned char *data=read_asset(path,&size);
    assert(ll_level_script_set_pause_archive(script,data,size));free(data);
}

static void test_original_sprite_geometry(char **paths)
{
    size_t bib_size,biz_size;
    unsigned char *bib=read_asset(paths[1],&bib_size),*biz=read_asset(paths[2],&biz_size);
    const unsigned char body[]={5,24,0,5,96,0,5,150,0,5,0x6e,0,0x3f,
        5,0,0,5,96,0,5,0x42,0,0x3e,0},end[]={0};
    unsigned char data[1024];size_t size=fixture(data,body,sizeof(body),end,sizeof(end),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,bib,bib_size,trace));
    assert(ll_level_script_set_biz(&script,biz,biz_size));ll_level_script_update(&script);
    static const int32_t expected[6]={-210,-384,-384,210,312,744};
    assert(!script.blocked_count && !memcmp(script.objects[150].bounds,expected,sizeof(expected)));
    assert(script.objects[150].sprite_frame==0 && !script.objects[150].sprite_animation_active);
    ll_level_script_close(&script);fclose(trace);free(bib);free(biz);
}

static void pause_original_dynamite(LL_LevelScript *script)
{
    ll_level_script_set_system_input(script,LL_PAUSE_KEY);ll_level_script_update(script);
    ll_level_script_set_system_input(script,0);ll_level_script_update(script);assert(script->pause.paused);
    LL_LevelPlayer player=script->player;LL_LevelNativeSetup native=script->native;
    LL_LevelScriptObject objects[3]={script->objects[4],script->objects[5],script->objects[6]};
    LL_LevelScriptObject gate=script->objects[52];
    size_t bytes=script->program.function_count*sizeof(*script->contexts);
    void *contexts=malloc(bytes);assert(contexts);memcpy(contexts,script->contexts,bytes);
    unsigned updates=script->updates;
    for (unsigned i=0;i<8;i++) ll_level_script_update(script);
    assert(script->updates==updates && !memcmp(&script->player,&player,sizeof(player)));
    assert(!memcmp(&script->native,&native,sizeof(native)) && !memcmp(script->contexts,contexts,bytes));
    for (unsigned i=0;i<3;i++) assert(!memcmp(&script->objects[4+i],&objects[i],sizeof(objects[i])));
    assert(!memcmp(&script->objects[52],&gate,sizeof(gate)));
    free(contexts);
    ll_level_script_set_system_input(script,LL_PAUSE_KEY);ll_level_script_update(script);
    ll_level_script_set_system_input(script,0);ll_level_script_update(script);assert(!script->pause.paused);
}

static void test_original_crouch_dynamite(char **paths, const char *pause_path)
{
    size_t code_size,bib_size,biz_size;
    unsigned char *code=read_asset(paths[0],&code_size),*bib=read_asset(paths[1],&bib_size);
    unsigned char *biz=read_asset(paths[2],&biz_size);FILE *trace=tmpfile();assert(trace);
    for (unsigned replay=0;replay<4;replay++) {
        LL_LevelScript script={0};assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
        assert(ll_level_script_set_biz(&script,biz,biz_size));attach_original_pause(&script,pause_path);
        for (unsigned i=0;i<120;i++) ll_level_script_update(&script);
        LL_LevelScriptObject *player=&script.objects[4];unsigned blocked=script.blocked_count;
        if (!replay) {
            int32_t start[3];memcpy(start,player->pose->position,sizeof(start));
            ll_level_script_set_input(&script,0x1000);ll_level_script_update(&script);
            assert(script.player.mode==1 && !script.native.level_event_latch && !script.native.player_dynamite);
            ll_level_script_set_input(&script,0x40);ll_level_script_update(&script);
            assert(script.player.mode==15 && script.player.event==19 && player->animation_selector==212);
            assert(player->bounds[1]==script.player.base_bounds[1]+800);
            for (unsigned i=0;i<20;i++) ll_level_script_update(&script);
            assert(script.player.mode==17 && script.player.event==20 && player->animation_selector==213);
            ll_level_script_set_input(&script,0xc0);ll_level_script_update(&script);
            assert(script.player.mode==17 && script.player.yaw==3072 && !script.player.speed);
            assert(!memcmp(start,player->pose->position,sizeof(start)));
            if (pause_path) pause_original_dynamite(&script);
            ll_level_script_set_input(&script,0x80);ll_level_script_update(&script);
            assert(script.player.mode==2 && script.player.event==4 && player->pose->position[0]<start[0]);
            assert(!memcmp(player->bounds,script.player.base_bounds,sizeof(script.player.base_bounds)));
            ll_level_script_set_input(&script,0);
            for (unsigned i=0;i<3;i++) ll_level_script_update(&script);
            ll_level_script_set_input(&script,0xc0);ll_level_script_update(&script);
            assert(script.player.mode==2 && player->bounds[1]==script.player.base_bounds[1]);
            ll_level_script_set_input(&script,0);
            for (unsigned i=0;i<3;i++) ll_level_script_update(&script);
            ll_level_script_set_input(&script,0x40);ll_level_script_update(&script);
            ll_level_script_set_input(&script,0);ll_level_script_update(&script);
            assert(script.player.mode==15); /* Releasing Down does not cut off the descending animation. */
            unsigned saw_rise=0;
            for (unsigned i=0;i<30;i++) { ll_level_script_update(&script);saw_rise|=script.player.event==21; }
            assert(saw_rise && script.player.mode==1 && !script.player.blocked && script.blocked_count==blocked);
            ll_level_script_set_input(&script,0x40);
            for (unsigned i=0;i<20;i++) ll_level_script_update(&script);
            assert(script.player.mode==17);
            ll_level_script_set_input(&script,0x8040);ll_level_script_update(&script);
            assert(script.player.mode==4 && script.player.vertical_speed==-113 && player->pose->position[1]<0);
            assert(!memcmp(player->bounds,script.player.base_bounds,sizeof(script.player.base_bounds)));
            ll_level_script_set_input(&script,0);
            for (unsigned i=0;i<50;i++) ll_level_script_update(&script);
            script.native.player_dynamite=-1;
            ll_level_script_set_input(&script,0x1000);ll_level_script_update(&script);
            assert(script.native.player_dynamite==-1 && !script.native.level_event_latch);
            ll_level_script_set_input(&script,0);ll_level_script_update(&script);
            script.native.player_dynamite=1;player->native_payload_flags|=8u;
            ll_level_script_set_input(&script,0x1000);ll_level_script_update(&script);
            assert(script.native.player_dynamite==1 && !script.native.level_event_latch);
            ll_level_script_set_input(&script,0);ll_level_script_update(&script);
            player->native_payload_flags|=0x10008u;
            ll_level_script_set_input(&script,0x1000);ll_level_script_update(&script);
            assert(!script.native.player_dynamite && script.native.level_event_latch==1 && !script.player.blocked);
            puts("Original crouch: Down212 -> hold213, turn/walk/jump cancellation, rise214, V stock/support gates and pause: OK");
            ll_level_script_close(&script);continue;
        }
        if (replay==3) {
            /* Controlled valid anchor beside the unchanged pack. Its own script supplies three sticks. */
            int32_t point[3]={script.objects[76].pose->position[0],0,script.objects[76].pose->position[2]};
            LL_BibPathAnchor anchor;LL_BibPathSegment segment;
            assert(ll_bib_prepare_path_anchor(&script.bib,player->path.selector,point,&anchor));
            assert(ll_bib_get_path_segment(&script.bib,player->path.selector,anchor.segment_index,&segment));
            LL_NativePathSegmentState orientation;
            ll_native_path_segment_reset(segment.start,segment.end,segment.length,&orientation);
            player->path.segment=anchor.segment_index;
            player->path.distance=player->path.previous_distance=anchor.distance;
            player->path.yaw=orientation.yaw;player->path.pitch=orientation.pitch;script.player.yaw=orientation.yaw;
            int32_t angles[3]={0,orientation.yaw,0};int16_t rotation[3][3];
            ll_native_model_rotation(angles,rotation);memcpy(player->root_rotation,rotation,sizeof(rotation));
            memcpy(player->pose->position,anchor.position,sizeof(anchor.position));
            memcpy(player->path.previous_position,anchor.position,sizeof(anchor.position));
            memcpy(player->collision_previous_position,anchor.position,sizeof(anchor.position));
            script.native.camera_callback_enabled=script.native.camera_output_active=0;
            ll_level_script_update(&script);assert(script.native.player_dynamite==3);
        } else script.native.player_dynamite=2; /* Controlled inventory to isolate the controller/fuse. */
        int16_t stock=script.native.player_dynamite,height=script.native.camera_follow_height;
        unsigned plant=0,explosion=0,reset=0,snapshot=0,sound=0,damage=0,shake=0;
        unsigned fuse_pause=0,explosion_pause=0;int32_t fuse_root[3]={0};
        for (unsigned i=0;i<320;i++) {
            uint16_t input=replay==1?0x1000u:i==0?0x1000u:replay==2 && i<100?0x4020u:0u;
            ll_level_script_set_input(&script,input);ll_level_script_update(&script);
            if (!i) {
                plant=script.updates;
                assert(script.native.player_dynamite==stock-1 && script.native.level_event_latch==1);
                assert(script.player.mode==15 && script.player.event==19);
            }
            if (script.objects[5].sprite_animation_active && !fuse_root[0])
                memcpy(fuse_root,script.objects[5].pose->position,sizeof(fuse_root));
            if (script.contexts[5].state==2 && script.contexts[5].body_done) {
                snapshot=1;
                assert(script.contexts[5].vm.stack_size==5 && script.contexts[5].vm.locals[0x20]==5);
                assert(script.contexts[5].vm.locals[0x26]==(uint16_t)(stock-1));
            }
            if (script.objects[6].sprite_animation_active) {
                if (!explosion) explosion=script.updates;
                assert(script.objects[6].sprite_selector==98);
                assert(script.objects[6].pose->position[0]==fuse_root[0] &&
                    script.objects[6].pose->position[1]==fuse_root[1]-1000 &&
                    script.objects[6].pose->position[2]==fuse_root[2]);
            }
            if (script.native.native_word_44<3 && !damage) damage=script.updates;
            shake|=script.native.camera_follow_height!=height;
            for (unsigned v=0;v<64;v++)
                if (script.audio.mixer.voices[v].active && script.audio.mixer.voices[v].pcm==script.audio.pcm[20]) sound=1;
            if (!reset && !script.native.level_event_latch) reset=script.updates;
            if (pause_path && script.objects[5].sprite_animation_active && !fuse_pause) {
                pause_original_dynamite(&script);fuse_pause=1;
            }
            if (pause_path && explosion && !explosion_pause) {
                pause_original_dynamite(&script);explosion_pause=1;
            }
            assert(script.blocked_count==blocked && !script.player.blocked && !script.native.camera_blocked &&
                !script.native.collision_blocked_count);
        }
        assert(explosion>plant && explosion-plant>=63 && explosion-plant<=66 && reset>explosion);
        assert(snapshot && shake && sound && script.native.camera_follow_height==height);
        assert(script.native.player_dynamite==stock-1 && script.native.player_lives==5);
        assert(script.native.native_word_44==(replay==2?3:2) && (replay==2?!damage:damage!=0));
        assert(script.contexts[5].state==4 && !script.native.level_event_latch);
        assert(!script.objects[5].sprite_animation_active && !script.objects[6].sprite_animation_active);
        assert(fuse_pause==(pause_path!=NULL) && explosion_pause==(pause_path!=NULL));
        printf("Original dynamite%u: stock%d->%d plant%u explosion%u damage%u reset%u health%u pause%u/%u\n",
            replay,stock,script.native.player_dynamite,plant,explosion,damage,reset,script.native.native_word_44,fuse_pause,explosion_pause);
        if (replay==1) {
            /* Holding V through the first reset did not rearm it. A new press must. */
            ll_level_script_set_input(&script,0);ll_level_script_update(&script);
            ll_level_script_set_input(&script,0x1000);ll_level_script_update(&script);
            assert(!script.native.player_dynamite && script.native.level_event_latch==1);
            ll_level_script_set_input(&script,0);unsigned second_snapshot=0;
            for (unsigned i=0;i<200;i++) {
                ll_level_script_update(&script);
                if (script.contexts[5].state==2 && script.contexts[5].body_done) {
                    second_snapshot=1;assert(script.contexts[5].vm.stack_size==5);
                    assert(!script.contexts[5].vm.locals[0x26] && script.contexts[5].vm.locals[0x22]==2);
                }
                assert(script.blocked_count==blocked && !script.player.blocked && !script.native.camera_blocked);
            }
            assert(second_snapshot && !script.native.level_event_latch && script.native.native_word_44==1 &&
                script.native.player_lives==5 && !script.native.player_dynamite);
            puts("Original dynamite: release/repress V starts a second complete fuse/explosion and refreshes snapshot: OK");
        }
        ll_level_script_close(&script);
    }
    fclose(trace);free(code);free(bib);free(biz);
}

static void test_boss_bounds_cache(const unsigned char *bib, size_t bib_size)
{
    unsigned char body[160];size_t at=0;
    body[at++]=0x10; /* All cache queries must execute in one native burst. */
    const unsigned modes[4]={2,2,1,2};
    for (unsigned i=0;i<4;i++) {
        if (i==1) {
            const unsigned char move[]={5,0,0,5,0,0,5,0xe8,3,5,0x1c,0,0x3f};
            memcpy(body+at,move,sizeof(move));at+=sizeof(move);
        }
        const unsigned char query[]={5,0,0,5,150,0,5,0,0,5,0x66,0,0x53,5,0,0,0x28,0x3b};
        memcpy(body+at,query,sizeof(query));word(body+at+1,modes[i]);word(body+at+14,18+i*2);at+=sizeof(query);
    }
    body[at++]=0;
    const unsigned char end[]={0};unsigned char data[1024];size_t size=fixture(data,body,at,end,sizeof(end),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,bib,bib_size,trace));
    unsigned model=0;LL_BibModelPart part;
    for (;model<script.bib.model_count;model++)
        if (ll_bib_get_model_part(&script.bib,model,2,&part) && part.vertex_count) break;
    assert(model<script.bib.model_count);
    LL_LevelScriptObject *object=&script.objects[150];object->present=1;object->kind=1;object->model_index=model;
    object->pose=&object->private_pose;object->bounds=object->private_bounds;
    object->root_rotation=object->private_root_rotation;
    object->private_root_rotation[0]=object->private_root_rotation[4]=object->private_root_rotation[8]=4096;
    for (unsigned i=0;i<3;i++) { object->bounds[i]=-32768;object->bounds[i+3]=32767; }
    script.contexts[0].instance=150;ll_level_script_update(&script);
    assert(!script.blocked_count && script.contexts[0].vm.locals[18]==1 && !script.contexts[0].vm.locals[20]);
    assert(script.contexts[0].vm.locals[22]==1 && script.contexts[0].vm.locals[24]==1);
    assert(object->pose->position[0]==100000 && object->query_bounds_valid && object->query_bounds_mode==2);
    ll_level_script_close(&script);fclose(trace);
}

static void test_original_boss_replacement(LL_LevelScript *script, const char *pause_path)
{
    size_t code_size,bib_size,biz_size,pause_size=0;
    unsigned char *code=read_asset("iso_extract/ABI_BOSS/abi_boss.cod",&code_size);
    unsigned char *bib=read_asset("iso_extract/ABI_BOSS/ABI_BOSS.BIB",&bib_size);
    unsigned char *biz=read_asset("iso_extract/ABI_BOSS/ABI_BOSS.BIZ",&biz_size);
    unsigned char *pause=pause_path?read_asset(pause_path,&pause_size):NULL;
    test_boss_bounds_cache(bib,bib_size);
    script->native.player_lives=2;script->native.player_money=37;script->native.player_cards=4;
    script->native.control_profile=script->native.saved_control_profile=2;
    script->audio.stereo=0;script->audio.master_volume=73;
    unsigned char *old_code=script->code_data;LL_LevelScriptContext *old_contexts=script->contexts;
    LL_LevelNativeSetup native=script->native;unsigned updates=script->updates;
    const unsigned char invalid[]={0,0,0,0};
    for (unsigned bad=0;bad<(pause_path?4u:3u);bad++) {
        ll_native_rng_reset();assert(ll_native_rng_word()==22539);
        assert(!ll_level_script_replace(script,bad==0?invalid:code,bad==0?sizeof(invalid):code_size,
            bad==1?invalid:bib,bad==1?sizeof(invalid):bib_size,bad==2?invalid:biz,bad==2?sizeof(invalid):biz_size,
            bad==3?invalid:pause,bad==3?sizeof(invalid):pause_size));
        assert(script->code_data==old_code && script->contexts==old_contexts && script->updates==updates);
        assert(script->scene_requested && script->requested_scene==3 && !memcmp(&native,&script->native,sizeof(native)));
        assert(ll_native_rng_word()==1810); /* A rejected resource set must not restart the live random stream. */
    }
    assert(ll_level_script_replace(script,code,code_size,bib,bib_size,biz,biz_size,pause,pause_size));
    free(code);free(bib);free(biz);free(pause);
    assert(script->program.function_count==24 && !script->updates && !script->scene_requested && !script->blocked_count);
    assert(script->audio.sample_count==25 && !script->audio.stereo && script->audio.master_volume==73);
    assert(script->native.player_lives==2 && script->native.player_money==37 && script->native.player_cards==4);
    unsigned walked_right=0,walked_left=0,fired=0,queried_part=0,paused=0;
    int32_t start=0,maximum=INT32_MIN,minimum=INT32_MAX;
    for (unsigned i=0;i<400;i++) {
        uint16_t input=i>=110 && i<140?0x20u:i>=160 && i<190?0x80u:i>=210?0x2000u:0;
        ll_level_script_set_input(script,input);ll_level_script_update(script);
        LL_LevelScriptObject *lucky=&script->objects[11];assert(lucky->present && lucky->pose);
        if (!i) {
            start=lucky->pose->position[0];
            assert(script->native.control_profile==0 && script->contexts[11].vm.locals[48]==2);
            assert(script->native.previous_control_profile==2 && script->native.timer_manager_registered);
            assert(script->native.native_word_44==3 && !script->native.player_dynamite && script->native.player_cards==4);
            assert(script->contexts[4].vm.locals[18]==2 && script->contexts[4].vm.locals[24]==0);
            assert(!script->objects[76].present && script->static_model_count==16);
        }
        int32_t x=lucky->pose->position[0];if (x>maximum) maximum=x;if (x<minimum) minimum=x;
        walked_right|=lucky->animation_selector==50;walked_left|=lucky->animation_selector==51;
        fired|=lucky->animation_selector==53;
        queried_part|=lucky->query_bounds_valid && lucky->query_bounds_mode==2;
        assert(!script->contexts[11].blocked && !script->contexts[14].blocked && !script->contexts[15].blocked);
        assert(script->blocked_count==(pause_path?1u:2u) && !script->native.camera_blocked);
        if (pause_path && !paused && lucky->animation_selector==50) {
            ll_level_script_set_system_input(script,LL_PAUSE_KEY);ll_level_script_update(script);
            ll_level_script_set_system_input(script,0);ll_level_script_update(script);assert(script->pause.paused);
            LL_LevelScriptObject before=*lucky;
            unsigned tick=script->updates;
            for (unsigned j=0;j<8;j++) ll_level_script_update(script);
            assert(script->updates==tick && !memcmp(&before,lucky,sizeof(before)));
            ll_level_script_set_system_input(script,LL_PAUSE_KEY);ll_level_script_update(script);
            ll_level_script_set_system_input(script,0);ll_level_script_update(script);assert(!script->pause.paused);paused=1;
        }
    }
    assert(walked_right && walked_left && fired && queried_part && maximum>start && minimum<=start);
    assert(script->native.player_lives==2 && script->native.player_money==37 && script->native.player_cards==4);
    assert(paused==(pause_path!=NULL));
    printf("Original Abilene -> Abi_Boss: atomic resources, 24 contexts, profileC->A, right/left/fire, part bounds, pause%u: OK\n",paused);
}

/* Inputs only: align with the thrown crate, release each lateral step, and
 * optionally release B near the incoming crate to swing the original shovel. */
static uint16_t boss_replay_actions(const LL_LevelScript *script, int deflect)
{
    if (script->updates<=108) return 0;
    const LL_LevelScriptObject *lucky=&script->objects[11],*enemy=&script->objects[14],*crate=&script->objects[15];
    if (!lucky->pose || !enemy->pose || !crate->pose) return 0;
    int32_t target=script->contexts[15].state==5?crate->pose->position[0]:enemy->pose->position[0]-763;
    int32_t dx=target+(deflect?500:0)-lucky->pose->position[0];
    uint16_t input=dx>250?0x20u:dx< -250?0x80u:0;
    unsigned state=script->contexts[11].state;
    if ((state==3 || state==4) && lucky->animation_frame==lucky->animation_last) input=0;
    if (deflect && dx>=-500 && dx<=500 && (state==2 || state==5))
        input=script->contexts[15].state!=5 || crate->pose->position[2]-lucky->pose->position[2]>2000?0x2000u:0;
    return input;
}

static void test_original_boss_outcomes(const char *pause_path)
{
    size_t code_size,bib_size,biz_size,pause_size=0;
    unsigned char *code=read_asset("iso_extract/ABI_BOSS/abi_boss.cod",&code_size);
    unsigned char *bib=read_asset("iso_extract/ABI_BOSS/ABI_BOSS.BIB",&bib_size);
    unsigned char *biz=read_asset("iso_extract/ABI_BOSS/ABI_BOSS.BIZ",&biz_size);
    unsigned char *pause=pause_path?read_asset(pause_path,&pause_size):NULL;
    FILE *trace=tmpfile();assert(trace);
    for (unsigned win=0;win<2;win++) {
        LL_LevelScript script={0};script.trace=trace;
        assert(ll_level_script_replace(&script,code,code_size,bib,bib_size,biz,biz_size,pause,pause_size));
        script.native.control_profile=script.native.saved_control_profile=2;
        script.native.player_money=37;script.native.player_cards=4;
        unsigned baseline=pause_path?1u:2u,damage=0,returns=0,hits=0,dead=0,celebrated=0,full_display=0,banner=0,finished=0;
        unsigned previous_crate=0,previous_enemy=0;int health=3;
        for (unsigned i=0;i<5000;i++) {
            ll_level_script_set_input(&script,boss_replay_actions(&script,(int)win));ll_level_script_update(&script);
            unsigned player_state=script.contexts[11].state,crate_state=script.contexts[15].state,enemy_state=script.contexts[14].state;
            if ((int16_t)script.native.native_word_44<health) { damage++;assert((int16_t)script.native.native_word_44==health-1); }
            health=(int16_t)script.native.native_word_44;
            if (crate_state==6 && previous_crate!=6) { returns++;assert(script.objects[15].motion[2]>0); }
            if (enemy_state==10 && previous_enemy!=10) hits++;
            previous_crate=crate_state;previous_enemy=enemy_state;
            dead|=player_state==9;celebrated|=player_state==7;full_display|=script.native.force_full_display!=0;
            banner|=script.objects[13].visible && script.objects[13].animation_selector==62;
            assert(!script.native.camera_blocked && !script.player.blocked && !script.contexts[14].blocked && !script.contexts[15].blocked);
            if (script.scene_requested || script.contexts[11].blocked) {
                finished=script.updates;assert(script.native.fade_alpha==255 && !script.native.fade_direction);
                assert(script.native.control_profile==2 && !script.native.force_full_display);
                if (win) {
                    assert(!script.scene_requested && script.contexts[11].blocked && script.blocked_count==baseline+1);
                    assert(script.contexts[11].vm.last_instruction_offset==0x568 && strstr(script.contexts[11].error,"outer scene"));
                    assert(script.contexts[11].vm.stack_size==2 && script.contexts[11].vm.stack[0]==4);
                } else {
                    assert(script.scene_requested && script.scene_reload && !script.requested_scene && script.blocked_count==baseline);
                    assert(script.native.player_lives==4 && script.native.native_word_44==3 && !script.audio.muted && !script.native.cd_paused);
                }
                break;
            }
            assert(script.blocked_count==baseline);
        }
        assert(finished && script.native.player_money==37 && script.native.player_cards==4);
        if (win) {
            assert(returns && hits==3 && celebrated && !dead && script.native.player_lives==5);
            assert(script.contexts[14].state==11 && script.contexts[14].vm.locals[44]==3);
        } else {
            assert(damage==4 && !returns && !hits && dead && full_display && banner);
            assert(ll_level_script_replace(&script,code,code_size,bib,bib_size,biz,biz_size,pause,pause_size));
            assert(!script.scene_reload && !script.scene_requested && !script.updates);
            for (unsigned i=0;i<160;i++) ll_level_script_update(&script);
            assert(script.native.player_lives==4 && script.native.native_word_44==3);
            assert(script.native.player_money==37 && script.native.player_cards==4);
            assert(script.contexts[4].vm.locals[18]==4 && script.contexts[4].vm.locals[20]==3);
            assert(script.native.control_profile==0 && script.contexts[11].vm.locals[48]==2);
            assert(script.objects[11].pose->position[0]==16062 && script.objects[15].pose->position[0]==14846);
            assert(script.blocked_count==baseline && script.native.pause_enabled==(pause_path!=NULL));
        }
        printf("Original Abi_Boss %s: tick%u damage%u returns%u hits%u lives%d, profile restored, %s: OK\n",
            win?"victory":"defeat",finished,damage,returns,hits,script.native.player_lives,
            win?"explicit unported Gare transition":"banner then fresh duel");
        ll_level_script_close(&script);
    }
    fclose(trace);free(code);free(bib);free(biz);free(pause);
}

static void test_original_dynamite_gate(char **paths, const char *pause_path)
{
    size_t code_size,bib_size,biz_size;
    unsigned char *code=read_asset(paths[0],&code_size),*bib=read_asset(paths[1],&bib_size);
    unsigned char *biz=read_asset(paths[2],&biz_size);
    FILE *trace=tmpfile();assert(trace);
    for (unsigned replay=0;replay<3;replay++) {
        LL_LevelScript script={0};assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
        assert(ll_level_script_set_biz(&script,biz,biz_size));attach_original_pause(&script,pause_path);
        for (unsigned i=0;i<120;i++) ll_level_script_update(&script);
        unsigned baseline=script.blocked_count;
        LL_LevelScriptObject *player=&script.objects[4],*gate=&script.objects[52];
        LL_BibScenePose blast_box;assert(ll_bib_get_scene_pose(&script.bib,91,70,&blast_box));
        assert(blast_box.position[0]==204000 && blast_box.angles[0]==206500);
        int32_t point[3]={(blast_box.position[0]+blast_box.angles[0])/2-(replay==2?8000:0),0,
            (blast_box.position[2]+blast_box.angles[2])/2};
        LL_BibPathAnchor anchor;LL_BibPathSegment segment;
        assert(ll_bib_prepare_path_anchor(&script.bib,player->path.selector,point,&anchor));
        assert(ll_bib_get_path_segment(&script.bib,player->path.selector,anchor.segment_index,&segment));
        LL_NativePathSegmentState orientation;
        ll_native_path_segment_reset(segment.start,segment.end,segment.length,&orientation);
        player->path.segment=anchor.segment_index;player->path.distance=player->path.previous_distance=anchor.distance;
        player->path.yaw=orientation.yaw;player->path.pitch=orientation.pitch;script.player.yaw=orientation.yaw;
        int32_t angles[3]={0,orientation.yaw,0};int16_t rotation[3][3];ll_native_model_rotation(angles,rotation);
        memcpy(player->root_rotation,rotation,sizeof(rotation));memcpy(player->pose->position,anchor.position,sizeof(anchor.position));
        memcpy(player->path.previous_position,anchor.position,sizeof(anchor.position));
        memcpy(player->collision_previous_position,anchor.position,sizeof(anchor.position));
        /* Controlled valid path anchor and stock. Teleport camera recovery is a separate unported branch. */
        script.native.camera_callback_enabled=script.native.camera_output_active=0;script.native.player_dynamite=2;
        unsigned opening=0,opened=0,paused=0,exit_started=0,exit_fade=0,finished=0;
        uint32_t final_gate_clock=0;
        for (unsigned i=0;i<520;i++) {
            uint16_t input=i==5 || (replay==0 && i==200)?0x1000u:replay==1 && i>150?0x4020u:0u;
            ll_level_script_set_input(&script,input);ll_level_script_update(&script);
            assert(!script.player.blocked && !script.native.collision_blocked_count && !script.native.camera_blocked);
            if (replay!=2 && i<5) assert(player->pose->position[0]==204447 && gate->collision_links[0].active);
            if (script.contexts[52].state==1 && !opening) {
                opening=script.updates;assert(gate->animation_selector==156 && !gate->collision_links[0].active);
                if (pause_path) {
                    pause_original_dynamite(&script);
                    paused=1;
                }
            }
            if (script.contexts[52].state==2) {
                assert(gate->animation_selector==157 && !gate->collision_links[0].active);
                if (!opened) { opened=script.updates;final_gate_clock=gate->animation_started; }
                else assert(final_gate_clock==gate->animation_started); /* A later blast cannot restart an opened obstacle. */
            }
            if (script.player.mode==14) {
                exit_started=1;assert((player->native_payload_flags&0x3e01u)==0x3e01u && player->animation_selector==198);
            }
            if (script.native.fade_direction==2) exit_fade=1;
            if (script.scene_requested) {
                assert(replay==1 && script.blocked_count==baseline && !script.contexts[4].blocked && script.requested_scene==3);
                assert(script.native.fade_alpha==255 && !script.native.fade_direction);
                assert(player->pose->position[0]>211500 && player->pose->position[0]<211700);
                assert(!script.contexts[4].vm.stack_size);
                finished=script.updates;
                if (pause_path) pause_original_dynamite(&script);
                break;
            }
            assert(script.blocked_count==baseline);
        }
        if (replay==2) {
            assert(!opening && !opened && !exit_started && !finished && gate->collision_links[0].active);
            assert(script.contexts[52].state==0 && script.contexts[4].state==3 && script.native.player_dynamite==1);
        } else {
            assert(opening && opened>opening && paused==(pause_path!=NULL));
            if (replay==1) assert(exit_started && exit_fade && finished);
            else assert(!exit_started && !finished && !script.native.player_dynamite && !script.native.level_event_latch);
        }
        printf("Original dynamite gate%u: opening%u opened%u exit%u boss_request%u stock%d pause%u\n",
            replay,opening,opened,exit_started,finished,script.native.player_dynamite,paused);
        if (replay==1) test_original_boss_replacement(&script,pause_path);
        ll_level_script_close(&script);
    }
    fclose(trace);free(code);free(bib);free(biz);
}

static void test_original_camera(char **paths, const char *pause_path)
{
    size_t code_size,bib_size,biz_size;
    unsigned char *code=read_asset(paths[0],&code_size),*bib=read_asset(paths[1],&bib_size);
    unsigned char *biz=read_asset(paths[2],&biz_size);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};unsigned settled[2]={0,0};
    for (unsigned skip=0;skip<2;skip++) {
        assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
        assert(ll_level_script_set_biz(&script,biz,biz_size));
        attach_original_pause(&script,pause_path);
        unsigned absolute_frames=0,follow_frames=0;
        int32_t first[3]={0,0,0},last[3]={0,0,0};
        for (unsigned tick=0;tick<120;tick++) {
            ll_level_script_set_input(&script,skip && tick==4?8:0);
            ll_level_script_update(&script);
            assert(!script.contexts[13].blocked && !script.native.camera_blocked && !script.player.blocked);
            const LL_NativeBackground *background=script.backgrounds[3];assert(background && !script.contexts[3].blocked);
            assert(background->layer_count==3 && background->reference_y==-74);
            assert(background->layers[0].primitive_count==3 && background->layers[1].primitive_count==1 && background->layers[2].primitive_count==3);
            unsigned quads=0;
            for (unsigned layer=0;layer<background->layer_count;layer++)
                for (unsigned primitive=0;primitive<background->layers[layer].primitive_count;primitive++) {
                    LL_BackgroundQuad quad;
                    assert(ll_native_background_quad(background,layer,primitive,&quad));quads++;
                    if (quad.textured) {
                        assert(quad.object==(layer==1?353:351));
                        assert(quad.uv[0][0]==0 && quad.uv[0][1]==1 && quad.uv[3][0]==255);
                        assert(quad.uv[3][1]==(layer==1?63:78));
                    }
                }
            assert(quads==7);
            if (script.native.camera_transition_active) {
                if (script.native.camera_transition_absolute) {
                    if (!absolute_frames) memcpy(first,script.native.camera_render_reference,sizeof(first));
                    memcpy(last,script.native.camera_render_reference,sizeof(last));absolute_frames++;
                } else follow_frames++;
            }
            if (tick>5 && !settled[skip] && script.contexts[13].state==1 &&
                !script.native.camera_transition_active && !script.native.camera_transition_remaining &&
                script.native.camera_follow_instance_plus_one==5) settled[skip]=script.updates;
        }
        assert(absolute_frames>=24 && follow_frames>=24 && settled[skip] && memcmp(first,last,sizeof(first)));
        assert(script.blocked_count==(pause_path?1u:2u) && script.native.depth==6000 && script.native.camera_bounds[3]==-3000);
        assert(script.backgrounds[3]->layers[1].phase[0]==20000); /* One -4 step per callback, independent of quad queries. */
        printf("Original context13 camera: skip%u settled_tick%u absolute_intervals%u follow_intervals%u root[%d,%d,%d] -> [%d,%d,%d]\n",
            skip,settled[skip],absolute_frames,follow_frames,first[0],first[1],first[2],last[0],last[1],last[2]);
        ll_level_script_close(&script);
    }
    assert(settled[1]<settled[0]);
    fclose(trace);free(code);free(bib);free(biz);
}

/* Three controlled drops onto shipped boxes, plus an input-only route from
 * startup to box42. All four run the original states and collision callbacks. */
static void test_original_spring_boxes(char **paths, const char *pause_path)
{
    size_t code_size,bib_size,biz_size;
    unsigned char *code=read_asset(paths[0],&code_size),*bib=read_asset(paths[1],&bib_size);
    unsigned char *biz=read_asset(paths[2],&biz_size);
    const unsigned pickups[3]={73,71,72};
    FILE *trace=tmpfile();assert(trace);
    for (unsigned replay=0;replay<4;replay++) {
        LL_LevelScript script={0};
        assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
        assert(ll_level_script_set_biz(&script,biz,biz_size));attach_original_pause(&script,pause_path);
        for (unsigned i=0;i<120;i++) ll_level_script_update(&script);
        unsigned natural=replay==3,owner=42u+(natural?0:replay),pickup=pickups[natural?0:replay];
        unsigned blocked=script.blocked_count;
        LL_LevelScriptObject *player=&script.objects[4],*box=&script.objects[owner];
        static const int32_t initial_card_bounds[6]={0,0,0,480,744,744};
        assert(!memcmp(script.objects[73].bounds,initial_card_bounds,sizeof(initial_card_bounds)));
        if (!natural) {
            int32_t point[3]={box->pose->position[0],box->pose->position[1]+box->bounds[1]-1000,
                box->pose->position[2]};
            LL_BibPathAnchor anchor;LL_BibPathSegment segment;
            assert(ll_bib_prepare_path_anchor(&script.bib,player->path.selector,point,&anchor));
            assert(ll_bib_get_path_segment(&script.bib,player->path.selector,anchor.segment_index,&segment));
            LL_NativePathSegmentState orientation;
            ll_native_path_segment_reset(segment.start,segment.end,segment.length,&orientation);
            player->path.segment=anchor.segment_index;
            player->path.distance=player->path.previous_distance=anchor.distance;
            player->path.yaw=orientation.yaw;player->path.pitch=orientation.pitch;script.player.yaw=orientation.yaw;
            int32_t angles[3]={0,orientation.yaw,0};int16_t rotation[3][3];
            ll_native_model_rotation(angles,rotation);memcpy(player->root_rotation,rotation,sizeof(rotation));
            memcpy(player->pose->position,anchor.position,sizeof(anchor.position));
            memcpy(player->path.previous_position,anchor.position,sizeof(anchor.position));
            memcpy(player->collision_previous_position,anchor.position,sizeof(anchor.position));
            player->native_payload_flags&=~0x20u; /* Relocate above the box; ordinary controller starts falling. */
            script.native.camera_callback_enabled=script.native.camera_output_active=0;
        }
        unsigned contact=0,launch=0,opened=0,landed=0,poses=0,sound=0,paused=0;
        unsigned spawned=0,collected=0,pickup_sound=0,effect=0;
        unsigned input_phase=0;
        int32_t top=player->pose->position[1];
        for (unsigned i=0;i<400;i++) {
            if (natural) { /* Only ordinary inputs from the unchanged startup position/camera. */
                uint16_t input=0x80;
                if (!input_phase && player->pose->position[0]<7900) { input_phase=1;input|=0x8000u; }
                if (input_phase==1 && player->pose->position[0]<7100) input_phase=2;
                ll_level_script_set_input(&script,input_phase==2?0:input);
            }
            ll_level_script_update(&script);
            for (unsigned n=0;n<3;n++)
                if (box->collision_links[n].active && (box->collision_links[n].flags&0x80u)) contact=script.updates;
            if (contact && !launch && script.player.mode==4) {
                launch=script.updates;
                assert(contact && script.player.vertical_speed==-113 && script.player.event==15);
                assert(!script.player.fall_sound_ticks && !script.player.air_motion && !script.player.speed);
                assert((player->native_payload_flags&0x40000u) && !(player->native_payload_flags&0x20u));
            }
            if (box->animation_selector>=158 && box->animation_selector<=160)
                poses|=1u<<(box->animation_selector-158u);
            for (unsigned voice=0;voice<64;voice++)
                if (script.audio.mixer.voices[voice].active && script.audio.mixer.voices[voice].pcm==script.audio.pcm[44]) sound=1;
            if (player->pose->position[1]<top) top=player->pose->position[1];
            if (script.contexts[owner].state==3 && !opened) opened=script.updates;
            if (launch && script.player.mode==1 && !landed) landed=script.updates;
            LL_LevelScriptObject *bonus=&script.objects[pickup];
            if (!spawned && script.contexts[pickup].state==2) spawned=script.updates;
            if (pickup==73) {
                if (script.contexts[pickup].state==2 && bonus->sprite_selector==96 && !bonus->sprite_frame) {
                    static const int32_t frame_card_bounds[6]={-210,-384,-384,210,312,744};
                    assert(!memcmp(bonus->bounds,frame_card_bounds,sizeof(frame_card_bounds)));
                }
                if (script.native.player_cards && !collected) collected=script.updates;
                effect|=bonus->sprite_selector==102 && bonus->sprite_animation_active;
                for (unsigned voice=0;voice<64;voice++)
                    if (script.audio.mixer.voices[voice].active && script.audio.mixer.voices[voice].pcm==script.audio.pcm[52])
                        pickup_sound=1;
            }
            if (pause_path && launch && script.updates>=launch+3u && !paused) {
                ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);assert(script.pause.paused);
                LL_LevelPlayer retained=script.player;LL_LevelScriptObject retained_box=*box,retained_player=*player;
                unsigned updates=script.updates;
                for (unsigned n=0;n<8;n++) ll_level_script_update(&script);
                assert(script.updates==updates && !memcmp(&script.player,&retained,sizeof(retained)));
                assert(!memcmp(box,&retained_box,sizeof(retained_box)) && !memcmp(player,&retained_player,sizeof(retained_player)));
                ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);assert(!script.pause.paused);
                paused=1;
            }
            assert(script.blocked_count==blocked && !script.player.blocked && !script.native.collision_blocked_count &&
                !script.native.camera_blocked);
            if (landed && script.updates>=landed+(pickup==73?40u:4u)) break; /* Barrel67 is tested separately. */
        }
        printf("Original spring box%u: natural%u contact%u launch%u open%u landed%u apex%d animations%x sound44=%u pickup%u\n",
            owner,natural,contact,launch,opened,landed,top,poses,sound,pickup);fflush(stdout);
        assert(launch==(natural?296u:127u) && opened==launch+14u && landed==launch+(natural?27u:26u) &&
            poses==7 && sound && top==(natural?-2115:-1976));
        assert(paused==(pause_path!=NULL) && script.native.native_word_44==3 && script.native.player_lives==5);
        for (unsigned n=0;n<3;n++) assert(!box->collision_links[n].active);
        assert(spawned);
        if (pickup==73) {
            assert(collected && pickup_sound && effect &&
                script.native.player_cards==1 && script.native.cards_dirty);
            assert(script.contexts[pickup].state==3 && !script.objects[pickup].sprite_animation_active &&
                !script.objects[pickup].sprite_primitives_present);
            assert(script.contexts[77].vm.locals[0x24]==1);
            printf("Original card73: spawned%u collected%u count1 sound52 effect102 complete\n",spawned,collected);
        } else assert(script.contexts[pickup].state==2 && script.objects[pickup].sprite_animation_active);
        const LL_LevelScriptObject *sprite=&script.objects[pickup];
        assert(sprite->pose->position[0]==box->pose->position[0]/100*100 &&
            sprite->pose->position[1]==box->pose->position[1]/100*100-400 &&
            sprite->pose->position[2]==box->pose->position[2]/100*100);
        ll_level_script_close(&script);
    }
    fclose(trace);free(code);free(bib);free(biz);
}

/* Controlled anchors on each shipped special path, without editing its flags,
 * links, geometry or SOOL states. This does not establish a natural playthrough. */
static void test_original_automatic_paths(char **paths, const char *pause_path)
{
    size_t code_size,bib_size,biz_size;
    unsigned char *code=read_asset(paths[0],&code_size),*bib=read_asset(paths[1],&bib_size);
    unsigned char *biz=read_asset(paths[2],&biz_size);
    const unsigned segments[4]={39,42,55,26},exits[4]={14,38,24,18};
    const int32_t ends[4][3]={{123047,-332,9744},{123550,-3716,7647},
        {159100,-4204,8552},{202550,-4798,11202}};
    FILE *trace=tmpfile();assert(trace);
    for (unsigned replay=0;replay<4;replay++) {
        LL_LevelScript script={0};
        assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
        assert(ll_level_script_set_biz(&script,biz,biz_size));attach_original_pause(&script,pause_path);
        for (unsigned i=0;i<120;i++) ll_level_script_update(&script);
        unsigned blocked=script.blocked_count;
        assert(blocked==(pause_path?1u:2u));
        LL_LevelScriptObject *player=&script.objects[4];
        assert(player->material && player->material->multiplier==256);
        LL_LevelObjectPath initial_path=player->path;
        int32_t initial_position[3];memcpy(initial_position,player->pose->position,sizeof(initial_position));
        LL_BibPathSegment segment;
        assert(ll_bib_get_path_segment(&script.bib,player->path.selector,segments[replay],&segment));
        assert((segment.flags&255u)==(replay<2?1u:2u));
        int32_t point[3],projected[3],along;
        for (unsigned axis=0;axis<3;axis++)
            point[axis]=segment.start[axis]+(segment.end[axis]-segment.start[axis])/4;
        assert(ll_bib_project_path_segment(&segment,point,projected,&along));
        LL_NativePathSegmentState orientation;
        ll_native_path_segment_reset(segment.start,segment.end,segment.length,&orientation);
        player->path.segment=segments[replay];
        player->path.distance=player->path.previous_distance=(int16_t)along;
        player->path.yaw=orientation.yaw;player->path.pitch=orientation.pitch;
        player->path.heading=(uint16_t)orientation.yaw;script.player.yaw=orientation.yaw;
        int32_t angles[3]={0,orientation.yaw,0};int16_t rotation[3][3];
        ll_native_model_rotation(angles,rotation);memcpy(player->root_rotation,rotation,sizeof(rotation));
        memcpy(player->pose->position,projected,sizeof(projected));
        memcpy(player->path.previous_position,projected,sizeof(projected));
        memcpy(player->collision_previous_position,projected,sizeof(projected));
        script.native.camera_callback_enabled=0;script.native.camera_output_active=0;
        unsigned automatic=0,deferred=0,shadow=0,exit_tick=0;
        for (unsigned i=0;i<150;i++) {
            ll_level_script_update(&script);
            if (i==0) {
                assert(script.player.mode==(replay<2?11:12) && script.player.event==(replay<2?4:5));
                assert(script.player.speed==20 && script.player.displacement==30);
                assert(player->animation_selector==(replay<2?197:198));
            }
            if (script.player.mode==11 || script.player.mode==12) automatic++;
            if (script.player.mode==13) {
                deferred++;assert(replay>=2 && script.player.speed==66 && script.player.displacement==132);
            }
            if (!exit_tick && script.player.mode==1) exit_tick=script.updates;
            shadow|=player->material->multiplier==128;
            assert(script.blocked_count==blocked && !script.player.blocked && !script.native.collision_blocked_count);
            if (pause_path && i==3) {
                ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);assert(script.pause.paused);
                LL_LevelPlayer retained=script.player;LL_LevelScriptObject object=*player;
                unsigned updates=script.updates;
                for (unsigned n=0;n<8;n++) ll_level_script_update(&script);
                assert(script.updates==updates && !memcmp(&retained,&script.player,sizeof(retained)));
                assert(!memcmp(&object,player,sizeof(object)));
                ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);assert(!script.pause.paused);
            }
        }
        assert(automatic && deferred==(replay>=2?1u:0u) && exit_tick);
        assert(script.player.mode==1 && !script.player.speed && player->path.segment==exits[replay]);
        assert(!memcmp(player->pose->position,ends[replay],sizeof(ends[replay])));
        if (replay<2) {
            assert(shadow && player->material->multiplier==128 && (player->native_payload_flags&0x2001u)==0x2001u);
            /* Leaving the original shadow volume must undo both RGB and input restrictions. */
            player->path=initial_path;script.player.yaw=initial_path.yaw;
            angles[1]=initial_path.yaw;ll_native_model_rotation(angles,rotation);
            memcpy(player->root_rotation,rotation,sizeof(rotation));
            memcpy(player->pose->position,initial_position,sizeof(initial_position));
            memcpy(player->collision_previous_position,initial_position,sizeof(initial_position));
            for (unsigned i=0;i<12;i++) ll_level_script_update(&script);
            assert(player->material->multiplier==256 && !(player->native_payload_flags&0x2001u));
            assert(script.blocked_count==blocked && !script.player.blocked);
        } else assert(!shadow && player->material->multiplier==256);
        printf("Original automatic path%u: exit%u tick%u automatic_updates%u deferred%u shadow%u root[%d,%d,%d]: OK\n",
            segments[replay],exits[replay],exit_tick,automatic,deferred,shadow,
            ends[replay][0],ends[replay][1],ends[replay][2]);
        ll_level_script_close(&script);
    }
    fclose(trace);free(code);free(bib);free(biz);
}

/* Controlled replay of the shipped enemy state. The player's relocation and
 * disabled camera/controller isolate the script, muzzle and collision flow;
 * this is not evidence of a natural playthrough or original Windows parity. */
static void test_original_combat(char **paths, const char *pause_path)
{
    size_t code_size,bib_size,biz_size;
    unsigned char *code=read_asset(paths[0],&code_size),*bib=read_asset(paths[1],&bib_size);
    unsigned char *biz=read_asset(paths[2],&biz_size);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
    assert(ll_level_script_set_biz(&script,biz,biz_size));free(code);free(bib);free(biz);
    attach_original_pause(&script,pause_path);
    for (unsigned i=0;i<48;i++) ll_level_script_update(&script);
    LL_LevelScriptObject *player=&script.objects[4],*enemy=&script.objects[23];
    assert(player->present && enemy->present && script.projectiles.initialized);
    LL_LevelObjectPath initial_path=player->path;
    player->update_enabled=0;
    memcpy(player->pose->position,enemy->pose->position,sizeof(player->pose->position));
    player->pose->position[0]-=300;player->pose->position[2]-=2000;
    script.native.camera_callback_enabled=0;script.native.camera_output_active=0;
    script.contexts[23].requested_state=5;script.contexts[23].state_requested=1;
    unsigned shots=0;
    for (unsigned i=0;i<100 && script.native.native_word_44==3;i++) {
        ll_level_script_update(&script);
        assert(!script.contexts[23].blocked && !script.player.blocked);
        if (script.projectiles.enemy_shots_fired!=shots) {
            shots=script.projectiles.enemy_shots_fired;
            unsigned index=script.contexts[23].vm.locals[38];assert(index<10);
            const LL_LevelProjectile *ball=&script.projectiles.slots[index];
            assert(ball->flags==1 && ball->targets[0]==4 && ball->target_count==2);
            assert(ball->velocity[0]==-38 && ball->velocity[1]==0 && ball->velocity[2]==-254);
            printf("Original enemy state5: tick%u ball%u targets[%u,%u] velocity[%d,%d,%d]\n",
                script.updates,index,ball->targets[0],ball->targets[1],ball->velocity[0],ball->velocity[1],ball->velocity[2]);
        }
    }
    assert(shots && script.native.native_word_44==2 && script.native.player_lives==5 && script.player.hurt_callback==1);
    assert(!script.contexts[18].blocked && !script.contexts[20].blocked);
    puts("Original Abilene COD/BIB/BIZ controlled enemy shot -> player impact: OK");
    player->path=initial_path;
    memcpy(player->pose->position,initial_path.previous_position,sizeof(initial_path.previous_position));
    player->update_enabled=1;script.player.hurt_callback=0;script.player.hurt_started=0;
    script.native.native_word_44=0;
    hit_player_with_targeted_ball(&script);
    assert(script.native.player_lives==4 && (script.native.native_flags&1u));
    unsigned dark_frames=0,scene_frames=0,audible_scene_frames=0,clone_animations=0,background_paused=0;
    for (unsigned i=0;i<600;i++) {
        int was_enabled=script.native.background_enabled;
        int16_t previous_phase=script.backgrounds[3]->layers[1].phase[0];
        ll_level_script_update(&script);
        if (!was_enabled && !script.native.background_enabled) {
            assert(script.backgrounds[3]->layers[1].phase[0]==previous_phase);background_paused++;
        }
        if (script.contexts[16].blocked || script.player.blocked || script.native.camera_blocked) {
            fprintf(stderr,"Death replay blocked: %s / %s / %s\n",script.contexts[16].error,script.player.error,script.native.camera_error);
            assert(0);
        }
        dark_frames+=script.native.fade_alpha!=0;
        scene_frames+=script.objects[16].visible && script.objects[16].update_enabled;
        if (script.objects[16].animation_active) {
            if (script.objects[16].animation_selector==113) clone_animations|=1u;
            if (script.objects[16].animation_selector==195) clone_animations|=2u;
        }
        for (unsigned voice=0;voice<64;voice++)
            audible_scene_frames+=script.audio.muted && script.audio.group[voice]==4 &&
                script.audio.mixer.voices[voice].active && script.audio.mixer.voices[voice].gain[0]>0;
        if (!(script.native.native_flags&1u) && script.contexts[16].state==2) break;
    }
    assert(!script.native.native_flags && script.contexts[16].state==2 && !script.contexts[78].blocked);
    assert(script.native.player_lives==4 && script.native.native_word_44==3 && dark_frames && scene_frames && audible_scene_frames);
    assert(clone_animations==3);
    assert(background_paused && script.native.background_enabled);
    assert(!(player->native_payload_flags&0x100u) && script.native.pause_enabled && !script.audio.muted);
    LL_BibPathAnchor checkpoint;
    assert(ll_bib_prepare_path_anchor(&script.bib,player->path.selector,script.native.player_reset_position,&checkpoint));
    assert(player->path.segment==checkpoint.segment_index && player->path.distance==checkpoint.distance);
    assert(!memcmp(player->pose->position,checkpoint.position,sizeof(checkpoint.position)));
    printf("Original Abilene death states15/16 -> recovery tick%u, %u dark frames, %u clone frames, %u audible muted-scene frames: OK\n",
        script.updates,dark_frames,scene_frames,audible_scene_frames);
    for (unsigned i=0;i<32;i++) ll_level_script_update(&script);
    assert(!script.native.fade_alpha && !script.native.fade_direction && !script.native.cd_paused);
    int32_t resumed_x=player->pose->position[0];
    ll_level_script_set_input(&script,0x20);
    for (unsigned i=0;i<8;i++) ll_level_script_update(&script);
    assert(!script.player.blocked && !script.native.camera_blocked && player->pose->position[0]!=resumed_x);
    ll_level_script_set_input(&script,0);
    script.native.player_lives=1;script.native.native_word_44=0;
    hit_player_with_targeted_ball(&script);assert(!script.native.player_lives);
    for (unsigned i=0;i<600 && !script.contexts[16].blocked;i++) ll_level_script_update(&script);
    assert(script.contexts[16].blocked && strstr(script.contexts[16].error,"game-over"));
    assert(!script.player.blocked && !script.native.player_lives);
    puts("Recovery restores movement; last-life reset retains the explicit missing game-over diagnostic: OK");
    ll_level_script_close(&script);fclose(trace);
}

/* Controlled placements isolate the shipped combat states. The enemy hit
 * branch uses an actual player-fired ball, without injecting a hit latch. */
static void test_original_reactions(char **paths, const char *pause_path)
{
    size_t code_size,bib_size,biz_size;
    unsigned char *code=read_asset(paths[0],&code_size),*bib=read_asset(paths[1],&bib_size);
    unsigned char *biz=read_asset(paths[2],&biz_size);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    for (unsigned replay=0;replay<2;replay++) {
        assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
        assert(ll_level_script_set_biz(&script,biz,biz_size));attach_original_pause(&script,pause_path);
        for (unsigned i=0;i<120;i++) ll_level_script_update(&script);
        LL_LevelScriptObject *player=&script.objects[4];
        unsigned expected_blocked=script.blocked_count;
        if (!replay) {
            LL_LevelScriptObject *enemy=&script.objects[24];LL_BibPathAnchor anchor;LL_BibPathSegment segment;
            int32_t destination[3]={enemy->pose->position[0]-2000,0,enemy->pose->position[2]};
            assert(ll_bib_prepare_path_anchor(&script.bib,player->path.selector,destination,&anchor));
            assert(ll_bib_get_path_segment(&script.bib,player->path.selector,anchor.segment_index,&segment));
            LL_NativePathSegmentState orientation;
            ll_native_path_segment_reset(segment.start,segment.end,segment.length,&orientation);
            player->path.segment=anchor.segment_index;player->path.distance=player->path.previous_distance=anchor.distance;
            player->path.yaw=orientation.yaw;player->path.pitch=orientation.pitch;script.player.yaw=orientation.yaw;
            memcpy(player->pose->position,anchor.position,sizeof(anchor.position));
            memcpy(player->path.previous_position,anchor.position,sizeof(anchor.position));
            script.native.camera_callback_enabled=0;script.native.camera_output_active=0;
            ll_level_script_set_input(&script,0x20);ll_level_script_update(&script); /* Face along the actual path. */
            ll_level_script_set_input(&script,0x2000);
            unsigned impact=0,reaction=0;
            for (unsigned i=0;i<40;i++) {
                ll_level_script_update(&script);
                if (script.native.collision_event_latch==24) {
                    assert(!script.projectiles.slots[script.projectiles.hit_slot].flags);
                    impact=script.updates;ll_level_script_set_input(&script,0);
                }
                reaction|=enemy->animation_selector==122;
                assert(!script.contexts[24].blocked && !script.player.blocked && !script.native.camera_blocked);
            }
            assert(impact && reaction && script.contexts[24].state==4 && !script.native.collision_event_latch);
            assert(script.projectiles.shots_fired==1 && script.native.native_word_44==3);
            printf("Original Lucky revolver -> enemy24 impact tick%u, reaction122 and state4: OK\n",impact);
        } else {
            LL_LevelScriptObject *enemy=&script.objects[31];
            memcpy(enemy->pose->position,player->pose->position,sizeof(enemy->pose->position));
            enemy->update_enabled=0; /* Keep its original hit box at the controlled contact. */
            enemy->collision_registered=0; /* Isolate repeated damage queries from the F5 physical separation. */
            script.contexts[31].requested_state=3;script.contexts[31].state_requested=1;
            unsigned impact=0,blink=0;
            for (unsigned i=0;i<40;i++) {
                ll_level_script_update(&script);
                if (!impact && script.native.native_word_44==2) {
                    impact=script.updates;assert(script.player.hurt_callback==2 && script.audio.plays);
                }
                if (impact) {
                    assert(script.native.native_word_44==2 && script.native.player_lives==5);
                    blink|=script.player.hurt_started && !player->visible;
                }
                assert(!script.contexts[31].blocked && !script.player.blocked && !script.native.camera_blocked);
            }
            assert(impact && blink && script.player.hurt_callback==2);
            fflush(trace);rewind(trace);char line[1024];unsigned damage_calls=0;
            while (fgets(line,sizeof(line),trace))
                damage_calls+=strstr(line,"context=31 ") && strstr(line,"variable=0x23 args=[1,1] supported");
            assert(damage_calls>1);
            printf("Original enemy31 contact -> script damage tick%u, %u repeated queries, one health loss and blink: OK\n",impact,damage_calls);
        }
        assert(script.blocked_count==expected_blocked);ll_level_script_close(&script);
    }
    free(code);free(bib);free(biz);fclose(trace);
}

static void test_attachment_commands(const unsigned char *bib, size_t bib_size)
{
    const unsigned char attach[]={5,12,0,5,3,0,5,151,0,5,10,0,5,0x7a,0,0x40,0};
    const unsigned char detach[]={5,151,0,5,0x7b,0,0x3d,0};
    unsigned char data[1024];size_t size=fixture(data,attach,sizeof(attach),detach,sizeof(detach),NULL,0);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,data,size,bib,bib_size,trace));
    const LL_Bib3dxModel *models[2]={ll_bib_find_model(&script.bib,"ABCOW03C3DK"),
        ll_bib_find_model(&script.bib,"ABTONE023DK")};
    int16_t pivots[2][3];const unsigned part_indices[2]={10,3};
    const int16_t identity[9]={4096,0,0,0,4096,0,0,0,4096};
    for (unsigned i=0;i<2;i++) {
        assert(models[i]);LL_LevelScriptObject *object=&script.objects[150+i];
        object->present=object->kind=object->visible=object->update_enabled=object->native_callback_enabled=1;
        object->model_index=(unsigned)(models[i]-script.bib.models);
        object->pose=&object->private_pose;object->root_rotation=object->private_root_rotation;
        memcpy(object->root_rotation,identity,sizeof(identity));memcpy(object->attachment_rotation,identity,sizeof(identity));
        LL_BibVertex *vertices=calloc(models[i]->vertex_count,sizeof(*vertices));assert(vertices);
        LL_BibModelPart part;assert(ll_bib_get_model_part(&script.bib,object->model_index,part_indices[i],&part));
        assert(ll_bib_build_neutral_vertices(&script.bib,object->model_index,vertices,models[i]->vertex_count));
        memcpy(pivots[i],vertices[part.pivot_vertex].position,sizeof(pivots[i]));free(vertices);
    }
    LL_LevelScriptObject *parent=&script.objects[150],*child=&script.objects[151];
    const int32_t origin[3]={10000,-1000,5000};memcpy(parent->pose->position,origin,sizeof(origin));
    script.contexts[0].instance=150;script.contexts[1].instance=152;script.contexts[1].body_done=1;
    ll_level_script_update(&script);assert(!script.blocked_count && script.skeletal_attachment_count==1);
    LL_LevelSkeletalAttachment *link=&script.skeletal_attachments[0];
    assert(link->child_instance==151 && link->parent_part==10 && link->child_part==3);
    for (unsigned a=0;a<3;a++) assert(child->pose->position[a]==origin[a]+pivots[0][a]-pivots[1][a]);
    parent->pose->position[0]+=100;ll_level_script_update(&script);
    assert(child->pose->position[0]==origin[0]+100+pivots[0][0]-pivots[1][0]);
    /* Rebinding the context does not transfer ownership. An attached root
     * setter writes the captured local offset, then presentation resolves it. */
    const unsigned char root_setter[]={5,3,0,5,2,0,5,1,0,5,0x1c,0,0x3f,0};
    memcpy(script.code_data+script.program.functions[0].offset+24,root_setter,sizeof(root_setter));
    script.contexts[0].instance=151;script.contexts[0].body_done=0;
    ll_level_script_update(&script);assert(!script.blocked_count);
    assert(link->root_offset[0]==100 && link->root_offset[1]==200 && link->root_offset[2]==300);
    for (unsigned a=0;a<3;a++) assert(child->pose->position[a]==parent->pose->position[a]+
        link->root_offset[a]+pivots[0][a]-pivots[1][a]);
    const int16_t quarter_turn[9]={0,0,4096,0,4096,0,-4096,0,0};
    memcpy(parent->attachment_rotation,quarter_turn,sizeof(quarter_turn));ll_level_script_update(&script);
    assert(child->pose->position[0]==parent->pose->position[0]+300+pivots[0][0]-pivots[1][0]);
    assert(child->pose->position[2]==parent->pose->position[2]-100+pivots[0][2]-pivots[1][2]);
    assert(!memcmp(child->root_rotation,identity,sizeof(identity))); /* +5c is still independent. */
    int32_t held[3];memcpy(held,child->pose->position,sizeof(held));
    parent->draw_suppressed=1;parent->pose->position[0]+=500;
    ll_level_script_update(&script);
    assert(!memcmp(held,child->pose->position,sizeof(held)) && !ll_level_script_model_presented(&script,151));
    parent->draw_suppressed=0;child->draw_suppressed=1;ll_level_script_update(&script);
    assert(child->pose->position[0]==held[0]+500 && ll_level_script_model_presented(&script,151));
    child->draw_suppressed=0;
    int32_t last_root[3];memcpy(last_root,child->pose->position,sizeof(last_root));
    parent->pose->position[0]+=700; /* Detach must retain the last presented root. */
    script.contexts[1].instance=150;script.contexts[1].body_done=0;
    ll_level_script_update(&script);assert(!script.blocked_count && !script.skeletal_attachment_count);
    assert(!memcmp(last_root,child->pose->position,sizeof(last_root)) &&
        !memcmp(child->root_rotation,quarter_turn,sizeof(quarter_turn)));
    /* Command72 is a presentation gate, with inverse meaning to callback+10. */
    const unsigned char suppress[]={5,1,0,5,151,0,5,0x72,0,0x3e,0};
    memcpy(script.code_data+script.program.functions[0].offset+24,suppress,sizeof(suppress));
    script.contexts[0].body_done=0;ll_level_script_update(&script);
    assert(child->draw_suppressed && child->native_callback_enabled && !script.blocked_count);
    script.code_data[script.program.functions[0].offset+25]=0;
    script.contexts[0].body_done=0;ll_level_script_update(&script);
    assert(!child->draw_suppressed && child->native_callback_enabled && !script.blocked_count);
    /* Mode2 without +10 captures the old world difference as the local
     * offset; mode2 still transforms that difference through parent+7c. */
    unsigned char retained_attach[sizeof(attach)];memcpy(retained_attach,attach,sizeof(attach));
    retained_attach[1]=2;retained_attach[4]=0; /* Child part0 skips the child-pivot subtraction. */
    memcpy(script.code_data+script.program.functions[0].offset+24,retained_attach,sizeof(retained_attach));
    int32_t expected_offset[3];
    for (unsigned a=0;a<3;a++) expected_offset[a]=child->pose->position[a]-pivots[0][a]-parent->pose->position[a];
    script.contexts[0].instance=150;script.contexts[0].body_done=0;ll_level_script_update(&script);
    assert(!script.blocked_count && script.skeletal_attachment_count==1);
    assert(!memcmp(script.skeletal_attachments[0].root_offset,expected_offset,sizeof(expected_offset)));
    assert(child->pose->position[0]==parent->pose->position[0]+expected_offset[2]+pivots[0][0]);
    assert(child->pose->position[1]==parent->pose->position[1]+expected_offset[1]+pivots[0][1]);
    assert(child->pose->position[2]==parent->pose->position[2]-expected_offset[0]+pivots[0][2]);
    script.contexts[1].body_done=0;ll_level_script_update(&script);
    assert(!script.blocked_count && !script.skeletal_attachment_count);
    memcpy(last_root,child->pose->position,sizeof(last_root));
    unsigned char invalid[sizeof(attach)];memcpy(invalid,attach,sizeof(invalid));invalid[1]=11;
    memcpy(script.code_data+script.program.functions[0].offset+24,invalid,sizeof(invalid));
    script.contexts[0].instance=150;script.contexts[0].body_done=0;ll_level_script_update(&script);
    assert(script.contexts[0].blocked && !script.skeletal_attachment_count &&
        !memcmp(last_root,child->pose->position,sizeof(last_root)));
    ll_level_script_close(&script);fclose(trace);
    puts("Native skeletal part attachment, deferred root, independent matrices, retained detach and presentation gate: OK");
}

static void test_original_attachments(const unsigned char *code, size_t code_size,
                                        const unsigned char *bib, size_t bib_size,
                                        const unsigned char *biz, size_t biz_size, const char *pause_path)
{
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    for (unsigned replay=0;replay<2;replay++) {
        assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
        assert(ll_level_script_set_biz(&script,biz,biz_size));attach_original_pause(&script,pause_path);
        for (unsigned i=0;i<120;i++) ll_level_script_update(&script);
        assert(script.skeletal_attachment_count==3);
        assert(script.objects[28].draw_suppressed && script.objects[29].draw_suppressed);
        unsigned expected_blocked=script.blocked_count,parent=replay?66:62,child=parent+1;
        LL_BibScenePose trigger;
        assert(ll_bib_get_scene_pose(&script.bib,91,replay?81:79,&trigger));
        int32_t destination[3]={(trigger.position[0]+trigger.angles[0])/2,0,
            (trigger.position[2]+trigger.angles[2])/2};
        LL_LevelScriptObject *player=&script.objects[4];LL_BibPathAnchor anchor;LL_BibPathSegment segment;
        assert(ll_bib_prepare_path_anchor(&script.bib,player->path.selector,destination,&anchor));
        assert(ll_bib_get_path_segment(&script.bib,player->path.selector,anchor.segment_index,&segment));
        LL_NativePathSegmentState orientation;ll_native_path_segment_reset(segment.start,segment.end,segment.length,&orientation);
        player->path.segment=anchor.segment_index;player->path.distance=player->path.previous_distance=anchor.distance;
        player->path.yaw=orientation.yaw;player->path.pitch=orientation.pitch;script.player.yaw=orientation.yaw;
        memcpy(player->pose->position,anchor.position,sizeof(anchor.position));
        memcpy(player->path.previous_position,anchor.position,sizeof(anchor.position));
        memcpy(player->collision_previous_position,anchor.position,sizeof(anchor.position));
        script.native.camera_callback_enabled=0;script.native.camera_output_active=0;
        unsigned attached=0,detached=0,moved=0;int32_t first[3]={0},last[3]={0};int16_t last_rotation[9]={0};
        for (unsigned i=0;i<500 && !detached;i++) {
            memcpy(last,script.objects[child].pose->position,sizeof(last));
            memcpy(last_rotation,script.objects[child].attachment_rotation,sizeof(last_rotation));
            ll_level_script_update(&script);
            LL_LevelSkeletalAttachment *link=NULL;
            for (unsigned n=0;n<script.skeletal_attachment_count;n++)
                if (script.skeletal_attachments[n].child_instance==child) link=&script.skeletal_attachments[n];
            if (link) {
                assert(link->parent_instance==parent && link->parent_part==10 && link->child_part==3 && !link->blocked);
                if (!attached) {
                    attached=script.updates;memcpy(first,script.objects[child].pose->position,sizeof(first));
                    if (pause_path) {
                        ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                        ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);assert(script.pause.paused);
                        LL_LevelSkeletalAttachment retained=*link;LL_LevelScriptObject retained_child=script.objects[child];
                        for (unsigned n=0;n<8;n++) ll_level_script_update(&script);
                        assert(!memcmp(link,&retained,sizeof(retained)) &&
                            !memcmp(&script.objects[child],&retained_child,sizeof(retained_child)));
                        ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                        ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);assert(!script.pause.paused);
                    }
                }
                else moved|=memcmp(first,script.objects[child].pose->position,sizeof(first))!=0;
            } else if (attached) {
                detached=script.updates;
                assert(!memcmp(last,script.objects[child].pose->position,sizeof(last)));
                assert(!memcmp(last_rotation,script.objects[child].root_rotation,sizeof(last_rotation)));
                assert(!script.objects[child].draw_suppressed && script.skeletal_attachment_count==3);
            }
            assert(script.blocked_count==expected_blocked && !script.native.collision_blocked_count);
        }
        if (!attached || !detached) fprintf(stderr,"Attachment replay parent%u anchor[%d,%d,%d] trigger[%d,%d,%d..%d,%d,%d] state%u attached%u detached%u\n",
            parent,anchor.position[0],anchor.position[1],anchor.position[2],trigger.position[0],trigger.position[1],trigger.position[2],
            trigger.angles[0],trigger.angles[1],trigger.angles[2],script.contexts[parent].state,attached,detached);
        if (!attached) fprintf(stderr,"Player now[%d,%d,%d] bounds[%d,%d,%d..%d,%d,%d] mode%u path%u/%d\n",
            player->pose->position[0],player->pose->position[1],player->pose->position[2],player->bounds[0],player->bounds[1],player->bounds[2],
            player->bounds[3],player->bounds[4],player->bounds[5],script.player.mode,player->path.segment,player->path.distance);
        assert(attached && detached && moved && !script.contexts[parent].blocked && !script.contexts[child].blocked);
        printf("Original context%u: child%u follows parent part10/child part3 at tick%u, detaches with retained root at tick%u: OK\n",
            parent,child,attached,detached);
        unsigned states=0,explosion=0,reset=0,damage=0,floor=0,audio=0,blink=0,flight_pause=0;
        uint16_t health=script.native.native_word_44;
        int16_t lives=script.native.player_lives;
        int32_t release_root[3];memcpy(release_root,script.objects[child].pose->position,sizeof(release_root));
        for (unsigned i=0;i<300 && !reset;i++) {
            ll_level_script_update(&script);LL_LevelScriptObject *barrel=&script.objects[child];
            unsigned current=script.contexts[child].state;states|=1u<<current;
            if (script.native.native_word_44!=health && !damage) damage=script.updates;
            if (barrel->animation_selector==168 && !explosion) explosion=script.updates;
            if (barrel->pose->position[1]==101 && !floor) floor=script.updates;
            if (current==1) reset=script.updates;
            if (pause_path && !flight_pause && current==2 && barrel->motion[1]) {
                ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);assert(script.pause.paused);
                LL_LevelScriptObject retained=*barrel;unsigned updates=script.updates;
                for (unsigned n=0;n<8;n++) ll_level_script_update(&script);
                assert(!memcmp(barrel,&retained,sizeof(retained)) && script.updates==updates);
                ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);assert(!script.pause.paused);
                flight_pause=1;
            }
            blink|=damage && !player->visible;
            for (unsigned v=0;v<64;v++) if (script.audio.mixer.voices[v].active) {
                if (script.audio.mixer.voices[v].pcm==script.audio.pcm[25]) audio|=1u;
                if (script.audio.mixer.voices[v].pcm==script.audio.pcm[26]) audio|=2u;
            }
            assert(script.blocked_count==expected_blocked && !script.native.collision_blocked_count && !script.player.blocked);
        }
        printf("Original barrel%u: states%x floor_tick%u damage_tick%u explosion_tick%u reset_tick%u health%u->%u audio%u blink%u lives%d->%d root[%d,%d,%d]\n",
            child,states,floor,damage,explosion,reset,health,script.native.native_word_44,
            audio,blink,lives,script.native.player_lives,
            script.objects[child].pose->position[0],script.objects[child].pose->position[1],script.objects[child].pose->position[2]);
        assert((states&0x1e)==0x1e && explosion && reset && floor && damage && blink && (audio&2u) &&
            flight_pause==(pause_path!=NULL) &&
            script.native.native_word_44==health-1 && script.native.player_lives==lives &&
            memcmp(release_root,script.objects[child].pose->position,sizeof(release_root)));
        ll_level_script_close(&script);
    }
    fclose(trace);
}

static void test_original_collisions(char **paths, const char *pause_path)
{
    size_t code_size,bib_size,biz_size;
    unsigned char *code=read_asset(paths[0],&code_size),*bib=read_asset(paths[1],&bib_size);
    unsigned char *biz=read_asset(paths[2],&biz_size);
    test_attachment_commands(bib,bib_size);
    test_original_attachments(code,code_size,bib,bib_size,biz,biz_size,pause_path);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    for (unsigned replay=0;replay<3;replay++) {
        assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
        assert(ll_level_script_set_biz(&script,biz,biz_size));attach_original_pause(&script,pause_path);
        for (unsigned i=0;i<120;i++) ll_level_script_update(&script);
        unsigned blocked=script.blocked_count;LL_LevelScriptObject *player=&script.objects[4];
        if (!replay) {
            /* Ordinary input from the startup anchor reaches the first fixed obstacle. */
            ll_level_script_set_input(&script,0x4020);
            for (unsigned i=0;i<120 && script.player.mode!=10;i++) ll_level_script_update(&script);
            assert(script.player.mode==10 && script.player.event==23 && player->animation_selector==216);
            assert(script.objects[48].collision_links[0].flags&0x40);
            int32_t stopped=player->pose->position[0];
            for (unsigned i=0;i<8;i++) ll_level_script_update(&script);
            assert(player->pose->position[0]==stopped && script.player.mode==10);
            ll_level_script_set_input(&script,0xc020);ll_level_script_update(&script);
            assert(script.player.mode==4 && player->pose->position[1]<0);
            assert(script.player.speed==20 && script.player.displacement==30);
            ll_level_script_set_input(&script,0x4020);
            for (unsigned i=0;i<40 && script.player.mode!=10;i++) ll_level_script_update(&script);
            assert(script.player.mode==10 && !player->pose->position[1]);
            ll_level_script_set_input(&script,0x80);
            for (unsigned i=0;i<8;i++) ll_level_script_update(&script);
            assert(player->pose->position[0]<stopped && script.player.mode==2 && !(player->native_payload_flags&0x14));
            const LL_LevelOrbitalGroup *coins=&script.orbital_groups[88];unsigned collected=0;
            assert(coins->sprites);
            for (unsigned m=0;m<coins->member_count;m++) if (!coins->member_active[m]) {
                collected++;
                assert(coins->member_effect[m] && coins->sprites[m].sprite_selector==102 && coins->sprites[m].sprite_scale==32);
            }
            assert(collected && script.native.money_dirty && script.native.player_money>=(int)collected);
            printf("Original coin group88: collected%u money%d effect102\n",collected,script.native.player_money);
            printf("Original startup run -> obstacle48 at X%d, animation216, jump and retreat: OK\n",stopped);
        } else {
            /* Place Lucky at a valid path anchor beside the unchanged first crate. */
            unsigned crate_instance=replay==1?45:46;
            LL_LevelScriptObject *crate=&script.objects[crate_instance];LL_BibPathAnchor anchor;LL_BibPathSegment segment;
            int32_t destination[3]={crate->pose->position[0]+crate->bounds[0]-player->bounds[3]-40,0,crate->pose->position[2]};
            assert(ll_bib_prepare_path_anchor(&script.bib,player->path.selector,destination,&anchor));
            assert(ll_bib_get_path_segment(&script.bib,player->path.selector,anchor.segment_index,&segment));
            LL_NativePathSegmentState orientation;ll_native_path_segment_reset(segment.start,segment.end,segment.length,&orientation);
            player->path.segment=anchor.segment_index;player->path.distance=player->path.previous_distance=anchor.distance;
            player->path.yaw=orientation.yaw;player->path.pitch=orientation.pitch;script.player.yaw=orientation.yaw;
            memcpy(player->pose->position,anchor.position,sizeof(anchor.position));
            memcpy(player->path.previous_position,anchor.position,sizeof(anchor.position));
            memcpy(player->collision_previous_position,anchor.position,sizeof(anchor.position));
            script.native.camera_callback_enabled=0;script.native.camera_output_active=0;
            int32_t initial_crate=crate->pose->position[0];
            ll_level_script_set_input(&script,0x4020);
            for (unsigned i=0;i<18;i++) ll_level_script_update(&script);
            assert(script.player.mode==9 && script.player.event==22 && player->animation_selector==215);
            assert(script.player.speed==20 && script.player.displacement==40 && crate->pose->position[0]>initial_crate);
            unsigned scrape=0;
            for (unsigned voice=0;voice<64;voice++) scrape|=script.audio.mixer.voices[voice].pcm==script.audio.pcm[21];
            assert(scrape);
            ll_level_script_set_input(&script,0);
            for (unsigned i=0;i<3;i++) ll_level_script_update(&script);
            assert(script.player.mode==1 && !script.player.speed && !(player->native_payload_flags&0x14));
            ll_level_script_set_input(&script,0x4020);
            for (unsigned i=0;i<8 && script.player.mode!=9;i++) ll_level_script_update(&script);
            assert(script.player.mode==9);
            ll_level_script_set_input(&script,0xc020);ll_level_script_update(&script);
            assert(script.player.mode==4);
            assert(script.player.speed==20 && script.player.displacement==30);
            unsigned support=0;
            for (unsigned i=0;i<50;i++) {
                uint16_t actions=player->pose->position[0]>=crate->pose->position[0]-100 ||
                    (crate->collision_links[0].flags&0x80)?0:0x4020;
                ll_level_script_set_input(&script,actions);ll_level_script_update(&script);
                if (crate->collision_links[0].flags&0x80) support=script.updates;
            }
            assert(support && script.player.mode==1 && crate->collision_links[0].callback_mode==4);
            assert(player->pose->position[1]==crate->pose->position[1]+crate->bounds[1] &&
                (player->native_payload_flags&0x28)==0x28);
            int32_t on_crate=player->pose->position[0];crate->pose->position[0]+=40;
            ll_level_script_update(&script);assert(player->pose->position[0]==on_crate+40);
            if (pause_path) {
                ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);
                assert(script.pause.paused);LL_LevelScriptObject retained=*player;LL_LevelCollisionLink link=crate->collision_links[0];
                for (unsigned i=0;i<8;i++) ll_level_script_update(&script);
                assert(!memcmp(&retained,player,sizeof(retained)) && !memcmp(&link,&crate->collision_links[0],sizeof(link)));
                ll_level_script_set_system_input(&script,LL_PAUSE_KEY);ll_level_script_update(&script);
                ll_level_script_set_system_input(&script,0);ll_level_script_update(&script);assert(!script.pause.paused);
            }
            if (replay==2) {
                /* Stay on the original crate: the rolling barrel must hit it
                 * while Lucky remains above the impact bounds. */
                uint16_t health=script.native.native_word_44;unsigned audio=0,explosions=0,resets=0;
                ll_level_script_set_input(&script,0);
                for (unsigned i=0;i<200;i++) {
                    ll_level_script_update(&script);
                    explosions+=script.contexts[67].state==4;
                    resets+=script.contexts[67].state==1;
                    for (unsigned v=0;v<64;v++) if (script.audio.mixer.voices[v].active) {
                        if (script.audio.mixer.voices[v].pcm==script.audio.pcm[25]) audio|=1u;
                        if (script.audio.mixer.voices[v].pcm==script.audio.pcm[26]) audio|=2u;
                    }
                    assert(script.native.native_word_44==health && player->pose->position[1]==-1600);
                }
                assert(explosions && resets && audio==3 && !script.contexts[67].blocked);
                puts("Original barrel67 -> crate46: repeated rolling/explosion/reset, sounds25/26, Lucky safe on top: OK");
            }
            ll_level_script_set_input(&script,0x4020);
            for (unsigned i=0;i<32 && crate->collision_links[0].callback_mode==4;i++) ll_level_script_update(&script);
            assert(!(crate->collision_links[0].flags&0x80));
            ll_level_script_update(&script);assert(script.player.mode==5 && player->pose->position[1]>-1600);
            printf("Original crate%u: push animation215/sound21, stop, jump onto its top, carry, pause and walk off: OK\n",crate_instance);
        }
        if (script.blocked_count!=blocked || script.player.blocked || script.native.camera_blocked || script.native.collision_blocked_count)
            ll_level_script_report(&script,stderr);
        assert(script.blocked_count==blocked && !script.player.blocked && !script.native.camera_blocked && !script.native.collision_blocked_count);
        ll_level_script_close(&script);
    }
    free(code);free(bib);free(biz);fclose(trace);
}

static void original_pause_input(LL_LevelScript *script, uint8_t system, uint16_t actions)
{
    ll_level_script_set_system_input(script,system);
    ll_level_script_set_input(script,actions);ll_level_script_update(script);
}

static void test_original_pause(char **paths, const char *pause_path)
{
    size_t code_size,bib_size,biz_size;
    unsigned char *code=read_asset(paths[0],&code_size),*bib=read_asset(paths[1],&bib_size);
    unsigned char *biz=read_asset(paths[2],&biz_size);
    FILE *trace=tmpfile();assert(trace);LL_LevelScript script={0};
    assert(ll_level_script_open(&script,code,code_size,bib,bib_size,trace));
    assert(ll_level_script_set_biz(&script,biz,biz_size));free(code);free(bib);free(biz);
    attach_original_pause(&script,pause_path);
    for (unsigned i=0;i<120;i++) ll_level_script_update(&script);
    assert(script.blocked_count==1 && !script.contexts[14].blocked && script.pause.registered);
    assert(script.native.pause_enabled && !script.pause.paused && !script.audio.muted);
    original_pause_input(&script,LL_PAUSE_KEY,0);assert(!script.pause.paused);
    original_pause_input(&script,0,0);assert(script.pause.paused && script.audio.muted && script.native.cd_paused);
    unsigned updates=script.updates;uint64_t calls=script.calls;
    LL_LevelScriptObject player=script.objects[4];
    LL_BibScenePose pose=*player.pose;
    LL_LevelNativeSetup native=script.native;
    LL_NativeBackground background=*script.backgrounds[3];
    size_t context_size=script.program.function_count*sizeof(*script.contexts);
    void *contexts=malloc(context_size);assert(contexts);memcpy(contexts,script.contexts,context_size);
    uint16_t voice;assert(ll_native_audio_play(&script.audio,script.audio.base,0,8191,1024,&voice) && voice);
    uint64_t phase=script.audio.mixer.voices[voice-1u].position;
    for (unsigned i=0;i<12;i++) original_pause_input(&script,0,0x4020);
    assert(script.updates==updates && script.calls==calls);
    assert(!memcmp(&player,&script.objects[4],sizeof(player)) && !memcmp(&pose,script.objects[4].pose,sizeof(pose)));
    assert(!memcmp(&native,&script.native,sizeof(native)) && !memcmp(&background,script.backgrounds[3],sizeof(background)));
    assert(!memcmp(contexts,script.contexts,context_size));free(contexts);
    assert(script.audio.mixer.voices[voice-1u].position!=phase);
    original_pause_input(&script,LL_PAUSE_KEY,0x4020);assert(script.pause.paused);
    original_pause_input(&script,0,0x4020);
    assert(!script.pause.paused && !script.audio.muted && !script.native.cd_paused && script.updates==updates+1);
    for (unsigned i=0;i<8;i++) original_pause_input(&script,0,0x4020);
    assert(!script.player.blocked && script.objects[4].pose->position[0]!=pose.position[0]);
    /* The script's command4D gate ignores pause requests during death/cutscenes. */
    script.native.pause_enabled=0;
    original_pause_input(&script,LL_PAUSE_EXIT_KEY,0);original_pause_input(&script,0,0);
    assert(!script.pause.paused && !script.pause.continue_menu);
    script.native.pause_enabled=1;
    original_pause_input(&script,LL_PAUSE_EXIT_KEY,0);original_pause_input(&script,0,0);
    assert(script.pause.paused && script.pause.continue_menu);
    original_pause_input(&script,0,8);assert(!script.pause.paused && !script.pause.exit_requested);
    original_pause_input(&script,LL_PAUSE_EXIT_KEY,0);original_pause_input(&script,0,0);
    original_pause_input(&script,0,0x20);original_pause_input(&script,0,8);
    assert(script.pause.quit_menu && !script.pause.quit_selection);
    original_pause_input(&script,0,0);original_pause_input(&script,0,8);
    assert(script.pause.continue_menu && !script.pause.quit_menu && !script.pause.exit_requested);
    original_pause_input(&script,0,0x20);original_pause_input(&script,0,8);
    original_pause_input(&script,0,0x80);updates=script.updates;
    original_pause_input(&script,0,8);
    assert(script.pause.exit_requested && !script.pause.registered && script.updates==updates);
    ll_level_script_update(&script);assert(script.updates==updates);
    ll_level_script_close(&script);fclose(trace);
    puts("Original context14 pause: frozen SOOL/camera/background/player, advancing audio, resume, No and confirmed menu exit: OK");
}

int main(int argc, char **argv)
{
    test_inventory_snapshot();test_camera_shake_and_latch();
    test_scripted_x_approach();test_payload_flag_query();test_scene_and_profile_requests();
    test_reload_and_display_override();
    test_sprite_sequence_release();
    test_inventory_updates();
    test_coordinate_queries();
    test_model_intensity();
    test_ballistic_queries();
    if (argc!=1 && argc!=4 && argc!=5) {
        fprintf(stderr,"usage: level-script-test [abilene.cod abilene.bib abilene.biz [MENU_F.KXP]]\n");return 2;
    }
    test_follow_camera();
    test_absolute_camera();
    test_camera_limits_transition();
    test_script_input();
    test_player();
    test_collision_callbacks();
    test_script_damage();
    test_animation_runtime();
    test_enemy_projectile();
    test_health_words();
    test_projectile_box();
    test_display_fade();
    test_scene_sprite_removal();
    test_checkpoint_command();
    test_level_audio();
    run_tests();
    if (argc>=4) {
        const char *pause_path=argc==5?argv[4]:NULL;
        test_original_sprite_geometry(argv+1);
        test_original_crouch_dynamite(argv+1,pause_path);
        test_original_dynamite_gate(argv+1,pause_path);
        test_original_boss_outcomes(pause_path);
        test_original_camera(argv+1,pause_path);test_original_combat(argv+1,pause_path);
        test_original_reactions(argv+1,pause_path);
        test_original_automatic_paths(argv+1,pause_path);
        test_original_spring_boxes(argv+1,pause_path);
        test_original_collisions(argv+1,pause_path);
        if (pause_path) test_original_pause(argv+1,pause_path);
    }
    puts("Level SOOL scheduling, native controller/camera, combat, fades, checkpoint reset and quarantine: OK");
    return 0;
}
