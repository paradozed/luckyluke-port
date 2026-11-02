/* FUN_0047de90 @ 0047de90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0047de90(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  undefined4 *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = DAT_004e8a94; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)local_8[1]) {
    if (*(char *)(local_8 + 9) != '\0') {
      (*DAT_004e8a30)();
      __chkesp();
    }
    local_c = local_8[8];
    switch(local_c) {
    case 0:
      (*DAT_004e8a40)(*local_8,local_8[3],local_8[4],local_8[5]);
      __chkesp();
      break;
    case 1:
      (*DAT_004e8a44)(*local_8,local_8[3],local_8[4],local_8[5],local_8[6]);
      __chkesp();
      break;
    case 2:
      (*DAT_004e8a50)(*local_8,local_8[3],local_8[4],local_8[5]);
      __chkesp();
      break;
    case 3:
      (*DAT_004e8a54)(*local_8,local_8[3],local_8[4],local_8[5],local_8[6]);
      __chkesp();
      break;
    case 4:
      (*DAT_004e8a48)(*local_8,local_8[3],local_8[4],local_8[5]);
      __chkesp();
      break;
    case 5:
      (*DAT_004e8a4c)(*local_8,local_8[3],local_8[4],local_8[5],local_8[6]);
      __chkesp();
      break;
    case 6:
      (*DAT_004e8a58)(*local_8,local_8[3],local_8[4],local_8[5]);
      __chkesp();
      break;
    case 7:
      (*DAT_004e8a5c)(*local_8,local_8[3],local_8[4],local_8[5],local_8[6]);
      __chkesp();
    }
    if (7 < (uint)local_8[8]) {
      if ((int)local_8[3] < 0x11) {
        local_8[6] = 0x11;
        local_8[5] = 0x11;
        local_8[4] = 0x11;
        local_8[3] = 0x11;
      }
      (*DAT_004e8a60)(*local_8,local_8[8] + -8,local_8[3],local_8[4],local_8[5],local_8[6]);
      __chkesp();
    }
  }
  local_8 = (undefined4 *)0x47e128;
  __chkesp();
  return;
}

