#include "bib.h"
#include "native_animation.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static void word(unsigned char *p, unsigned value)
{
    p[0]=(unsigned char)value;p[1]=(unsigned char)(value>>8);
}

static void test_short_animation(void)
{
    /* FUN_00483e30 accepts fewer animated parts than mesh parts. The
     * unanimated child still follows its parent's transformed pivot. */
    unsigned char raw[128]={0};
    word(raw+0x1c,2);word(raw+0x24,2);
    word(raw+68,1); /* hierarchy [0,1] */
    word(raw+80,1); /* root: one vertex at0 */
    word(raw+92,1);word(raw+96,1); /* child: vertex1, pivot0 */
    word(raw+108,1);word(raw+110,0x4008);word(raw+112,100);
    word(raw+114,1);word(raw+116,0x4008);word(raw+118,300);
    LL_BibVertex source[2]={{{0,0,0},0},{{10,0,0},0}}, vertices[2];
    LL_Bib3dxModel model={0};
    model.vertices=source;model.vertex_count=2;
    model.data_offsets[1]=64;model.data_sizes[1]=8;
    model.data_offsets[2]=80;model.data_sizes[2]=24;
    LL_BibAnimationRecord records[2]={{108,6,1,raw+108},{114,6,1,raw+114}};
    LL_BibAnimationTable table={0};
    table.record_type=1;table.record_count=2;table.records=records;
    LL_BibFile bib={0};bib.valid=1;bib.raw_data=raw;bib.raw_size=sizeof(raw);
    bib.model_count=1;bib.models=&model;bib.selector_count=1;bib.animations=&table;
    assert(ll_bib_build_neutral_vertices(&bib,0,vertices,2));
    assert(vertices[1].position[0]==10);
    LL_BibPackedPose evaluated;
    assert(ll_native_animation_vertices(&bib,0,0,0,1,32768,vertices,2,NULL,0,&evaluated));
    assert(vertices[0].position[0]==200 && vertices[1].position[0]==210);
    assert(evaluated.channels[3]==200);
    /* An explicit held next frame must not blend toward another sequence. */
    assert(ll_bib_build_neutral_vertices(&bib,0,vertices,2));
    assert(ll_native_animation_vertices(&bib,0,0,0,0,32768,vertices,2,NULL,0,NULL));
    assert(vertices[0].position[0]==100 && vertices[1].position[0]==110);
    assert(!ll_native_animation_vertices(&bib,0,0,0,1,65536,vertices,2,NULL,0,NULL));
    assert(!ll_native_animation_vertices(&bib,0,0,0,1,0,vertices,1,NULL,0,NULL));
    assert(!ll_native_animation_vertices(&bib,0,0,2,0,0,vertices,2,NULL,0,NULL));
    LL_BibPackedPose retained[2]={0};
    retained[0].present_groups=2;retained[0].channels[3]=100;
    retained[1].present_groups=2;retained[1].channels[3]=50;
    assert(ll_bib_build_neutral_vertices(&bib,0,vertices,2));
    assert(ll_native_model_pose_vertices(&bib,0,retained,2,vertices,2));
    assert(vertices[0].position[0]==100 && vertices[1].position[0]==160);
    retained[1].channels[3]=0; /* animation release, retained root/part basis */
    assert(ll_bib_build_neutral_vertices(&bib,0,vertices,2));
    assert(ll_native_model_pose_vertices(&bib,0,retained,2,vertices,2));
    assert(vertices[0].position[0]==100 && vertices[1].position[0]==110);
    const int16_t quarter_turn[9]={0,-4096,0,4096,0,0,0,0,4096};
    assert(ll_bib_build_neutral_vertices(&bib,0,vertices,2));
    assert(ll_native_model_pose_vertices_rooted(&bib,0,retained,2,vertices,2,quarter_turn));
    assert(vertices[0].position[0]==0 && vertices[0].position[1]==100);
    assert(vertices[1].position[0]==0 && vertices[1].position[1]==110);
    records[0].size=4;
    assert(!ll_native_animation_vertices(&bib,0,0,0,1,0,vertices,2,NULL,0,NULL));
}

