/* FUN_0043f950 @ 0043f950 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043f950(uint *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (uint *)FUN_00494c40(0x104,1);
  if (local_8 != (uint *)0x0) {
    local_8[0x40] = 0;
    FUN_00497270(local_8,param_1);
  }
  local_8 = (uint *)0x43f9b1;
  __chkesp();
  return;
}

