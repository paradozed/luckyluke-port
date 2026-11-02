/* FUN_004162d0 @ 004162d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004162d0(int param_1,void *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_60 [16];
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_60;
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_c = **(int **)(local_8 + 8);
  uVar1 = FUN_004074b0(param_2,2);
  local_10 = FUN_00456c10(DAT_004f2b3c,uVar1);
  if (local_10 != 0) {
    *(undefined4 *)(local_10 + 0x18) = *(undefined4 *)(local_8 + 8);
    *(uint *)(*(int *)(local_8 + 8) + 0x10) = *(uint *)(*(int *)(local_8 + 8) + 0x10) | 0x20;
    local_20 = *(int *)(local_c + 0x90);
    local_1c = *(undefined4 *)(local_c + 0x94);
    local_18 = *(undefined4 *)(local_c + 0x98);
    FUN_00457740(local_c,local_10,&local_20);
    *(code **)(local_10 + 4) = FUN_00457180;
    *(int *)(local_c + 0xe4) = local_10;
  }
  local_8 = 0x41639d;
  __chkesp();
  return;
}

