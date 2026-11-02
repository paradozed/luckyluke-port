/* FUN_00449510 @ 00449510 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00449510(undefined4 param_1,undefined4 *param_2)

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
  local_8 = FUN_00426610(param_1);
  FUN_00426140(param_2);
  local_8 = 0x449553;
  __chkesp();
  return;
}

