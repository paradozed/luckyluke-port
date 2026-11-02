/* FUN_00404be0 @ 00404be0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00404be0(void)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  bool bVar6;
  undefined4 local_1170 [16];
  int local_1130;
  int local_112c;
  undefined1 local_1128 [260];
  uint local_1024;
  uint local_1020;
  uint local_101c;
  int local_1014;
  undefined1 local_1010 [232];
  undefined1 local_f28 [3832];
  undefined4 uStackY_30;
  undefined1 *puVar7;
  uint *puVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004b280c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00497180();
  puVar5 = local_1170;
  for (iVar4 = 0x458; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  FUN_004011c0((int)local_1010);
  local_8 = 0;
  local_112c = 0;
  if (*DAT_004f58a8 != 0x536f6674) {
    local_112c = 6;
  }
  uStackY_30 = 0x404c64;
  FUN_00497080(local_1128,0x4b3740);
  FUN_00458ec0();
  FUN_00425f40(local_f28,FUN_00404b90);
  puVar7 = local_1128;
  uVar2 = FUN_00445810();
  cVar1 = FUN_004016a0(local_1010,uVar2,puVar7);
  if (cVar1 == '\0') {
    local_8 = 0xffffffff;
    FUN_00404f20();
  }
  else {
    DAT_004d1d80 = local_1010;
    cVar1 = FUN_00401a10(local_1010,&local_1020);
    if (cVar1 == '\0') {
      FUN_00458ec0();
    }
    FUN_00458ec0();
    uStackY_30 = 0x404d1b;
    local_1014 = FUN_0043ff20(local_1020,local_101c,0,5);
    FUN_00458ec0();
    FUN_00458ec0();
    FUN_00401550((int)local_1010);
    DAT_004d1dc4 = 1;
    (*DAT_004e8a74)();
    __chkesp();
    (*DAT_005089f4)();
    __chkesp();
    FUN_0043fe80();
    DAT_004e8601 = 1;
    for (local_1130 = 0; local_1130 < 0x10; local_1130 = local_1130 + 1) {
      _memset(*(void **)(DAT_004f58a4 + local_1130 * 4),0,0x20000);
    }
    FUN_0044b2a0();
    do {
      if (DAT_004e8603 != '\0') break;
      FUN_004454d0();
      FUN_0043f8d0();
      FUN_0045ee90();
      uVar3 = FUN_0043fd80();
      if (((uVar3 & 0xff) != 0) && (cVar1 = FUN_0045f3e0(), cVar1 == '\0')) break;
      puVar8 = &local_1024;
      uVar2 = FUN_00445810();
      FUN_00401f80(local_1010,uVar2,(int *)puVar8);
      (*DAT_004e8a10)();
      __chkesp();
      if ((1000 < local_1024) &&
         (iVar4 = local_112c + -1, bVar6 = local_112c < 0, local_112c = iVar4, bVar6)) {
        FUN_004408d0(local_1014,local_1024,'\x01');
      }
      FUN_00440730(local_1014,0x11);
      (*DAT_004e8a14)();
      __chkesp();
      (*DAT_004e8a0c)();
      __chkesp();
      bVar6 = FUN_004014c0((int)local_1010);
    } while (!bVar6);
    DAT_004e8601 = 0;
    (*DAT_004e8a70)();
    __chkesp();
    DAT_004d1dc4 = 0;
    FUN_00401350((int)local_1010);
    local_8 = 0xffffffff;
    FUN_00404f20();
  }
  ExceptionList = local_10;
  __chkesp();
  return;
}

