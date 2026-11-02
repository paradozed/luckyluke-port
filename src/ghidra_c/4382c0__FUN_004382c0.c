/* FUN_004382c0 @ 004382c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004382c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e84cc != (int *)0x0) {
    FUN_00498130(DAT_004e84cc,
                 (byte *)"Memory allocated at %x of size %d bytes on line %d of %s<BR>\n");
    FUN_00499050(DAT_004e84cc);
  }
  uStack_8 = 0x438323;
  __chkesp();
  return;
}

