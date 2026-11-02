/* FUN_0045ea00 @ 0045ea00 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x0045eb40) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0045ea00(void)

{
  int iVar1;
  int extraout_ECX;
  undefined4 *puVar2;
  undefined4 local_70 [16];
  int local_30;
  byte local_2c;
  ushort local_28 [16];
  int local_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_2c = 0;
  FUN_0043fe50(1 << (DAT_004f2800 & 0x1f));
  FUN_0043f8d0();
  FUN_0045ee90();
  iVar1 = extraout_ECX;
  for (local_8 = 0; local_8 < 0xf; local_8 = local_8 + 1) {
    local_28[local_8] = 1;
    iVar1 = local_8;
  }
  if (DAT_004e8984 == '\0') {
    for (local_8 = 0; local_8 < 0xf; local_8 = local_8 + 1) {
      local_30 = *(int *)(&DAT_004f2604 + local_8 * 0x14);
      if (local_30 == 2) {
        local_2c = FUN_0045eb60((uint)DAT_004f2800,(&DAT_004f2600)[local_8 * 0x14]);
        local_28[local_8] = (ushort)local_2c;
      }
      else if ((local_30 == 0x16) && (local_8 < 2)) {
        (&DAT_004f2750)[local_8 * 6] = 0;
        (&DAT_004f2744)[local_8 * 6] = 0;
      }
    }
  }
  else {
    FUN_0045eb60(CONCAT31((int3)((uint)iVar1 >> 8),DAT_004f2800),DAT_004f2600);
    local_28[0] = 1;
  }
  local_8 = 0;
  local_8 = 0x45eb4f;
  __chkesp();
  return;
}

