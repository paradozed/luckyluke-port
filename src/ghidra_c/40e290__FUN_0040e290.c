/* FUN_0040e290 @ 0040e290 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040e290(int param_1,void *param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 local_7c [16];
  int *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int local_24;
  int local_1c;
  int local_18;
  int local_c;
  undefined4 uStack_8;
  
  puVar4 = local_7c;
  for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  iVar3 = FUN_00407580(param_1);
  local_38 = *(int **)(iVar3 + 8);
  sVar1 = FUN_004074b0(param_2,3);
  local_3c = *(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  piVar5 = &local_1c;
  sVar1 = FUN_004074b0(param_2,2);
  FUN_0040da10(local_38,(int)sVar1,piVar5);
  piVar5 = &local_34;
  sVar1 = FUN_004074b0(param_2,4);
  FUN_0040da10(local_3c,(int)sVar1,piVar5);
  uVar2 = FUN_0040d810(&local_1c,&local_34);
  if ((short)uVar2 != 0) {
    if ((local_30 < local_c) && (local_c < local_24)) {
      *(int *)(*local_3c + 0x94) = *(int *)(*local_3c + 0x94) + (local_c - local_30);
    }
    else if ((local_18 < local_24) && (local_30 < local_18)) {
      *(int *)(*local_3c + 0x94) = *(int *)(*local_3c + 0x94) - (local_24 - local_18);
    }
  }
  uStack_8 = 0x40e3a0;
  __chkesp();
  return;
}

