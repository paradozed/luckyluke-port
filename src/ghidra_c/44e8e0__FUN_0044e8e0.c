/* FUN_0044e8e0 @ 0044e8e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044e8e0(void)

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
  FUN_0041f5e0(2,0x14,0,14000,0x400,'\0');
  FUN_00466510(9,FUN_0044e8a0);
  DAT_004f23f8 = FUN_0044e950;
  FUN_0044e950();
  uStack_8 = 0x44e93d;
  __chkesp();
  return;
}

