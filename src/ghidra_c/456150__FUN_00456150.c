/* FUN_00456150 @ 00456150 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_00456150(ushort param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [17];
  ushort local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  switch(param_1 & 0xf0) {
  case 0:
    local_8 = 8;
    break;
  case 0x10:
    local_8 = 2;
    break;
  case 0x20:
    local_8 = 0;
    break;
  case 0x30:
    local_8 = 1;
    break;
  case 0x40:
    local_8 = 6;
    break;
  default:
    local_8 = 8;
    break;
  case 0x60:
    local_8 = 7;
    break;
  case 0x80:
    local_8 = 4;
    break;
  case 0x90:
    local_8 = 3;
    break;
  case 0xc0:
    local_8 = 5;
  }
  return (uint)local_8;
}

