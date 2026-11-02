/* FUN_00440e80 @ 00440e80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00440e80(short param_1,short param_2,short param_3,short param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00439af0(0x18);
  *(short *)(iVar1 + 8) = param_1;
  *(short *)(iVar1 + 10) = param_2;
  *(short *)(iVar1 + 0xc) = param_1 + param_3;
  *(short *)(iVar1 + 0xe) = param_2;
  *(short *)(iVar1 + 0x10) = param_1;
  *(short *)(iVar1 + 0x12) = param_2 + param_4;
  *(short *)(iVar1 + 0x14) = param_1 + param_3;
  *(short *)(iVar1 + 0x16) = param_2 + param_4;
  local_8 = 0x440f25;
  __chkesp();
  return;
}

