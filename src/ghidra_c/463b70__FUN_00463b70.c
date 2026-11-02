/* FUN_00463b70 @ 00463b70 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00463b70(void)

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
  FUN_00461db0('\0');
  if (((DAT_004f2744 & 0x8000) == 0) && ((DAT_004f2744 & 0x40) == 0)) {
    DAT_004f23f8 = FUN_00462ff0;
    FUN_00462ff0();
  }
  uStack_8 = 0x463bc9;
  __chkesp();
  return;
}

