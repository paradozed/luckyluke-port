/* FUN_0044dfa0 @ 0044dfa0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044dfa0(void)

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
  FUN_00466510(2,FUN_0044e050);
  DAT_004f23f8 = FUN_0044dff0;
  FUN_0044dff0();
  uStack_8 = 0x44dfe3;
  __chkesp();
  return;
}

