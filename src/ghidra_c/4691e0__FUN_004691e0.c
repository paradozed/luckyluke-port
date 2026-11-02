/* FUN_004691e0 @ 004691e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004691e0(void)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_58 [16];
  short local_18;
  undefined4 uStack_8;
  
  puVar4 = local_58;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18 = FUN_00467130(*DAT_004f2458);
  if ((DAT_004f245c & 0x8000) == 0) {
    if ((DAT_004f2458[4] & 4U) != 0) {
      iVar3 = FUN_004696b0();
      sVar1 = local_18;
      if (iVar3 == 1) {
        sVar2 = FUN_00467130(*DAT_004f2458);
        if (sVar1 == sVar2) {
          if ((DAT_004f2458[4] & 0x20U) == 0) {
            DAT_004f23f8 = FUN_00467dd0;
            FUN_00467dd0();
          }
          goto LAB_004692b7;
        }
      }
    }
    DAT_004f2458[4] = DAT_004f2458[4] & 0xfffffffb;
    DAT_004f23f8 = FUN_00466900;
    FUN_00466900();
  }
  else {
    DAT_004f2458[0x2b] = 0;
    DAT_004f23f8 = FUN_00466900;
    FUN_00466900();
  }
LAB_004692b7:
  uStack_8 = 0x4692c4;
  __chkesp();
  return;
}