static void test_loop_root(void)
{
    unsigned char raw[160]={0};
    word(raw+0x1c,2);word(raw+0x24,2);word(raw+68,1);
    word(raw+80,1);word(raw+92,1);word(raw+96,1);
    for (unsigned i=0;i<2;i++) {
        unsigned at=108+i*12;
        word(raw+at,10);word(raw+at+4,0x4038);
        word(raw+at+6,i?500:100);word(raw+at+8,i?40:20);word(raw+at+10,i?900:300);
    }
    LL_BibVertex source[2]={{{0,0,0},0},{{10,0,0},0}},vertices[2];
    LL_Bib3dxModel model={0};model.vertices=source;model.vertex_count=2;
    model.data_offsets[1]=64;model.data_sizes[1]=8;model.data_offsets[2]=80;model.data_sizes[2]=24;
    LL_BibAnimationRecord records[2]={{108,12,10,raw+108},{120,12,10,raw+120}};
    LL_BibAnimationTable table={0};table.record_type=2;table.record_count=2;table.records=records;
    table.loop_displacement[0]=1000;table.loop_displacement[2]=2000;
    LL_BibFile bib={0};bib.valid=1;bib.raw_data=raw;bib.raw_size=sizeof(raw);
    bib.model_count=1;bib.models=&model;bib.selector_count=1;bib.animations=&table;
    int16_t root[3];
    assert(ll_native_animation_root_translation(&bib,0,1,0,32768,1,root));
    assert(root[0]==800 && root[1]==30 && root[2]==1600);
    assert(ll_native_animation_root_translation(&bib,0,0,1,32768,-1,root));
    assert(root[0]==-200 && root[1]==30 && root[2]==-400);
    assert(ll_native_animation_root_translation(&bib,0,0,1,32768,0,root));
    assert(root[0]==300 && root[1]==30 && root[2]==600);
    assert(!ll_native_animation_root_translation(&bib,0,1,0,32768,2,root));
    LL_BibPackedPose poses[2];assert(ll_bib_build_neutral_vertices(&bib,0,vertices,2));
    assert(ll_native_animation_vertices_motion(&bib,0,0,1,0,32768,vertices,2,NULL,0,poses,0,1));
    assert(!poses[1].channels[3] && poses[1].channels[4]==30 && poses[1].channels[5]==1600);
    assert(vertices[1].position[0]==10 && vertices[1].position[1]==30 && vertices[1].position[2]==1600);
    assert(!ll_native_animation_vertices_motion(&bib,0,0,1,0,32768,vertices,2,NULL,0,poses,3,1));
}

int main(void)
{
    test_short_animation();
    test_loop_root();
    LL_BibPackedPose poses[3]={0};
    for (unsigned part=0;part<3;part++) {
        poses[part].flags=(uint16_t)(0x8000u+part);
        poses[part].present_groups=(uint8_t)part;
        for (unsigned channel=0;channel<9;channel++)
            poses[part].channels[channel]=(int16_t)(100*part+channel+1);
    }
    LL_BibPackedPose original[3];memcpy(original,poses,sizeof(poses));
    assert(!ll_bib_prepare_transition_pose(poses,1,&poses[0]));
    assert(!memcmp(original,poses,sizeof(poses)));
    /* Aliased source: edits must preserve the source translation first. */
    assert(ll_bib_prepare_transition_pose(poses,3,&poses[0]));
    for (unsigned axis=0;axis<3;axis++) {
        assert(poses[0].channels[axis]==0);
        assert(poses[1].channels[axis+3]==original[0].channels[axis+3]);
    }
    for (unsigned part=0;part<3;part++) {
        assert(poses[part].flags==original[part].flags);
        assert(poses[part].present_groups==original[part].present_groups);
        for (unsigned channel=0;channel<9;channel++)
            if (!(part==0 && channel<3) && !(part==1 && channel>=3 && channel<6))
                assert(poses[part].channels[channel]==original[part].channels[channel]);
    }
    assert(!ll_bib_prepare_transition_pose(NULL,3,&original[0]));
    assert(!ll_bib_prepare_transition_pose(poses,3,NULL));
    puts("BIB skeletal vertices, short animations, interpolation, transition edits and bounds: OK");
    return 0;
}
