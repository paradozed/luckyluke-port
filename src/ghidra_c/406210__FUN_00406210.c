/* FUN_00406210 @ 00406210 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406210(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  int local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = 0;
  if (((DAT_004e8984 == '\0') && (DAT_004f1765 != '\0')) && (DAT_004f2e0c != '\0')) {
    if ((DAT_004e8988 != 0) && (sVar2 = FUN_004775f0(), sVar2 == 0)) {
      local_8 = 1;
    }
    if (((DAT_004e8914 == 0x19) && (cVar1 = FUN_0043fc90(DAT_004e8784), cVar1 != '\0')) ||
       ((DAT_004e8914 != 0x19 &&
        ((cVar1 = FUN_0043fc90(DAT_004e8784), cVar1 != '\0' ||
         (cVar1 = FUN_0043fc90(DAT_004e8788), cVar1 != '\0')))))) {
      cVar1 = FUN_0043fc90(DAT_004e8784);
      if ((cVar1 != '\0') && (1 < DAT_004e85b8)) {
        DAT_004d1dcc = 1;
      }
      cVar1 = FUN_0043fc90(DAT_004e8788);
      if ((cVar1 != '\0') && (DAT_004e8986 == '\0')) {
        DAT_004e8986 = '\x01';
        DAT_004d1dd0 = 1;
      }
    }
    else {
      cVar1 = FUN_0043fc90(DAT_004e8784);
      if ((cVar1 == '\0') && (DAT_004d1dcc != 0)) {
        DAT_004d1dcc = 0;
        local_8 = 1;
      }
      cVar1 = FUN_0043fc90(DAT_004e8788);
      if ((cVar1 == '\0') && (DAT_004d1dd0 != 0)) {
        DAT_004d1dd0 = 0;
        local_8 = 1;
      }
    }
    if ((((DAT_004e8988 != 0) && (DAT_004f58d9 != '\0')) && (DAT_004e8986 == '\0')) &&
       (DAT_004e898a == '\0')) {
      local_8 = 1;
    }
    if ((local_8 != 0) && (DAT_004be1a8 != '\0')) {
      if (DAT_004e8988 == 0) {
        DAT_004d1d78 = _DAT_004e89dc;
        FUN_0041f830('\x01');
        FUN_004200e0('\x01');
        if (DAT_004e8750 == 1) {
          DAT_004e8750 = 0;
          FUN_0045e280();
          DAT_004d1dd4 = 1;
        }
      }
      else {
        _DAT_004e89dc = DAT_004d1d78;
        FUN_0041f830('\0');
        FUN_004200e0('\0');
        DAT_004e8986 = '\0';
        DAT_004e898b = 0;
        if (DAT_004d1dd4 != 0) {
          DAT_004e8750 = 1;
          FUN_0045e280();
          DAT_004d1dd4 = 0;
        }
      }
      DAT_004e8988 = DAT_004e8988 ^ 1;
    }
  }
  local_8 = 0x4064cd;
  __chkesp();
  return;
}

