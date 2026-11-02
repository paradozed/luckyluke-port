/* FUN_00449840 @ 00449840 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00449840(undefined4 param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_15c [16];
  undefined4 local_11c;
  char local_118 [260];
  void *local_14;
  uint local_10;
  PVOID local_c;
  size_t local_8;
  
  puVar4 = local_15c;
  for (iVar3 = 0x56; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_10 = local_10 & 0xffffff00;
  FUN_00441270(0,0,0);
  DAT_004f2e22 = DAT_004f2e22 & 0xf7;
  FUN_00440f30();
  FUN_00497080(local_118,0x4b3740);
  local_8 = _strlen(local_118);
  local_118[local_8 - 1] = 'X';
  local_118[local_8 - 2] = 'C';
  local_118[local_8 - 3] = 'P';
  local_14 = (void *)FUN_00431910(local_118);
  FUN_00437760((int)local_14,0x1e,0xe1);
  FUN_00437590((int)local_14,0x14,0xd7);
  local_c = (PVOID)FUN_0043ff20(0x200,0x100,0,1);
  FUN_004408d0((int)local_c,(int)local_14,'\0');
  if (local_14 != (void *)0xdddddddd) {
    FUN_00495280(local_14);
  }
  FUN_004371d0(param_2);
  (*DAT_004e8a7c)();
  uVar2 = __chkesp();
  if ((uVar2 & 0xff) != 0) {
    (*DAT_004e8a14)();
    __chkesp();
  }
  DAT_004e8601 = 1;
  for (local_8 = 0; (int)local_8 < 0x21; local_8 = local_8 + 1) {
    FUN_004454d0();
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_c,0x11);
    FUN_004374d0();
    FUN_00440fb0();
    FUN_00441080();
    (*DAT_004e8a14)();
    __chkesp();
    FUN_00449380();
  }
  while ((cVar1 = FUN_0045f3e0(), cVar1 != '\0' ||
         ((uVar2 = FUN_0043fdf0(), (uVar2 & 0xff) == 0 && ((local_10 & 0xff) == 0))))) {
    FUN_004454d0();
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_c,0x11);
    iVar3 = FUN_004374d0();
    if (iVar3 == 0) {
      local_10 = CONCAT31(local_10._1_3_,1);
    }
    (*DAT_004e8a14)();
    __chkesp();
    if (DAT_004e85b4 != '\0') {
      (*DAT_004e8a28)();
      local_11c = __chkesp();
      if (local_11c != 0) {
        FUN_004266d0("backpic.bmp",local_11c,DAT_004be3c8,DAT_004be3cc,'\x01');
      }
      DAT_004e85b4 = '\0';
    }
    FUN_00449380();
  }
  FUN_00440f70();
  for (local_8 = 0; (int)local_8 < 0x20; local_8 = local_8 + 1) {
    FUN_004454d0();
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_c,0x11);
    FUN_004374d0();
    FUN_00440fb0();
    FUN_00441080();
    (*DAT_004e8a14)();
    __chkesp();
    FUN_00449380();
  }
  DAT_004e8601 = 0;
  FUN_004405d0(local_c);
  FUN_00437480();
  FUN_00449670();
  local_8 = 0x449b5a;
  __chkesp();
  return;
}

