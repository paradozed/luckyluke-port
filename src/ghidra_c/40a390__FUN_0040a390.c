/* FUN_0040a390 @ 0040a390 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040a390(int param_1)

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
  int local_800;
  int local_7fc [250];
  int local_414 [250];
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
  local_2c = local_2c & 0xffffff00;
  local_800 = FUN_00407580(param_1);
  local_804 = **(int **)(local_800 + 8);
  local_28 = *(int *)(local_804 + 0x90);
  local_24 = *(undefined4 *)(local_804 + 0x94);
  local_20 = *(undefined4 *)(local_804 + 0x98);
  for (local_808 = 0; local_808 < (int)(uint)*(ushort *)(DAT_004f1e24 + 4);
      local_808 = local_808 + 1) {
    if ((((*(int *)(&DAT_004f1e40 + local_808 * 4) != 0) &&
         (local_80c = *(int *)(*(int *)(&DAT_004f1e40 + local_808 * 4) + 8), local_80c != 0)) &&
        ((*(ushort *)(*(int *)(&DAT_004f1e40 + local_808 * 4) + 0xe) & 4) != 0)) &&
       (sVar1 = FUN_00409ee0(local_804,**(int **)(*(int *)(&DAT_004f1e40 + local_808 * 4) + 8)),
       sVar1 != 0)) {
      local_414[local_2c & 0xff] = *(int *)(&DAT_004f1e40 + local_808 * 4);
      local_18 = *(int *)(**(int **)(local_414[local_2c & 0xff] + 8) + 0x90);
      local_14 = *(undefined4 *)(**(int **)(local_414[local_2c & 0xff] + 8) + 0x94);
      local_10 = *(undefined4 *)(**(int **)(local_414[local_2c & 0xff] + 8) + 0x98);
      if (local_28 - local_18 < 0) {
        local_810 = -(local_28 - local_18);
      }
      else {
        local_810 = local_28 - local_18;
      }
      local_7fc[local_2c & 0xff] = local_810;
      local_2c = CONCAT31(local_2c._1_3_,(char)local_2c + '\x01');
    }
  }
  if ((local_2c & 0xff) != 0) {
    iVar2 = FUN_00409d30((int)local_7fc,(int)local_414,(char)local_2c);
    local_8 = iVar2;
    this = (void *)FUN_00409d00(param_1);
    FUN_00421ea0(this,iVar2);
  }
  local_8 = 0x40a5c3;
  __chkesp();
  return;
}

