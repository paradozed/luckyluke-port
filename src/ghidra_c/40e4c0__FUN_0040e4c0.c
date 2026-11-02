/* FUN_0040e4c0 @ 0040e4c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040e4c0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_10 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  local_14 = **(int **)(local_10 + 8);
  if (*(int *)(local_14 + 0xc4) != 0) {
    if (*(char *)(*(int *)(local_14 + 0xc4) + 0x37) == '\0') {
      local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(*(int *)(local_14 + 0xc4) + 0x34));
    }
    else {
      local_c = (uint)local_c._2_2_ << 0x10;
    }
  }
  local_8 = 0x40e573;
  __chkesp();
  return;
}

