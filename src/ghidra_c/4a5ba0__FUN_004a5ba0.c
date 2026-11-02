/* FUN_004a5ba0 @ 004a5ba0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004a5ba0(void)

{
  int iVar1;
  
  iVar1 = DAT_004e8d1c;
  __setdefaultprecision();
  if ((iVar1 != 0) && ((**(uint **)(iVar1 + 4) & 0x10008) != 0)) {
    iVar1 = *(int *)(iVar1 + 4);
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0xffff;
  }
  return;
}

