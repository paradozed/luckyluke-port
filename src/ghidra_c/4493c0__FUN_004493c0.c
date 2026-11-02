/* FUN_004493c0 @ 004493c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004493c0(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [19];
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_00440e80(0,0,(short)DAT_004be3c8 + -1,(short)DAT_004be3cc + -1);
  *(undefined1 *)(local_8 + 4) = param_1;
  *(undefined1 *)(local_8 + 5) = param_2;
  *(undefined1 *)(local_8 + 6) = param_3;
  (*DAT_004e8a30)();
  __chkesp();
  (*DAT_004e8a44)(local_8,0,0,0,0);
  __chkesp();
  FUN_00449380();
  local_8 = 0x449454;
  __chkesp();
  return;
}

