/* FUN_0040d120 @ 0040d120 */
/* decompiled from Lucky.exe (Game.run) */


byte FUN_0040d120(void)

{
  int iVar1;
  undefined4 *puVar2;
  byte bVar3;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  bVar3 = DAT_004e8700 != '\0';
  if (DAT_004e8701 != '\0') {
    bVar3 = bVar3 | 2;
  }
  return bVar3;
}

