/* FUN_0040c8f0 @ 0040c8f0 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_0040c8f0(void)

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
  if (DAT_00507f38 == 0) {
    iVar2 = -0x33340000;
  }
  else if (DAT_005081a0 == '\0') {
    iVar2 = 0;
  }
  else {
    uVar1 = (ushort)((uint)DAT_00507f38 >> 0x10);
    if (*(short *)(DAT_00507f38 + 8) == *(short *)(DAT_00507f38 + 6)) {
      iVar2 = (uint)uVar1 << 0x10;
    }
    else {
      iVar2 = CONCAT22(uVar1,1);
    }
  }
  return iVar2;
}

