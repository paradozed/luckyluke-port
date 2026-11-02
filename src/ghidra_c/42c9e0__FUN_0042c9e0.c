/* FUN_0042c9e0 @ 0042c9e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042c9e0(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (*(int *)(&DAT_004f7140 + DAT_004e8320 * 4) == 0) {
    uVar1 = FUN_00494c40(0x48,1);
    *(undefined4 *)(&DAT_004f7140 + DAT_004e8320 * 4) = uVar1;
    if (*(int *)(&DAT_004f7140 + DAT_004e8320 * 4) == 0) goto LAB_0042ca74;
  }
  local_8 = *(undefined4 **)(&DAT_004f7140 + DAT_004e8320 * 4);
  *local_8 = param_1;
  local_8[1] = param_2;
  FUN_00497270(local_8 + 2,param_3);
  DAT_004e8320 = DAT_004e8320 + 1;
LAB_0042ca74:
  local_8 = (undefined4 *)0x42ca81;
  __chkesp();
  return;
}

