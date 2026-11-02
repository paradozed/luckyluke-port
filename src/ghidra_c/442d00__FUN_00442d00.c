/* FUN_00442d00 @ 00442d00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442d00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = *(undefined4 **)(param_1 + 0x210); local_8 != (undefined4 *)0x0;
      local_8 = (undefined4 *)*local_8) {
    FUN_00458ec0();
  }
  local_8 = (undefined4 *)0x442d5e;
  __chkesp();
  return;
}

