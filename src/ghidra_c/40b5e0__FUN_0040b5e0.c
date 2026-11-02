/* FUN_0040b5e0 @ 0040b5e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040b5e0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  undefined2 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_c;
  int local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_c = **(int **)(local_8 + 8);
  local_20 = FUN_0040b690(local_c);
  local_1c = *(undefined4 *)(local_c + 0x90);
  local_18 = *(undefined4 *)(local_c + 0x94);
  local_14 = *(undefined4 *)(local_c + 0x98);
  local_8 = 0x40b683;
  __chkesp();
  return;
}

