/* FUN_0043fe80 @ 0043fe80 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043fe80(void)

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
  _memset(&DAT_004f59c0,0,0x100);
  _memset(&DAT_004f58c0,0,0x100);
  _memset(&DAT_004f5ac0,0,0x50);
  _memset(&DAT_004f5b10,0,0x10);
  _memset(&DAT_004e8518,0,0x10);
  _memset(&DAT_004e8528,0,0x10);
  uStack_8 = 0x43ff11;
  __chkesp();
  return;
}

