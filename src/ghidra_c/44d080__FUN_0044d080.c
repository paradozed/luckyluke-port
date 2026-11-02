/* FUN_0044d080 @ 0044d080 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d080(void)

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
  if (DAT_004e8622 == '\0') {
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x32) = 0;
  }
  else if ((int)(uint)DAT_004bd054 < (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36)) {
    DAT_004f2c60 = FUN_0044d1f0;
    FUN_0044d1f0();
  }
  uStack_8 = 0x44d0ec;
  __chkesp();
  return;
}

