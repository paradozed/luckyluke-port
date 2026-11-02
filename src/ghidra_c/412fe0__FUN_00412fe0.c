/* FUN_00412fe0 @ 00412fe0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00412fe0(int param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_50 [16];
  undefined2 local_10;
  int local_c;
  int local_8;
  
  puVar5 = local_50;
  for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_8 = FUN_00407580(param_1);
  sVar1 = FUN_004074b0(param_2,2);
  local_c = FUN_0046e8d0((int)sVar1);
  local_10 = *(undefined2 *)(*(int *)(**(int **)(local_8 + 8) + 0xcc) + 0x14);
  uVar3 = CONCAT22((short)((uint)**(int **)(local_8 + 8) >> 0x10),local_10);
  sVar1 = FUN_004074b0(param_2,3);
  sVar2 = FUN_004074b0(param_2,3);
  FUN_004856f0((byte *)**(undefined4 **)(local_8 + 8),local_c,sVar2,sVar1,uVar3);
  local_8 = 0x41306f;
  __chkesp();
  return;
}

