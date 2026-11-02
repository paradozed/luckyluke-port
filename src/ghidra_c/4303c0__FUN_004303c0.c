/* FUN_004303c0 @ 004303c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004303c0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  undefined1 local_c;
  int local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004e8478 != 0) {
    FUN_0042fd30();
    FUN_004300e0();
    (*DAT_004e8a6c)(0);
    uVar1 = __chkesp();
    local_c = (undefined1)uVar1;
    for (local_8 = 0; local_8 < 1; local_8 = local_8 + 1) {
      (*DAT_004e8a30)();
      __chkesp();
      (*DAT_004e8a6c)(*(undefined1 *)(DAT_004f6128 + local_8));
      __chkesp();
      (*DAT_004e8a54)(DAT_004f6124 + local_8 * 0x28,0x11,0x11,0x11,0x11);
      __chkesp();
    }
    (*DAT_004e8a6c)(local_c);
    __chkesp();
  }
  local_8 = 0x430499;
  __chkesp();
  return;
}

