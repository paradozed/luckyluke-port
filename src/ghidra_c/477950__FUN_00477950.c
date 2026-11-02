/* FUN_00477950 @ 00477950 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00477950(void)

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
  FUN_00477260();
  if (DAT_004e8984 == '\0') {
    if (DAT_004e8986 == '\0') {
      if (DAT_004e898a == '\0') {
        (*DAT_004e8a30)();
        __chkesp();
        FUN_004442e0((int *)&DAT_004f1610,0,0,0,0);
        (*DAT_004e8a30)();
        __chkesp();
        FUN_004442e0((int *)&DAT_004f1740,0,0,0,0);
      }
      else {
        (*DAT_004e8a30)();
        __chkesp();
        FUN_004442e0((int *)&DAT_004f16b0,0,0,0,0);
      }
    }
    else {
      (*DAT_004e8a30)();
      __chkesp();
      FUN_004442e0((int *)&DAT_004f1580,0,0,0,0);
    }
    DAT_004e897c = *(short **)(DAT_004f175c + 0xc);
    FUN_00448a40(DAT_004e897c);
  }
  uStack_8 = 0x477a54;
  __chkesp();
  return;
}

