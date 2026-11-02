/* FUN_004544b0 @ 004544b0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004544b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined1 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004f23f8 == FUN_00467660) || (DAT_004f23f8 == FUN_00467bd0)) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return CONCAT31(0xcccccc,local_8);
}

