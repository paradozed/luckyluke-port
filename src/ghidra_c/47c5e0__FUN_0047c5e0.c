/* FUN_0047c5e0 @ 0047c5e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047c5e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  FUN_00482a50(0x508180,&local_14);
  uStack_8 = 0x47c628;
  __chkesp();
  return;
}

