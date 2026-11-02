/* FUN_00467ec0 @ 00467ec0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00467ec0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004f2438 & 0x2000) == 0) {
    DAT_004f23f8 = FUN_004680e0;
  }
  else {
    DAT_004f23f8 = FUN_004682f0;
  }
  return;
}

