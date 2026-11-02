/* FUN_00431660 @ 00431660 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00431660(void)

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
  FUN_00430d70();
  uStack_8 = 0x43168a;
  __chkesp();
  return;
}

