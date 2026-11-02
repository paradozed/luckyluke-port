/* FUN_00487ce0 @ 00487ce0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00487ce0(int param_1)

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
  (**(code **)(*(int *)(param_1 + 0xd4) + 4))(param_1);
  __chkesp();
  FUN_00487c50(param_1);
  (**(code **)(*(int *)(param_1 + 0xd4) + 8))(param_1);
  __chkesp();
  uStack_8 = 0x487d49;
  __chkesp();
  return;
}

