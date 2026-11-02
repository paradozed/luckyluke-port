/* FUN_0047d700 @ 0047d700 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047d700(int param_1,undefined4 param_2)

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
  FUN_0047d630(param_1,param_2,*(int *)(param_1 + 0x4c));
  FUN_0047d630(param_1,param_2,*(int *)(param_1 + 0x50));
  uStack_8 = 0x47d753;
  __chkesp();
  return;
}

