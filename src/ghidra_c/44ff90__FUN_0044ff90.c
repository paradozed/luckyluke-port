/* FUN_0044ff90 @ 0044ff90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044ff90(void)

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
  DAT_004e863c = 1;
  FUN_00466510(1,FUN_0044fd30);
  FUN_0041f5e0(2,4,0x15e,0xfff,0x800,'\0');
  DAT_004f23f8 = FUN_00450000;
  FUN_00450000();
  uStack_8 = 0x44fff9;
  __chkesp();
  return;
}

