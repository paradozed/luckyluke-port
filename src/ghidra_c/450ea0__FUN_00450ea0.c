/* FUN_00450ea0 @ 00450ea0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00450ea0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [19];
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_14);
  local_14 = local_14 + _DAT_004f2b40;
  local_10 = local_10 + _DAT_004f2b44;
  local_c = param_1[2];
  FUN_00482fb0(&local_14,param_2,param_3);
  uStack_8 = 0x450f0f;
  __chkesp();
  return;
}

