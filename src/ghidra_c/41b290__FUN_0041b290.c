/* FUN_0041b290 @ 0041b290 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041b290(int param_1)

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
  local_8 = (undefined4 *)FUN_00407580(param_1);
  FUN_0041b2d0(local_8);
  local_8 = (undefined4 *)0x41b2cc;
  __chkesp();
  return;
}

