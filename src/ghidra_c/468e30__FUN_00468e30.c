/* FUN_00468e30 @ 00468e30 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00468e30(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8854 == 0) {
    DAT_004e8854 = DAT_004e89e0;
  }
  if (0x78 < (uint)(DAT_004e89e0 - DAT_004e8854)) {
    DAT_004e8854 = 0;
    DAT_004f23b8 = 0;
  }
  return;
}

