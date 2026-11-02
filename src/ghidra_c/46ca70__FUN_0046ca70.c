/* FUN_0046ca70 @ 0046ca70 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046ca70(void)

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
  if ((DAT_004f2438 & 0x2000) == 0) {
    DAT_004f5556 = 0;
    DAT_004f2294 = FUN_0046ca20;
    FUN_0046ca20();
  }
  else {
    FUN_0046cb30();
  }
  uStack_8 = 0x46cac3;
  __chkesp();
  return;
}

