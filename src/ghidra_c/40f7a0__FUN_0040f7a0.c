/* FUN_0040f7a0 @ 0040f7a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040f7a0(int param_1,void *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = FUN_00407580(param_1);
  local_8 = *(undefined4 *)(local_c + 8);
  FUN_004074b0(param_2,2);
  local_8 = 0x40f7fb;
  __chkesp();
  return;
}

