/* FUN_00411280 @ 00411280 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411280(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_004714a0(DAT_004f1e24);
  uVar1 = FUN_004074b0(param_2,2);
  *(undefined2 *)(local_8 + 0xc) = uVar1;
  *(undefined1 *)(local_8 + 0x11) = 1;
  *(undefined1 *)(local_8 + 0x10) = 1;
  *(undefined4 *)(local_8 + 8) = 0;
  local_8 = 0x4112df;
  __chkesp();
  return;
}

