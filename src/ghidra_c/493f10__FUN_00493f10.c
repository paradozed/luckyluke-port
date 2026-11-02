/* FUN_00493f10 @ 00493f10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00493f10(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    *(undefined1 *)(param_1 + 1) = 0;
    param_1[2] = 0;
    *param_1 = 0;
  }
  return;
}

