/* FUN_0044d460 @ 0044d460 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d460(void)

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
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
  *(short *)(*(int *)(DAT_004f1578 + 4) + 0x30) = *(short *)(*(int *)(DAT_004f1578 + 4) + 0x30) + 1;
  if (DAT_004e861d == '\0') {
    DAT_004f2c60 = FUN_0044d0f0;
    FUN_0044d0f0();
  }
  else {
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x32) = 0;
    DAT_004f2c60 = FUN_0044d760;
    DAT_004f23f8 = FUN_0044cb20;
    FUN_0044cb20();
  }
  uStack_8 = 0x44d522;
  __chkesp();
  return;
}

