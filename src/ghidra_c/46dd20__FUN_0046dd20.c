/* FUN_0046dd20 @ 0046dd20 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046dd20(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [18];
  undefined4 uStack_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004f2288 = FUN_0046dfd0();
  DAT_004e8904 = 0;
  uStack_8 = 0x46dd59;
  __chkesp();
  return;
}

