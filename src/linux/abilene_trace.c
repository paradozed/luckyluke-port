#include "level_script.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

static unsigned char *read_file(const char *path, size_t *size)
{
    FILE *file=fopen(path,"rb");long length;
    if (!file) { fprintf(stderr,"ERROR: cannot open %s: %s\n",path,strerror(errno));return NULL; }
    if (fseek(file,0,SEEK_END) || (length=ftell(file))<=0 || length>64*1024*1024 ||
        fseek(file,0,SEEK_SET)) {
        fprintf(stderr,"ERROR: %s is empty, unreadable or larger than64 MiB\n",path);
        fclose(file);return NULL;
    }
    unsigned char *data=malloc((size_t)length);
    if (!data || fread(data,1,(size_t)length,file)!=(size_t)length) {
        fprintf(stderr,"ERROR: cannot allocate/read %s\n",path);free(data);fclose(file);return NULL;
    }
    fclose(file);*size=(size_t)length;return data;
}

int main(int argc, char **argv)
{
    if (argc<3 || argc>5) {
        fprintf(stderr,"usage: abilene-trace abilene.cod abilene.bib [updates=24] [abilene.biz]\n       abilene-trace abilene.cod abilene.bib abilene.biz [updates=24]\n");return 2;
    }
    unsigned long updates=24;
    int biz_index=0;
    const char *updates_arg=NULL;
    if (argc==4) {
        char *end;errno=0;(void)strtoul(argv[3],&end,10);
        if (!errno && argv[3][0] && !*end) updates_arg=argv[3];
        else biz_index=3;
    } else if (argc==5) {
        char *end;errno=0;(void)strtoul(argv[3],&end,10);
        if (!errno && argv[3][0] && !*end) { updates_arg=argv[3];biz_index=4; }
        else { biz_index=3;updates_arg=argv[4]; }
    }
    if (updates_arg) {
        char *end;errno=0;updates=strtoul(updates_arg,&end,10);
        if (errno || !updates_arg[0] || *end || updates<1 || updates>10000) {
            fprintf(stderr,"ERROR: updates must be an integer1..10000\n");return 2;
        }
    }
    size_t code_size=0,bib_size=0,biz_size=0;
    unsigned char *code=read_file(argv[1],&code_size),*bib=read_file(argv[2],&bib_size);
    unsigned char *biz=biz_index?read_file(argv[biz_index],&biz_size):NULL;
    if (!code || !bib || (biz_index && !biz)) { free(code);free(bib);free(biz);return 2; }
    LL_LevelScript script={0};
    int ok=ll_level_script_open(&script,code,code_size,bib,bib_size,stdout);
    free(code);free(bib);
    if (!ok) {
        fprintf(stderr,"ERROR: %s\n",script.error);ll_level_script_close(&script);return 2;
    }
    if (biz && !ll_level_script_set_biz(&script,biz,biz_size)) {
        fprintf(stderr,"ERROR: %s\n",script.error);free(biz);
        ll_level_script_close(&script);return 2;
    }
    free(biz);
    unsigned conditions=0,virtuals=0;
    for (unsigned i=0;i<script.program.function_count;i++) {
        conditions+=script.program.functions[i].conditions_start!=UINT16_MAX;
        virtuals+=script.program.functions[i].virtual_count!=0;
    }
    printf("ABILENE directory: functions=%u condition_streams=%u virtual_tables=%u models=%u\n",
        script.program.function_count,conditions,virtuals,script.bib.model_count);
    for (unsigned long i=0;i<updates;i++) ll_level_script_update(&script);
    ll_level_script_report(&script,stdout);
    printf("ABILENE setup: initialized=%u projection=%u cell=%d camera_mode=%d speed=%d bounds=[%d,%d,%d,%d] word=%u limit=%u\n",
        script.native.initialized,script.native.projection,script.native.world_cell,
        script.native.camera_mode,script.native.camera_speed,script.native.camera_bounds[0],
        script.native.camera_bounds[1],script.native.camera_bounds[2],script.native.camera_bounds[3],
        script.native.camera_word,script.native.camera_limit);
    int result=script.blocked_count?3:0;
    ll_level_script_close(&script);return result;
}
