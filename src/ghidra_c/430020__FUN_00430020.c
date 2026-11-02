/* FUN_00430020 @ 00430020 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00430020(void)

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
  FUN_00458ec0();
  DAT_004f6124 = FUN_00494c40(0x28,1);
  DAT_004f6128 = FUN_00494c40(1,1);
  FUN_0042fd30();
  uStack_8 = 0x430079;
  __chkesp();
  return;
}

