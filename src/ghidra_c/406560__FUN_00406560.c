/* FUN_00406560 @ 00406560 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00406560(void)

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
  FUN_0045f3e0();
  FUN_004454d0();
  if ((*DAT_004e8310 & 4) != 0) {
    iVar1 = FUN_004064e0();
    if (iVar1 == 0) {
      (*DAT_004e8a10)(0);
      __chkesp();
      (*DAT_00508a00)(DAT_004e8310[4],DAT_004e8310[5],DAT_004e8310[6],DAT_004e8310[1],
                      DAT_004e8310[2],DAT_004e8310[3]);
      __chkesp();
      goto LAB_0040660f;
    }
  }
  (*DAT_004e8a10)(1);
  __chkesp();
LAB_0040660f:
  FUN_00441340();
  if (DAT_004bdcf0 == 2) {
    if ((DAT_004f598b != '\0') && (0 < DAT_004d1dd8)) {
      DAT_004d1dd8 = DAT_004d1dd8 + -1;
    }
    if ((DAT_004f598d != '\0') && (DAT_004d1dd8 < 0xf)) {
      DAT_004d1dd8 = DAT_004d1dd8 + 1;
    }
    FUN_004441c0((short)DAT_004d1dd8);
  }
  FUN_00478400();
  FUN_0041ea10();
  uStack_8 = 0x406688;
  __chkesp();
  return;
}

