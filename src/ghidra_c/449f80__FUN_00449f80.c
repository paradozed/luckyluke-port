/* FUN_00449f80 @ 00449f80 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00449f80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004f2e22 & 2) == 2) {
    DAT_004f2e20 = DAT_004f2e20 + -8;
    if (DAT_004f2e20 < 1) {
      DAT_004f2e20 = 0;
      DAT_004f2e22 = DAT_004f2e22 | 0x14;
      DAT_004f2e0c = 1;
    }
  }
  else {
    DAT_004f2e20 = DAT_004f2e20 + 8;
    if (0xfe < DAT_004f2e20) {
      DAT_004f2e20 = 0xff;
      DAT_004f2e22 = DAT_004f2e22 | 0xc;
    }
  }
  return;
}

