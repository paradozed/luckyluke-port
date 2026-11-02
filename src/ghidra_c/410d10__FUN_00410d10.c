/* FUN_00410d10 @ 00410d10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410d10(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_004074b0(param_2,3);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)((&DAT_004f25e0)[sVar2] + 2) = uVar1;
  uVar1 = FUN_004074b0(param_2,4);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)((&DAT_004f25e0)[sVar2] + 4) = uVar1;
  uVar1 = FUN_004074b0(param_2,5);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)((&DAT_004f25e0)[sVar2] + 6) = uVar1;
  uVar1 = FUN_004074b0(param_2,6);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)((&DAT_004f25e0)[sVar2] + 8) = uVar1;
  uVar1 = FUN_004074b0(param_2,7);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)((&DAT_004f25e0)[sVar2] + 10) = uVar1;
  uVar1 = FUN_004074b0(param_2,8);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)((&DAT_004f25e0)[sVar2] + 0xc) = uVar1;
  uStack_8 = 0x410e13;
  __chkesp();
  return;
}

