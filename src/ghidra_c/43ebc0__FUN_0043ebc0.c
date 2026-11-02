/* FUN_0043ebc0 @ 0043ebc0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043ebc0(undefined4 param_1)

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
  if (DAT_004e8500 == 0) {
    FUN_00458ec0();
    DirectInputCreateA(param_1,0x500,&DAT_004e8500,0);
  }
  local_8 = 0x43ec24;
  __chkesp();
  return;
}

