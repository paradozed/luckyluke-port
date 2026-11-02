/* FUN_00464880 @ 00464880 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00464880(void)

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
  FUN_0041f5e0(2,0xf,0,14000,0x400,'\0');
  FUN_00466510(0x10,FUN_00464840);
  DAT_004f23f8 = FUN_004648f0;
  FUN_004648f0();
  uStack_8 = 0x4648dd;
  __chkesp();
  return;
}

