/* FUN_00445040 @ 00445040 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00445040(void)

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
  FUN_0047d7e0(4000);
  DAT_004e85bc = FUN_00494c40(0x708,1);
  DAT_004e85c0 = FUN_00494c40(0x4b0,1);
  DAT_004e85c4 = FUN_00494c40(2000,1);
  DAT_004e85c8 = 0;
  DAT_004e85cc = 0;
  DAT_004e85d0 = 0;
  _memset(&DAT_004f2e40,0,10000);
  uStack_8 = 0x4450e0;
  __chkesp();
  return;
}

