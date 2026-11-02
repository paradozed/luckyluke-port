/* FUN_0040c310 @ 0040c310 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0040c310(void)

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
  DAT_004e8812 = 0;
  DAT_004f1e21 = 1;
  DAT_004f17e8 = 1;
  FUN_0042e7f0();
  uStack_8 = 0x40c353;
  __chkesp();
  return;
}

