/* FUN_00469020 @ 00469020 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00469020(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_0041ff20();
  if ((uVar1 & 0xff) == 1) {
    FUN_0041f5e0(0,1,-100,0x1fff,0x400,'\0');
  }
  DAT_004f23b8 = FUN_00468d80;
  uStack_8 = 0x469078;
  __chkesp();
  return;
}

