/* FUN_004452f0 @ 004452f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004452f0(void)

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
  _memset(DAT_004e85bc,0,0x708);
  _memset(DAT_004e85c0,0,0x4b0);
  _memset(DAT_004e85c4,0,2000);
  DAT_004e85c8 = 0;
  DAT_004e85cc = 0;
  DAT_004e85d0 = 0;
  uStack_8 = 0x445374;
  __chkesp();
  return;
}

