/* FUN_00463050 @ 00463050 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00463050(void)

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
  if (DAT_004e880d == '\0') {
    FUN_00464910();
  }
  iVar1 = FUN_00463480();
  if (iVar1 != 0) {
    DAT_004f23f8 = FUN_004630b0;
    FUN_004630b0();
  }
  uStack_8 = 0x46309d;
  __chkesp();
  return;
}

