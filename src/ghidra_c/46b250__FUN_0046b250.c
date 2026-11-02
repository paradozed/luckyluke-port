/* FUN_0046b250 @ 0046b250 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046b250(void)

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
  DAT_004f2748 = DAT_004f2748 & 0xffffff5f;
  FUN_00466510(0,FUN_00465a40);
  uStack_8 = 0x46b290;
  __chkesp();
  return;
}

