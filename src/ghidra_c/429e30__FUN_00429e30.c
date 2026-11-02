/* FUN_00429e30 @ 00429e30 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00429e30(void)

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
  for (local_8 = 0; local_8 < 0x1f; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004f79e0 + local_8 * 0x1c) = 3;
    *(undefined4 *)(&DAT_004f79f0 + local_8 * 0x1c) = 0;
    *(undefined4 *)(&DAT_004f79f4 + local_8 * 0x1c) = 0;
    *(undefined4 *)(&DAT_004f79f8 + local_8 * 0x1c) = 0;
    *(undefined4 *)(&DAT_004f79e4 + local_8 * 0x1c) = 0xff;
    *(undefined4 *)(&DAT_004f79e8 + local_8 * 0x1c) = 100;
    *(undefined4 *)(&DAT_004f79ec + local_8 * 0x1c) = 0xff;
  }
  return;
}

