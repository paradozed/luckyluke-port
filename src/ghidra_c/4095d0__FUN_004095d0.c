/* FUN_004095d0 @ 004095d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_004095d0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            int param_7)

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
  param_3 = param_3 + *(int *)(param_6 + 8);
  if (param_7 < param_3) {
    param_3 = param_7 + 1;
  }
  FUN_00408d40(param_1,param_2 + *(int *)(param_6 + 4),param_3,param_4 + *(int *)(param_6 + 0xc));
  uStack_8 = 0x409642;
  __chkesp();
  return;
}

