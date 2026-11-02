/* FUN_00438400 @ 00438400 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00438400(void)

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
                 (byte *)
                 "<FONT color=AA0000>Duplicate allocation detected at %x, line %d of file %s</FONT><BR>\n"
                );
    FUN_00499050(DAT_004e84cc);
  }
  uStack_8 = 0x43845e;
  __chkesp();
  return;
}

