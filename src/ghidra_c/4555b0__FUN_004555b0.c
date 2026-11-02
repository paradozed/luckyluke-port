/* FUN_004555b0 @ 004555b0 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_004555b0(void)

{
  uint3 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = (uint3)(char)((ushort)DAT_004e866a >> 8);
  if (DAT_004e866a < 0x79) {
    if (((DAT_004e866a == 0x78) || (DAT_004e866a == 0x41)) ||
       ((DAT_004e866a == 0x4c || (DAT_004e866a == 0x62)))) {
LAB_0045560f:
      return CONCAT31(uVar1,1);
    }
  }
  else if (((DAT_004e866a == 0x99) || (DAT_004e866a == 0x1b2)) || (DAT_004e866a == 0x1e1))
  goto LAB_0045560f;
  return (uint)uVar1 << 8;
}

