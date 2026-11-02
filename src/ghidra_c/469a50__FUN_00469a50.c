/* FUN_00469a50 @ 00469a50 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00469a50(void)

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
  if ((*(uint *)(DAT_004f2458 + 0x10) & 0x20) == 0) {
    DAT_004f23f8 = FUN_00467dd0;
    FUN_00467dd0();
  }
  else {
    iVar1 = FUN_004696b0();
    if (iVar1 == 0) {
      if ((DAT_004f2438 & 0x2000) == 0) {
        if ((DAT_004f245c & 0x8000) != 0) {
          DAT_004f23f8 = FUN_00466900;
          FUN_00466900();
        }
      }
      else {
        DAT_004f23f8 = FUN_00467f60;
        FUN_00467f60();
      }
    }
    else {
      DAT_004f23f8 = FUN_00466cf0;
      FUN_00466cf0();
    }
  }
  uStack_8 = 0x469af3;
  __chkesp();
  return;
}

