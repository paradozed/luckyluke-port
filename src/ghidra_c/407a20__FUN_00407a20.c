/* FUN_00407a20 @ 00407a20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00407a20(int param_1,void *param_2)

{
  short sVar1;
  void *this;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_58 [16];
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_c = (uint)sVar1;
  local_10 = FUN_00407580(param_1);
  local_14 = **(int **)(local_10 + 8);
  local_18 = 0;
  do {
    if (0xf9 < local_18) {
LAB_00407ae9:
      local_8 = 0x407af6;
      __chkesp();
      return;
    }
    if (((local_14 != **(int **)(*(int *)(&DAT_004f1e40 + local_18 * 4) + 8)) &&
        (*(int *)(&DAT_004f1e40 + local_18 * 4) != 0)) &&
       (sVar1 = FUN_00407700(local_14,**(int **)(*(int *)(&DAT_004f1e40 + local_18 * 4) + 8),local_c
                            ), sVar1 != 0)) {
      iVar2 = *(int *)(&DAT_004f1e40 + local_18 * 4);
      local_8 = iVar2;
      this = (void *)FUN_00409d00(param_1);
      FUN_00421ea0(this,iVar2);
      goto LAB_00407ae9;
    }
    local_18 = local_18 + 1;
  } while( true );
}

