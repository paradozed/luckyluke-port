/* FUN_004342c0 @ 004342c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004342c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_350 [16];
  BYTE local_310 [260];
  undefined1 local_20c [260];
  uint local_108 [64];
  undefined4 uStack_8;
  
  puVar2 = local_350;
  for (iVar1 = 0xd3; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00433fa0(local_310);
  if (iVar1 != 0) {
    FUN_004341f0((int)local_310,(int)local_108,0);
    FUN_004341f0((int)local_310,(int)local_20c,1);
    FUN_00498cf0(local_108,(char *)local_108);
  }
  uStack_8 = 0x434352;
  __chkesp();
  return;
}

