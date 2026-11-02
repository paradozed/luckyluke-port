/* FUN_0046d700 @ 0046d700 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_0046d700(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_48 [17];
  
  puVar4 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (DAT_004f23b4 + 1) % 0x37;
  DAT_004f23b4 = (ushort)uVar2;
  uVar3 = (DAT_004f23b6 + 1) % 0x37;
  DAT_004f23b6 = (ushort)uVar3;
  *(int *)(&DAT_004f22c0 + uVar2 * 4) =
       *(int *)(&DAT_004f22c0 + uVar2 * 4) - *(int *)(&DAT_004f22c0 + uVar3 * 4);
  return CONCAT22((short)((ulonglong)*(uint *)(&DAT_004f22c0 + (uint)DAT_004f23b4 * 4) / 0x7fff >>
                         0x10),
                  (short)((ulonglong)*(uint *)(&DAT_004f22c0 + (uint)DAT_004f23b4 * 4) % 0x7fff));
}

