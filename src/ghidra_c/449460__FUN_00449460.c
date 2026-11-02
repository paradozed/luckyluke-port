/* FUN_00449460 @ 00449460 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00449460(char param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_00440e80(0,0,(short)DAT_004be3c8,(short)DAT_004be3cc);
  *(undefined1 *)(local_8 + 4) = param_2;
  *(undefined1 *)(local_8 + 5) = param_3;
  *(undefined1 *)(local_8 + 6) = param_4;
  if (param_1 != '\0') {
    *(byte *)(local_8 + 7) = *(byte *)(local_8 + 7) | 2;
  }
  (*DAT_004e8a30)();
  __chkesp();
  (*DAT_004e8a44)(local_8,0,0,0,0);
  __chkesp();
  local_8 = 0x449509;
  __chkesp();
  return;
}

