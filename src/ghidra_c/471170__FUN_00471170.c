/* FUN_00471170 @ 00471170 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00471170(void)

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
  iVar1 = FUN_00494c40(8,1);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 6) = 0;
    *(undefined2 *)(iVar1 + 4) = 0;
  }
  local_8 = 0x4711c3;
  __chkesp();
  return;
}

