/* FUN_0044a1c0 @ 0044a1c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044a1c0(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 uStack_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  bVar1 = FUN_004411c0();
  if (bVar1) {
    FUN_00440fb0();
    FUN_00441080();
  }
  uStack_8 = 0x44a1fd;
  __chkesp();
  return;
}

