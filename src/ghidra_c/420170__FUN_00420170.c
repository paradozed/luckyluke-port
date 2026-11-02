/* FUN_00420170 @ 00420170 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00420170(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = local_8 & 0xffffff00;
  if ((DAT_004bcfd0 != 0) && (DAT_004d2884 != '\0')) {
    uVar1 = FUN_004037c0();
    local_8 = CONCAT31(local_8._1_3_,(char)uVar1);
    FUN_00497610((byte *)"Retrieving number of CD tracks: %d\n");
  }
  local_8 = 0x4201dc;
  __chkesp();
  return;
}

