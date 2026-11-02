/* FUN_00416040 @ 00416040 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00416040(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004f1e24 != (int *)0x0) {
    FUN_004712c0(DAT_004f1e24);
  }
  if (DAT_004f1804 != (int *)0x0) {
    FUN_00473010(DAT_004f1804);
    DAT_004f1804 = (int *)0x0;
  }
  if (DAT_004f2b3c != (int *)0x0) {
    FUN_00456de0(DAT_004f2b3c);
    DAT_004f2b3c = (int *)0x0;
  }
  if (DAT_004f13a0 != (ushort *)0x0) {
    FUN_00477b30(DAT_004f13a0);
    DAT_004f13a0 = (ushort *)0x0;
  }
  for (local_8 = 0; local_8 < 0x104; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004f1e40 + local_8 * 4) = 0;
  }
  FUN_00474970();
  local_8 = 0x416111;
  __chkesp();
  return;
}

