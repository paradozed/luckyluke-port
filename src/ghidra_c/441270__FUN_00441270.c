/* FUN_00441270 @ 00441270 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00441270(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [17];
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_00440e80(0,0,(short)DAT_004be3c8,(short)DAT_004be3cc);
  *(undefined1 *)(local_8 + 4) = param_1;
  *(undefined1 *)(local_8 + 5) = param_2;
  *(undefined1 *)(local_8 + 6) = param_3;
  (*DAT_004e8a30)();
  __chkesp();
  (*DAT_004e8a44)(local_8,0,0,0,0);
  __chkesp();
  (*DAT_004e8a0c)();
  __chkesp();
  local_8 = 0x44130a;
  __chkesp();
  return;
}

