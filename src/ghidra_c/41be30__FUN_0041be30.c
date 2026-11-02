/* FUN_0041be30 @ 0041be30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041be30(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_50 [16];
  int local_10;
  ushort *local_c;
  int local_8;
  
  puVar6 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  if (local_8 != 0) {
    local_c = *(ushort **)(local_8 + 8);
    for (local_10 = 0; local_10 < (int)(uint)*local_c; local_10 = local_10 + 1) {
      iVar3 = local_10 * 0x20;
      iVar2 = *(int *)(local_c + 8);
      sVar1 = FUN_004074b0(param_2,5);
      iVar3 = *(int *)(iVar2 + 0x14 + iVar3) + (int)sVar1;
      iVar4 = local_10 * 0x20;
      iVar2 = *(int *)(local_c + 8);
      sVar1 = FUN_004074b0(param_2,4);
      iVar4 = *(int *)(iVar2 + 0x10 + iVar4) + (int)sVar1;
      iVar5 = local_10 * 0x20;
      iVar2 = *(int *)(local_c + 8);
      sVar1 = FUN_004074b0(param_2,3);
      FUN_0041bd70(*(int *)(*(int *)(local_c + 8) + local_10 * 0x20),
                   *(int *)(iVar2 + 0xc + iVar5) + (int)sVar1,iVar4,iVar3);
    }
  }
  local_8 = 0x41bf1c;
  __chkesp();
  return;
}

