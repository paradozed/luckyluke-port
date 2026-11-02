/* FUN_00438fa0 @ 00438fa0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00438fa0(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_004385a0(param_2);
  local_c = FUN_00438ce0(param_1);
  FUN_004385a0(local_8);
  local_8 = 0x438ff2;
  __chkesp();
  return;
}

