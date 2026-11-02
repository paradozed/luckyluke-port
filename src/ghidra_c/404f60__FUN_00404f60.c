/* FUN_00404f60 @ 00404f60 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00404f60(void)

{
  char cVar1;
  HWND pHVar2;
  uint dwNewLong;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_174 [16];
  int local_134;
  BYTE local_130 [4];
  uint local_12c;
  undefined4 uStack_8;
  
  puVar4 = local_174;
  for (iVar3 = 0x5c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  FUN_0045e600();
  FUN_00458ec0();
  cVar1 = FUN_0047d110((int)DAT_004f58a8,DAT_004e8590);
  if (cVar1 == '\0') {
    if ((*DAT_004f58a8 != 0x6d443344) || (DAT_004e8590 == 0)) {
      FUN_0045e8f0();
      goto LAB_0040522b;
    }
    FUN_00458ec0();
    if (DAT_004e8a88 == 0) {
      FUN_0045e8f0();
      goto LAB_0040522b;
    }
    FUN_00458ec0();
    FUN_0042b340();
    cVar1 = FUN_0047d110((int)DAT_004f58a8,DAT_004e8590);
    if (cVar1 == '\0') {
      FUN_0045e8f0();
      goto LAB_0040522b;
    }
  }
  if (DAT_004e8590 != 0) {
    iVar3 = -0x10;
    pHVar2 = (HWND)FUN_00445810();
    GetWindowLongA(pHVar2,iVar3);
    local_12c = __chkesp();
    dwNewLong = local_12c & 0xfffeffff;
    iVar3 = -0x10;
    pHVar2 = (HWND)FUN_00445810();
    SetWindowLongA(pHVar2,iVar3,dwNewLong);
    __chkesp();
  }
  if (*DAT_004f58a8 != 0x536f6674) {
    FUN_00429e30();
  }
  DAT_004d1dc0 = 1;
  FUN_00458ec0();
  local_134 = DAT_004e85a8;
  if (DAT_004e85a8 == 0) {
    (*DAT_00508a04)(0,0);
    __chkesp();
  }
  else if (DAT_004e85a8 == 1) {
    (*DAT_00508a04)(1,0);
    __chkesp();
  }
  else if (DAT_004e85a8 == 2) {
    (*DAT_00508a04)(0,1);
    __chkesp();
  }
  DAT_004f17ea = DAT_004e85ac;
  DAT_004f16c8 = 0;
  DAT_004f160c = (undefined1)DAT_004e859c;
  FUN_00458ec0();
  FUN_00473af0();
  FUN_00465a20();
  FUN_00471130();
  DAT_004f1e24 = FUN_00471170();
  FUN_0046dd20();
  FUN_00458ec0();
  FUN_004971b0(1);
  iVar3 = FUN_004223c0(&DAT_004d1da8,3,FUN_00420ad0,FUN_00420a40,FUN_00420c00);
  if (iVar3 == 0) {
    FUN_00477a60();
  }
  FUN_00458ec0();
  FUN_00420b60();
  iVar3 = FUN_00442670('\x01');
  if (iVar3 == 0) {
    DAT_004f2800 = '\0';
  }
  else {
    iVar3 = FUN_00442860("Keyboard Config",local_130);
    if (iVar3 == 0) {
      DAT_004f2800 = '\0';
    }
    else {
      DAT_004f2800 = local_130[0];
    }
    FUN_00442770();
  }
  DAT_004e8914 = 1;
  DAT_004be2e8 = (DAT_004be2e8 * 0x32) / 0x3c;
LAB_0040522b:
  uStack_8 = 0x40523b;
  __chkesp();
  return;
}

