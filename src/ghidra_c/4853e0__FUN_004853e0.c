/* FUN_004853e0 @ 004853e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004853e0(int param_1,int param_2,int param_3)

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
  do {
    FUN_00485360(param_1,param_2,param_3);
    param_1 = *(int *)(param_1 + 0x10);
  } while (param_1 != 0);
  uStack_8 = 0x485428;
  __chkesp();
  return;
}

