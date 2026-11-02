/* FUN_00410f50 @ 00410f50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410f50(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_004074b0(param_2,2);
  *(undefined2 *)(DAT_004f25a0 + 0x10) = uVar1;
  uVar1 = FUN_004074b0(param_2,3);
  *(undefined2 *)(DAT_004f25a4 + 0x10) = uVar1;
  uVar1 = FUN_004074b0(param_2,4);
  *(undefined2 *)(DAT_004f25a8 + 0x10) = uVar1;
  uVar1 = FUN_004074b0(param_2,5);
  *(undefined2 *)(DAT_004f25ac + 0x10) = uVar1;
  uVar1 = FUN_004074b0(param_2,6);
  *(undefined2 *)(DAT_004f25b0 + 0x10) = uVar1;
  uVar1 = FUN_004074b0(param_2,7);
  *(undefined2 *)(DAT_004f25b4 + 0x10) = uVar1;
  uStack_8 = 0x410fed;
  __chkesp();
  return;
}

