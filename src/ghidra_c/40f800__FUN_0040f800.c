/* FUN_0040f800 @ 0040f800 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_0040f800(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = (ushort)((uint)DAT_004f58a8 >> 0x10);
  if (*DAT_004f58a8 == 0x536f6674) {
    iVar2 = CONCAT22(uVar1,1);
  }
  else {
    iVar2 = (uint)uVar1 << 0x10;
  }
  return iVar2;
}

