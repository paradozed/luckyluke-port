/* FUN_00462060 @ 00462060 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00462060(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_80 [16];
  uint local_40;
  int *local_3c;
  int *local_38;
  int local_34 [6];
  int local_1c [5];
  undefined4 uStack_8;
  
  puVar2 = local_80;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_38 = *(int **)(DAT_004f2458[0x27] + 8);
  local_3c = *(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4);
  FUN_00464fc0(local_3c,(uint)DAT_004e8816,local_1c);
  FUN_00465130(local_38,(uint)DAT_004e8814,local_34);
  local_40 = (uint)DAT_004e8814;
  switch(local_40) {
  case 0:
    if (*(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32) < 3) {
      FUN_0040d810(local_1c,local_34);
    }
    break;
  case 1:
    if (*(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32) < 4) {
      FUN_0040d810(local_1c,local_34);
    }
    break;
  case 2:
    if ((1 < *(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32)) &&
       (*(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32) < 5)) {
      FUN_0040d810(local_1c,local_34);
    }
    break;
  case 3:
    if ((1 < *(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32)) &&
       (*(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32) < 5)) {
      FUN_0040d810(local_1c,local_34);
    }
    break;
  case 4:
    if ((3 < *(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32)) &&
       (*(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32) < 6)) {
      FUN_0040d810(local_1c,local_34);
    }
    break;
  case 5:
    if ((2 < *(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32)) &&
       (*(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32) < 5)) {
      FUN_0040d810(local_1c,local_34);
    }
  }
  uStack_8 = 0x462282;
  __chkesp();
  return;
}

