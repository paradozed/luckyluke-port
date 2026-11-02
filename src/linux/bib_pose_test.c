#include "bib.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
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
    puts("BIB transition root edits, aliasing, preserved channels and bounds: OK");
    return 0;
}
