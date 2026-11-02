/* FUN_00474e90 @ 00474e90 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_00474e90(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar2 = (param_1 & 0xffff) - 2;
  switch(param_1 & 0xffff) {
  case 2:
  case 3:
  case 5:
  case 7:
  case 9:
  case 10:
  case 0xb:
  case 0xd:
  case 0xf:
  case 0x11:
  case 0x12:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
    uVar2 = CONCAT31((int3)(uVar2 >> 8),1);
    break;
  default:
    uVar2 = uVar2 & 0xffffff00;
  }
  return uVar2;
}

