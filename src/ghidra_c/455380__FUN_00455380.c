/* FUN_00455380 @ 00455380 */
/* decompiled from Lucky.exe (Game.run) */


uint FUN_00455380(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_48 [17];
  
  puVar4 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = (uint)DAT_004e866a;
  if (0x1d9 < (int)uVar1) {
    uVar3 = uVar1 - 0x1ef;
    switch(uVar1) {
    case 0x1ef:
    case 0x205:
    case 0x21b:
    case 0x231:
    case 0x247:
    case 0x25d:
    case 0x275:
    case 0x28b:
      goto switchD_004553d4_caseD_d7;
    default:
switchD_004553d4_caseD_d9:
      return uVar3 & 0xffffff00;
    }
  }
  uVar3 = uVar1;
  if (uVar1 == 0x1d9) {
switchD_004553d4_caseD_d7:
    return CONCAT31((int3)(uVar3 >> 8),1);
  }
  uVar3 = uVar1 - 0xd7;
  switch(uVar1) {
  case 0xd7:
  case 0xd8:
  case 0x103:
  case 0x105:
  case 0x106:
  case 0x107:
  case 0x119:
  case 0x11d:
  case 0x12f:
  case 0x133:
  case 0x145:
  case 0x1c3:
    goto switchD_004553d4_caseD_d7;
  default:
    goto switchD_004553d4_caseD_d9;
  }
}

