/* FUN_00441340 @ 00441340 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00441340(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004e8914 == 5) && (DAT_004bcdd4 != '\0')) {
    local_18 = 0xe0;
    local_17 = 0xb0;
    local_16 = 0x80;
    local_14 = (undefined2)((DAT_004be3c8 * 10) / 0x280);
    local_10 = (undefined2)((DAT_004be3c8 * 600) / 0x280);
    local_c = (undefined2)((DAT_004be3c8 * 10) / 0x280);
    local_12 = (undefined2)((DAT_004be3cc * 200) / 0x1e0);
    local_e = (undefined2)((DAT_004be3cc * 200) / 0x1e0);
    local_a = (undefined2)((DAT_004be3cc * 0x1df) / 0x1e0);
    local_8 = CONCAT22((short)((DAT_004be3cc * 0x1df) / 0x1e0),(short)((DAT_004be3c8 * 600) / 0x280)
                      );
    local_1c = 0;
    local_15 = 0;
    (*DAT_004e8a30)();
    __chkesp();
    (*DAT_004e8a44)(&local_1c,64000,64000,64000,64000);
    __chkesp();
  }
  local_8 = 0x4414c2;
  __chkesp();
  return;
}

