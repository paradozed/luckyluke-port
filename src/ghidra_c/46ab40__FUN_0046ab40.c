/* FUN_0046ab40 @ 0046ab40 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ab40(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_0046a6e0(DAT_004f2458 + 0x2d,DAT_004f2458 + 0x2e,(int *)&DAT_004be0b0);
  local_14 = *(undefined4 *)(*DAT_004f2458 + 0x90);
  local_c = *(undefined4 *)(*DAT_004f2458 + 0x98);
  local_10 = *(int *)(*DAT_004f2458 + 0x94) + DAT_004f2458[0x2e];
  FUN_00467730(*DAT_004f2458,local_14,local_10,local_c);
  *(short *)(DAT_004f2458 + 0x2a) = (short)DAT_004f2458[0x2a] + _DAT_004e8834;
  if ((DAT_004f2458[4] & 0x20U) != 0) {
    *(undefined2 *)(DAT_004f2458 + 0x2a) = 0;
    DAT_004f23f8 = FUN_0046b040;
    FUN_0046b040();
  }
  if ((short)DAT_004f2458[0x2a] < 0) {
    local_18 = -(int)(short)DAT_004f2458[0x2a];
  }
  else {
    local_18 = (int)(short)DAT_004f2458[0x2a];
  }
  if (0x200 < local_18) {
    DAT_004f2458[4] = DAT_004f2458[4] | 0x100;
  }
  uStack_8 = 0x46ac8a;
  __chkesp();
  return;
}

