/* FUN_0043e8b0 @ 0043e8b0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043e8b0(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined4 local_4c [16];
  int local_c;
  undefined4 local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = 0;
  local_c = 0;
  FUN_0043cfe0();
  FUN_0043e770();
  DAT_004f5b60 = (int *)FUN_0043d1b0();
  DAT_004f5b68 = (int *)FUN_0043d7f0(0,0x43480000,0x43fa0000);
  DAT_004f5b6c = (int *)FUN_0043d7f0(0,-0x3cb80000,0x43fa0000);
  FUN_0043d4d0(DAT_004f5b60);
  FUN_0043d980(DAT_004f5b68,'\0');
  FUN_0043d980(DAT_004f5b6c,-0x80);
  FUN_004435d0((uint *)"Fade control",0,0x440fb0,0,1);
  FUN_004435d0((uint *)"Fade draw",0,0x441080,0,1);
  FUN_00440f30();
  (*DAT_004e8a74)();
  __chkesp();
  FUN_0047d870();
  do {
    FUN_0045f3e0();
    if (local_c == 0) {
      if ((DAT_004f59ce & 0x80) != 0) {
        FUN_00440f70();
        local_c = 1;
      }
      if ((DAT_004f5a90 & 0x80) != 0) {
        FUN_0043d180((int)DAT_004f5b60,1);
      }
      if ((DAT_004f5a88 & 0x80) != 0) {
        FUN_0043d180((int)DAT_004f5b60,2);
      }
      if ((DAT_004f59dc & 0x80) != 0) {
        FUN_00440f70();
        local_c = 1;
        lVar4 = __ftol();
        local_8 = (undefined4)lVar4;
      }
    }
    if ((float)DAT_004f5b60[5] <= _DAT_004b6ad8) {
      FUN_0043d8b0((int)DAT_004f5b68,2);
      FUN_0043d8b0((int)DAT_004f5b6c,1);
    }
    if (_DAT_004b6ad4 <= (float)DAT_004f5b60[5]) {
      FUN_0043d8b0((int)DAT_004f5b68,1);
      FUN_0043d8b0((int)DAT_004f5b6c,2);
    }
    FUN_00445740();
    while (DAT_004bcfe8 == '\0') {
      FUN_00445740();
    }
    (*DAT_004e8a10)(1);
    __chkesp();
    FUN_0043d310(DAT_004f5b60);
    FUN_0043d8e0(DAT_004f5b68);
    FUN_0043d8e0(DAT_004f5b6c);
    FUN_0047de90();
    FUN_004437e0(1);
    (*DAT_004e8a14)();
    __chkesp();
    if (DAT_004bcfe8 != '\0') {
      (*DAT_004e8a0c)();
      __chkesp();
    }
    FUN_0047d870();
  } while ((local_c == 0) || (bVar1 = FUN_004411c0(), bVar1));
  (*DAT_004e8a70)();
  __chkesp();
  FUN_00443890();
  FUN_0043d060(DAT_004f5b60);
  FUN_0043d790(DAT_004f5b68);
  FUN_0043d790(DAT_004f5b6c);
  local_8 = 0x43ebb2;
  __chkesp();
  return;
}

