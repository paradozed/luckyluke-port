/* FUN_00410e20 @ 00410e20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410e20(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  if ((&DAT_004f25a0)[sVar1] != 0) {
    uVar2 = FUN_004074b0(param_2,3);
    sVar1 = FUN_004074b0(param_2,2);
    *(undefined2 *)((&DAT_004f25a0)[sVar1] + 2) = uVar2;
    uVar2 = FUN_004074b0(param_2,4);
    sVar1 = FUN_004074b0(param_2,2);
    *(undefined2 *)((&DAT_004f25a0)[sVar1] + 4) = uVar2;
    uVar2 = FUN_004074b0(param_2,5);
    sVar1 = FUN_004074b0(param_2,2);
    *(undefined2 *)((&DAT_004f25a0)[sVar1] + 6) = uVar2;
    uVar2 = FUN_004074b0(param_2,6);
    sVar1 = FUN_004074b0(param_2,2);
    *(undefined2 *)((&DAT_004f25a0)[sVar1] + 8) = uVar2;
    uVar2 = FUN_004074b0(param_2,7);
    sVar1 = FUN_004074b0(param_2,2);
    *(undefined2 *)((&DAT_004f25a0)[sVar1] + 10) = uVar2;
    uVar2 = FUN_004074b0(param_2,8);
    sVar1 = FUN_004074b0(param_2,2);
    *(undefined2 *)((&DAT_004f25a0)[sVar1] + 0xc) = uVar2;
  }
  uStack_8 = 0x410f3e;
  __chkesp();
  return;
}

