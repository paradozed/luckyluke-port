/* FUN_00455270 @ 00455270 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00455270(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  uVar1 = (ushort)DAT_004f2744;
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (((ushort)DAT_004f2744 & 0x2000) != 0) {
    *(undefined4 *)(DAT_004f2458 + 0xac) = 0x5aa;
  }
  if (DAT_004e8701 == '\x01') {
    if ((DAT_004e8668 == '\0') && ((uVar1 & 0x1000) != 0)) {
      DAT_004e8668 = '\x01';
    }
    if ((DAT_004e8668 == '\x01') && ((uVar1 & 0x1000) == 0)) {
      DAT_004e8668 = '\x02';
    }
    if ((DAT_004e8668 == '\x02') && ((uVar1 & 0x1000) != 0)) {
      DAT_004e8668 = '\x03';
    }
    if ((DAT_004e8668 == '\x03') && ((uVar1 & 0x1000) == 0)) {
      DAT_004e8668 = '\0';
    }
    if (DAT_004e8668 == '\x02') {
      *(undefined4 *)(DAT_004f2458 + 0xac) = 0;
    }
  }
  return;
}

