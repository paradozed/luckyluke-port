/* FUN_0042c8c0 @ 0042c8c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042c8c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  char *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  _memset(&DAT_004f6540,0,0x400);
  FUN_00458ec0();
  local_8 = (char *)FUN_00435000("win\\graphics\\font.kxp","lucky");
  FUN_00458ec0();
  FUN_0042c050(local_8,0x4bc578,0x38);
  FUN_00458ec0();
  FUN_00435d90(local_8);
  FUN_00458ec0();
  FUN_00458ec0();
  local_8 = (char *)0x42c9a2;
  __chkesp();
  return;
}

