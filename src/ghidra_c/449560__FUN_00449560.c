/* FUN_00449560 @ 00449560 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00449560(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  short local_14;
  undefined1 local_10;
  int local_c;
  uint local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_14 = 0;
  DAT_004f2e0c = 0;
  if ((DAT_004f2e22 & 8) != 8) {
    (*DAT_004e8a28)();
    local_c = __chkesp();
    if (local_c != 0) {
      local_8 = local_8 & 0xffffff00;
      while ((local_8 & 0xff) < 0x20) {
        (*DAT_004e8a78)(local_c);
        __chkesp();
        (*DAT_004e8a6c)((undefined1)local_14);
        uVar1 = __chkesp();
        local_10 = (undefined1)uVar1;
        FUN_00449460('\x03',0,0,0);
        (*DAT_004e8a6c)(local_10);
        __chkesp();
        local_14 = local_14 + 8;
        if (0xff < local_14) {
          local_14 = 0xff;
        }
        FUN_00449380();
        local_8 = CONCAT31(local_8._1_3_,(char)local_8 + '\x01');
      }
    }
    DAT_004f2e22 = DAT_004f2e22 | 8;
  }
  local_8 = 0x44966a;
  __chkesp();
  return;
}

