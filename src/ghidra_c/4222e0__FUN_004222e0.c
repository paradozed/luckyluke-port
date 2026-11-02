/* FUN_004222e0 @ 004222e0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004222e0(undefined4 *param_1)

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
  local_8 = param_1;
  FUN_004227d0(param_1);
  local_8 = (undefined4 *)0x422315;
  __chkesp();
  return;
}

