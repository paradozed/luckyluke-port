/* FUN_004474f0 @ 004474f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004474f0(int param_1,byte param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 != 0) && (iVar1 = FUN_00446540(param_1,param_2), iVar1 != 0)) {
    *(undefined2 *)(iVar1 + 0x24) = param_3;
  }
  local_8 = 0x447543;
  __chkesp();
  return;
}

