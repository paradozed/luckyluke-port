/* FUN_00462ff0 @ 00462ff0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00462ff0(void)

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
  DAT_004e8810 = 1;
  DAT_004e880d = 0;
  FUN_00466510(0,FUN_00465a40);
  DAT_004f23f8 = FUN_00463050;
  FUN_00463050();
  uStack_8 = 0x463041;
  __chkesp();
  return;
}

