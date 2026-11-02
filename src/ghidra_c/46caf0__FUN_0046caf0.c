/* FUN_0046caf0 @ 0046caf0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046caf0(void)

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
  FUN_0046cb30();
  DAT_004f2294 = FUN_0046cad0;
  FUN_0046cad0();
  uStack_8 = 0x46cb29;
  __chkesp();
  return;
}

