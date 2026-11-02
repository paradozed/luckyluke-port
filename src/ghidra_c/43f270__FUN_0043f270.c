/* FUN_0043f270 @ 0043f270 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043f270(void)

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
  if (DAT_004e850c != (int *)0x0) {
    (**(code **)(*DAT_004e850c + 0x20))(DAT_004e850c);
    __chkesp();
    (**(code **)(*DAT_004e850c + 8))(DAT_004e850c);
    __chkesp();
    DAT_004e850c = (int *)0x0;
  }
  if (DAT_004e8510 != (int *)0x0) {
    (**(code **)(*DAT_004e8510 + 8))(DAT_004e8510);
    __chkesp();
    DAT_004e8510 = (int *)0x0;
  }
  if (((DAT_004e8504 == 0) || (DAT_004e850c == (int *)0x0)) || (DAT_004e8514 == 0)) {
    FUN_0043ec30();
  }
  uStack_8 = 0x43f329;
  __chkesp();
  return;
}

