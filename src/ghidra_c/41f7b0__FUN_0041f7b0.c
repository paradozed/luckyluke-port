/* FUN_0041f7b0 @ 0041f7b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041f7b0(char param_1)

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
  if ((DAT_004bcfd0 != 0) && (param_1 != '\0')) {
    local_8 = *(undefined4 **)(&DAT_004d2390 + (uint)(byte)(param_1 - 1U) * 0x10);
    FUN_00493f10(local_8);
    (&DAT_004d2394)[(uint)(byte)(param_1 - 1U) * 0x10] = 0;
  }
  local_8 = (undefined4 *)0x41f829;
  __chkesp();
  return;
}

