/* FUN_004118b0 @ 004118b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004118b0(undefined4 param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar5 = local_44;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  sVar2 = FUN_004074b0(param_2,3);
  (&DAT_004f16e0)[sVar2] = *(undefined4 *)(&DAT_004f1e40 + sVar1 * 4);
  uVar3 = FUN_004074b0(param_2,4);
  sVar1 = FUN_004074b0(param_2,3);
  *(undefined2 *)(*(int *)((&DAT_004f16e0)[sVar1] + 8) + 0x14) = uVar3;
  uStack_8 = 0x411925;
  __chkesp();
  return;
}

