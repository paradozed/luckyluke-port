/* FUN_004500e0 @ 004500e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004500e0(void)

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
  DAT_004e863c = 2;
  FUN_00466510(2,FUN_0044fd30);
  FUN_0041f5e0(2,6,100,0x1fff,0x800,'\0');
  DAT_004f23f8 = FUN_00450150;
  FUN_00450150();
  uStack_8 = 0x450146;
  __chkesp();
  return;
}

