/* FUN_0040f890 @ 0040f890 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0040f890(void)

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
  if (DAT_004d1e48 != 0) {
    (*DAT_004e8a2c)(10,400,"Speed X: %d",*(undefined4 *)(DAT_004d1e48 + 4));
    __chkesp();
    (*DAT_004e8a2c)(10,0x19a,"Speed Y: %d",*(undefined4 *)(DAT_004d1e48 + 8));
    __chkesp();
    (*DAT_004e8a2c)(10,0x1a4,"Speed Z: %d",*(undefined4 *)(DAT_004d1e48 + 0xc));
    __chkesp();
    (*DAT_004e8a2c)(10,0x1ae,"Dead:    %d",(int)*(short *)(DAT_004d1e48 + 0x14));
    __chkesp();
    (*DAT_004e8a2c)(10,0x1b8,"State:   %d",*(undefined4 *)(DAT_004d1e48 + 0x10));
    __chkesp();
    (*DAT_004e8a2c)(10,0x1c2,"Sense:   %d",*(undefined1 *)(DAT_004d1e48 + 0x16));
    __chkesp();
  }
  uStack_8 = 0x40f9b3;
  __chkesp();
  return;
}

