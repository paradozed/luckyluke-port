/* FUN_00465320 @ 00465320 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00465320(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  cVar1 = FUN_00465280();
  if (cVar1 == '\0') goto LAB_00465397;
  local_8 = (uint)DAT_004e881a;
  if (local_8 != 2) {
    if (local_8 != 4) goto LAB_00465397;
    if (DAT_004f23f8 != FUN_00463660) {
      DAT_004f2598 = FUN_00463610;
      FUN_00463610();
      goto LAB_00465397;
    }
  }
  if (DAT_004f23f8 != FUN_004639e0) {
    DAT_004f2598 = FUN_00463820;
    FUN_00463820();
  }
LAB_00465397:
  local_8 = 0x4653a4;
  __chkesp();
  return;
}

