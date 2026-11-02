/* FUN_00411bd0 @ 00411bd0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411bd0(int param_1,short param_2,short param_3,short param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(param_1 + 0xdc) == 0) {
    FUN_00411680(param_1,param_2,param_3,param_4);
  }
  else {
    FUN_00411c40(*(int *)(param_1 + 0xdc),param_2,param_3,param_4);
  }
  uStack_8 = 0x411c39;
  __chkesp();
  return;
}

