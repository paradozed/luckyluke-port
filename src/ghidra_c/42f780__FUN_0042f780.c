/* FUN_0042f780 @ 0042f780 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042f780(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004e8468 != (byte *)0x0) && (DAT_004e846c != 0)) {
    if ((*DAT_004e8468 & 2) == 0) {
      FUN_0047f2d0(DAT_004e8468);
    }
    else {
      FUN_0047f140(DAT_004e8468);
    }
  }
  uStack_8 = 0x42f7e8;
  __chkesp();
  return;
}

