/* FUN_00462f20 @ 00462f20 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00462f20(void)

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
  if ((DAT_004e8813 == '\0') && (DAT_004e8813 = '\x01', DAT_004e8984 == '\0')) {
    DAT_004f2c6c = DAT_004f2800;
  }
  DAT_004e861e = 0;
  FUN_00466510(0,FUN_00465a40);
  DAT_004f23f8 = FUN_00462fa0;
  FUN_00462fa0();
  uStack_8 = 0x462f94;
  __chkesp();
  return;
}

