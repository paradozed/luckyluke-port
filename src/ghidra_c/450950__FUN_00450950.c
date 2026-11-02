/* FUN_00450950 @ 00450950 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00450950(void)

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
  DAT_004e863c = 6;
  FUN_00466510(8,FUN_0044fd30);
  FUN_0041f5e0(2,10,0xfa,0x1194,0,'\0');
  DAT_004f23f8 = FUN_004509c0;
  FUN_004509c0();
  uStack_8 = 0x4509b6;
  __chkesp();
  return;
}

