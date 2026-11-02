/* FUN_0043ec30 @ 0043ec30 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043ec30(void)

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
  if (DAT_004e8500 != (int *)0x0) {
    (**(code **)(*DAT_004e8500 + 8))(DAT_004e8500);
    __chkesp();
    DAT_004e8500 = (int *)0x0;
  }
  uStack_8 = 0x43ec82;
  __chkesp();
  return;
}

