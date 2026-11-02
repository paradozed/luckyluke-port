/* FUN_00410b30 @ 00410b30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410b30(undefined4 param_1,void *param_2)

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
  if (DAT_004f25a0 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,2);
    *DAT_004f25a0 = uVar1;
  }
  if (DAT_004f25a4 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,3);
    *DAT_004f25a4 = uVar1;
  }
  if (DAT_004f25a8 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,4);
    *DAT_004f25a8 = uVar1;
  }
  if (DAT_004f25ac != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,5);
    *DAT_004f25ac = uVar1;
  }
  if (DAT_004f25b0 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,6);
    *DAT_004f25b0 = uVar1;
  }
  if (DAT_004f25b4 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,7);
    *DAT_004f25b4 = uVar1;
  }
  if (DAT_004f25b8 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,8);
    *DAT_004f25b8 = uVar1;
  }
  if (DAT_004f25bc != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,9);
    *DAT_004f25bc = uVar1;
  }
  if (DAT_004f25c0 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,10);
    *DAT_004f25c0 = uVar1;
  }
  for (local_8 = 0; local_8 < 9; local_8 = local_8 + 1) {
    if ((&DAT_004f25a0)[local_8] != (undefined2 *)0x0) {
      *(undefined2 *)((int)(&DAT_004f25a0)[local_8] + 2) = 0;
      *(undefined2 *)((int)(&DAT_004f25a0)[local_8] + 4) = 0;
      *(undefined2 *)((int)(&DAT_004f25a0)[local_8] + 6) = 0;
      *(undefined2 *)((int)(&DAT_004f25a0)[local_8] + 8) = 0;
      *(undefined2 *)((int)(&DAT_004f25a0)[local_8] + 10) = 0;
      *(undefined2 *)((int)(&DAT_004f25a0)[local_8] + 0xc) = 0;
      *(undefined2 *)((int)(&DAT_004f25a0)[local_8] + 0xe) = 0;
      *(undefined2 *)((int)(&DAT_004f25a0)[local_8] + 0x10) = 0;
    }
  }
  local_8 = 0x410d03;
  __chkesp();
  return;
}

