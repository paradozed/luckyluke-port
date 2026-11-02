/* FUN_00411040 @ 00411040 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411040(undefined4 param_1,void *param_2)

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
  *(undefined2 *)(&DAT_004e87a8 + sVar2 * 0x14) = uVar1;
  uVar1 = FUN_004074b0(param_2,4);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)(&DAT_004e87aa + sVar2 * 0x14) = uVar1;
  uVar1 = FUN_004074b0(param_2,5);
  sVar2 = FUN_004074b0(param_2,2);
  (&DAT_004e87ac)[sVar2 * 10] = uVar1;
  uVar1 = FUN_004074b0(param_2,6);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)(&DAT_004e87ae + sVar2 * 0x14) = uVar1;
  uVar1 = FUN_004074b0(param_2,7);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)(&DAT_004e87b0 + sVar2 * 0x14) = uVar1;
  uVar1 = FUN_004074b0(param_2,8);
  sVar2 = FUN_004074b0(param_2,2);
  (&DAT_004e87b2)[sVar2 * 10] = uVar1;
  uVar1 = FUN_004074b0(param_2,9);
  sVar2 = FUN_004074b0(param_2,2);
  (&DAT_004e87b4)[sVar2 * 10] = uVar1;
  uVar1 = FUN_004074b0(param_2,10);
  sVar2 = FUN_004074b0(param_2,2);
  (&DAT_004e87b6)[sVar2 * 10] = uVar1;
  uStack_8 = 0x411185;
  __chkesp();
  return;
}

