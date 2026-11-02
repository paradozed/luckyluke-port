/* FUN_0040fe20 @ 0040fe20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040fe20(int param_1)

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
  iVar1 = FUN_00407580(param_1);
  DAT_004e8474 = **(undefined4 **)(iVar1 + 8);
  local_8 = 0x40fe67;
  local_c = DAT_004e8474;
  __chkesp();
  return;
}

