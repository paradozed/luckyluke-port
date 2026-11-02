/* FUN_004784d0 @ 004784d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004784d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004be2ed == '\0') {
    DAT_004be2ed = '\x01';
  }
  return;
}

