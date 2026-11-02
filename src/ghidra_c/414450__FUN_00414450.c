/* FUN_00414450 @ 00414450 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00414450(void)

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
  FUN_0042bf50();
  uStack_8 = 0x41447a;
  __chkesp();
  return;
}

