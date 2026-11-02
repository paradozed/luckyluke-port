/* FUN_0040f9c0 @ 0040f9c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040f9c0(int param_1)

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
  iVar1 = FUN_00407580(param_1);
  DAT_004d1e48 = *(undefined4 *)(iVar1 + 8);
  local_8 = 0x40fa00;
  __chkesp();
  return;
}

