/* FUN_004037c0 @ 004037c0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004037c0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004d1d64 == 0) {
    uVar1 = 0xcccc0000;
  }
  else {
    uVar1 = CONCAT22(0xcccc,DAT_004d1cdc);
  }
  return uVar1;
}

