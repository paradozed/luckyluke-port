/* FUN_00415190 @ 00415190 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00415190(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_005081a0 != '\0') {
    if (*(char *)(DAT_00507f38 + 1) == '\0') {
      if (*(ushort *)(DAT_00507f38 + 8) < 0x400) {
        *(ushort *)(DAT_00507f38 + 8) =
             *(short *)(DAT_00507f38 + 8) + (ushort)*(byte *)(DAT_00507f38 + 2);
      }
      else {
        DAT_005081a0 = '\0';
      }
    }
    else if (*(ushort *)(DAT_00507f38 + 6) < *(ushort *)(DAT_00507f38 + 8)) {
      *(ushort *)(DAT_00507f38 + 8) =
           *(short *)(DAT_00507f38 + 8) - (ushort)*(byte *)(DAT_00507f38 + 2);
    }
    else {
      *(undefined2 *)(DAT_00507f38 + 8) = *(undefined2 *)(DAT_00507f38 + 6);
    }
    *(short *)(DAT_00507f38 + 10) =
         (short)((int)(uint)(ushort)DAT_004e8abc >> (*(byte *)(DAT_00507f38 + 3) & 0x1f));
  }
  return;
}

