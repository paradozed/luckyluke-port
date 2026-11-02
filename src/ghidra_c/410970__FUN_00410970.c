/* FUN_00410970 @ 00410970 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410970(int param_1,void *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  undefined4 *local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (undefined4 *)FUN_00407580(param_1);
  *local_8 = FUN_0045f8a0;
  *(undefined4 *)(&DAT_004f2580 + (uint)DAT_004f2596 * 4) = local_8[2];
  uVar1 = FUN_004074b0(param_2,2);
  *(undefined2 *)(*(int *)(&DAT_004f2580 + (uint)DAT_004f2596 * 4) + 0x3c) = uVar1;
  if (DAT_004f25e0 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,3);
    *DAT_004f25e0 = uVar1;
  }
  if (DAT_004f25e4 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,4);
    *DAT_004f25e4 = uVar1;
  }
  if (DAT_004f25e8 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,5);
    *DAT_004f25e8 = uVar1;
  }
  if (DAT_004f25ec != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,6);
    *DAT_004f25ec = uVar1;
  }
  if (DAT_004f25f0 != (undefined2 *)0x0) {
    uVar1 = FUN_004074b0(param_2,7);
    *DAT_004f25f0 = uVar1;
  }
  for (local_c = 0; local_c < 5; local_c = local_c + 1) {
    if ((&DAT_004f25e0)[local_c] != (undefined2 *)0x0) {
      *(undefined2 *)((int)(&DAT_004f25e0)[local_c] + 2) = 0;
      *(undefined2 *)((int)(&DAT_004f25e0)[local_c] + 4) = 0;
      *(undefined2 *)((int)(&DAT_004f25e0)[local_c] + 6) = 0;
      *(undefined2 *)((int)(&DAT_004f25e0)[local_c] + 8) = 0;
      *(undefined2 *)((int)(&DAT_004f25e0)[local_c] + 10) = 0;
      *(undefined2 *)((int)(&DAT_004f25e0)[local_c] + 0xc) = 0;
      *(undefined2 *)((int)(&DAT_004f25e0)[local_c] + 0xe) = 0;
      *(undefined2 *)((int)(&DAT_004f25e0)[local_c] + 0x10) = 0;
    }
  }
  DAT_004f2564 = 1;
  DAT_004f2598 = FUN_0045fc80;
  local_8 = (undefined4 *)0x410b2c;
  __chkesp();
  return;
}

