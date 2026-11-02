/* FUN_00409ae0 @ 00409ae0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00409ae0(int param_1)

{
  short sVar1;
  void *this;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_850 [16];
  int local_810;
  int local_80c;
  int local_808;
  int local_804;
  int local_800 [250];
  int local_418 [250];
  uint local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  puVar3 = local_850;
  for (iVar2 = 0x213; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_2c = 0x80;
  local_30 = local_30 & 0xffffff00;
  local_804 = FUN_00407580(param_1);
  local_808 = **(int **)(local_804 + 8);
  local_28 = *(int *)(local_808 + 0x90);
  local_24 = *(undefined4 *)(local_808 + 0x94);
  local_20 = *(undefined4 *)(local_808 + 0x98);
  for (local_80c = 0; local_80c < 0xfa; local_80c = local_80c + 1) {
    if (((local_808 != **(int **)(*(int *)(&DAT_004f1e40 + local_80c * 4) + 8)) &&
        (*(int *)(&DAT_004f1e40 + local_80c * 4) != 0)) &&
       (sVar1 = FUN_00407700(local_808,**(int **)(*(int *)(&DAT_004f1e40 + local_80c * 4) + 8),
                             local_2c), sVar1 != 0)) {
      local_418[local_30 & 0xff] = *(int *)(&DAT_004f1e40 + local_80c * 4);
      local_18 = *(int *)(**(int **)(local_418[local_30 & 0xff] + 8) + 0x90);
      local_14 = *(undefined4 *)(**(int **)(local_418[local_30 & 0xff] + 8) + 0x94);
      local_10 = *(undefined4 *)(**(int **)(local_418[local_30 & 0xff] + 8) + 0x98);
      if (local_28 - local_18 < 0) {
        local_810 = -(local_28 - local_18);
      }
      else {
        local_810 = local_28 - local_18;
      }
      local_800[local_30 & 0xff] = local_810;
      local_30 = CONCAT31(local_30._1_3_,(char)local_30 + '\x01');
    }
  }
  if ((local_30 & 0xff) != 0) {
    iVar2 = FUN_00409d30((int)local_800,(int)local_418,(char)local_30);
    local_8 = iVar2;
    this = (void *)FUN_00409d00(param_1);
    FUN_00421ea0(this,iVar2);
  }
  local_8 = 0x409cf5;
  __chkesp();
  return;
}

