/* FUN_0043ee20 @ 0043ee20 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043ee20(void)

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
  if (DAT_004e8508 != (int *)0x0) {
    (**(code **)(*DAT_004e8508 + 0x20))(DAT_004e8508);
    __chkesp();
    (**(code **)(*DAT_004e8508 + 8))(DAT_004e8508);
    __chkesp();
    DAT_004e8508 = (int *)0x0;
  }
  if (((DAT_004e8504 == 0) || (DAT_004e850c == 0)) || (DAT_004e8514 == 0)) {
    FUN_0043ec30();
  }
  uStack_8 = 0x43eeac;
  __chkesp();
  return;
}

