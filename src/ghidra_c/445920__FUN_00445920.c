/* FUN_00445920 @ 00445920 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00445920(void)

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
  FUN_00439a90(DAT_004e85ec,0x28);
  local_8 = 0x44595b;
  __chkesp();
  return;
}

