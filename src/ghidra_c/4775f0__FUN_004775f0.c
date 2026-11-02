/* FUN_004775f0 @ 004775f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004775f0(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 uStack_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  cVar1 = FUN_0043fc90(DAT_004e8788);
  if (cVar1 != '\0') {
    DAT_004e8986 = '\x01';
  }
  if ((DAT_004e8986 == '\0') && (DAT_004e898a == '\0')) {
    DAT_004be1a8 = 1;
  }
  else {
    if (DAT_004e8986 != '\0') {
      DAT_004be1a8 = 0;
      if ((DAT_004f2750 & 0x20) != 0) {
        DAT_004e89cd = '\x01';
        DAT_004e8990 = 1;
      }
      if ((DAT_004f2750 & 0x80) != 0) {
        DAT_004e89cd = '\0';
        DAT_004e8990 = 0;
      }
      if (((DAT_004f274c & 0x4000) != 0) || ((DAT_004f2750 & 8) != 0)) {
        if (DAT_004e89cd == '\0') {
          DAT_004e8990 = 0;
          DAT_004e898a = '\0';
          DAT_004e8986 = '\0';
          DAT_004e89cd = '\0';
          if (DAT_004e85b8 < 2) {
            while ((DAT_004f59dc & 0x80) != 0) {
              FUN_0045f3e0();
            }
            DAT_004be1a8 = 1;
          }
          else {
            DAT_004be1a8 = 1;
          }
        }
        else {
          DAT_004e898a = '\x01';
          DAT_004e8986 = '\0';
          DAT_004e89cd = '\0';
          DAT_004e8990 = 0;
        }
        goto LAB_004778cd;
      }
    }
    if (DAT_004e898a != '\0') {
      if ((DAT_004f2750 & 0x20) != 0) {
        DAT_004e89cc = '\0';
        DAT_004be1e8 = 1;
      }
      if ((DAT_004f2750 & 0x80) != 0) {
        DAT_004e89cc = '\x01';
        DAT_004be1e8 = 0;
      }
      if (((DAT_004f274c & 0x4000) != 0) || ((DAT_004f2750 & 8) != 0)) {
        if (DAT_004e89cc == '\0') {
          DAT_004e898a = '\0';
          DAT_004e8986 = '\x01';
          DAT_004be1e8 = 1;
          DAT_004e89cc = '\0';
        }
        else if (DAT_004e85b8 < 2) {
          DAT_004f1e20 = 1;
          DAT_004f1e21 = 1;
        }
        else {
          if (((DAT_004e8914 == 0x19) || (DAT_004e8914 == 3)) || (DAT_004e8914 == 0x1a)) {
            DAT_004f2c6c = DAT_004f2c7b;
          }
          DAT_004e898a = '\0';
          DAT_004f1e21 = 1;
          DAT_004e8986 = '\0';
          DAT_004e8914 = 1;
          DAT_004f1765 = 0;
          DAT_004e8988 = 1;
          DAT_004be1a8 = 1;
          DAT_004be1e8 = 1;
          DAT_004e89cc = '\0';
          DAT_004e8916 = 0;
          DAT_004e89c8 = 0;
          DAT_004e89c9 = 0;
          DAT_004e8813 = 0;
          DAT_004e861e = 0;
          DAT_004e861f = 0;
          DAT_004e898e = 0;
          DAT_004f16c8 = 0;
        }
      }
    }
  }
LAB_004778cd:
  uStack_8 = 0x4778da;
  __chkesp();
  return;
}

