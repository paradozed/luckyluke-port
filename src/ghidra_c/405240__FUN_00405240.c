/* FUN_00405240 @ 00405240 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00405240(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00442670('\0');
  if (iVar1 != 0) {
    local_8 = (uint)DAT_004f2800;
    FUN_004428e0("Keyboard Config");
    FUN_00442770();
  }
  FUN_00404b60();
  FUN_0046ddd0();
  FUN_0047d490();
  FUN_0045e8f0();
  FUN_004492d0();
  local_8 = 0x4052ac;
  __chkesp();
  return;
}

