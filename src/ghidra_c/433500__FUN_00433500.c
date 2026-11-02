/* FUN_00433500 @ 00433500 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00433500(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  iVar2 = FUN_00442670('\x01');
  if (iVar2 != 0) {
    iVar2 = FUN_00442860("Language",(LPBYTE)&local_10);
    if (iVar2 != 0) {
      DAT_004bc760 = local_10;
    }
    FUN_00442770();
  }
  if (DAT_004bc760 == -1) {
    GetUserDefaultLangID();
    uVar1 = __chkesp();
    local_c = CONCAT22(local_c._2_2_,(short)uVar1) & 0xffff03ff;
    local_14 = (uVar1 & 0x3ff) - 7;
    switch(uVar1 & 0x3ff) {
    case 7:
      DAT_004bc760 = 2;
      break;
    default:
      DAT_004bc760 = 0;
      break;
    case 9:
      DAT_004bc760 = 0;
      break;
    case 10:
      DAT_004bc760 = 3;
      break;
    case 0xc:
      DAT_004bc760 = 1;
      break;
    case 0x10:
      DAT_004bc760 = 4;
      break;
    case 0x13:
      DAT_004bc760 = 5;
      break;
    case 0x16:
      DAT_004bc760 = 6;
    }
  }
  local_8 = 0x433613;
  __chkesp();
  return;
}

