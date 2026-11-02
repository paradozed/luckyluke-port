/* FUN_004125d0 @ 004125d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004125d0(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_50 [16];
  int local_10;
  ushort *local_c;
  int local_8;
  
  puVar4 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_c = *(ushort **)(local_8 + 8);
  for (local_10 = 0; local_10 < (int)(uint)*local_c; local_10 = local_10 + 1) {
    iVar3 = local_10 * 0x20;
    iVar2 = *(int *)(local_c + 8);
    sVar1 = FUN_004074b0(param_2,2);
    *(int *)(*(int *)(local_c + 8) + 0xc + local_10 * 0x20) =
         *(int *)(iVar2 + 0xc + iVar3) + (int)sVar1;
    iVar3 = local_10 * 0x20;
    iVar2 = *(int *)(local_c + 8);
    sVar1 = FUN_004074b0(param_2,3);
    *(int *)(*(int *)(local_c + 8) + 0x10 + local_10 * 0x20) =
         *(int *)(iVar2 + 0x10 + iVar3) + (int)sVar1;
    iVar3 = local_10 * 0x20;
    iVar2 = *(int *)(local_c + 8);
    sVar1 = FUN_004074b0(param_2,4);
    *(int *)(*(int *)(local_c + 8) + 0x14 + local_10 * 0x20) =
         *(int *)(iVar2 + 0x14 + iVar3) + (int)sVar1;
  }
  local_8 = 0x4126be;
  __chkesp();
  return;
}

