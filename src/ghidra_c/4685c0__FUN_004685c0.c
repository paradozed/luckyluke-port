/* FUN_004685c0 @ 004685c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004685c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = *(undefined4 *)(*DAT_004f2458 + 0x90);
  local_14 = *(undefined4 *)(*DAT_004f2458 + 0x94);
  local_10 = *(undefined4 *)(*DAT_004f2458 + 0x98);
  iVar1 = (int)(DAT_004f2438 & 0xf0) >> 4;
  local_8 = CONCAT22(local_8._2_2_,(short)iVar1);
  if (iVar1 != 0) {
    DAT_004f23f8 = FUN_00468750;
    FUN_00468750();
  }
  local_8 = 0x468645;
  __chkesp();
  return;
}

