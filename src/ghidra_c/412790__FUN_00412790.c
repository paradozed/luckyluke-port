/* FUN_00412790 @ 00412790 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00412790(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [16];
  undefined2 local_c;
  undefined4 local_8;
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_004074b0(param_2,3);
  local_8 = CONCAT22(local_8._2_2_,uVar1);
  local_c = FUN_004074b0(param_2,4);
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x1c + sVar2 * 0x20) = (undefined2)local_8;
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x1e + sVar2 * 0x20) = local_c;
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12 + sVar2 * 0x20) = 10;
  sVar2 = FUN_004074b0(param_2,2);
  *(undefined1 *)(*(int *)(DAT_004f1578 + 4) + 0x1a + sVar2 * 0x20) = 0;
  DAT_004f2594 = 0;
  DAT_004f2564 = 0;
  local_8 = 0x412860;
  __chkesp();
  return;
}

