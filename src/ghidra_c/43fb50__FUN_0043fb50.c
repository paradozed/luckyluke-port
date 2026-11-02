/* FUN_0043fb50 @ 0043fb50 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0043fb50(uint param_1)

{
  uint3 uVar2;
  uint uVar1;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [17];
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (uint3)(param_1 >> 8);
  if (param_1 < 4) {
    uVar1 = 0xcccccccc;
    switch(param_1) {
    case 0:
      if (DAT_004f5ac4 < 0) {
        uVar1 = CONCAT31(uVar2,1);
      }
      else {
        uVar1 = (uint)uVar2 << 8;
      }
      break;
    case 1:
      if (DAT_004f5ac4 < 1) {
        uVar1 = (uint)uVar2 << 8;
      }
      else {
        uVar1 = CONCAT31(uVar2,1);
      }
      break;
    case 2:
      if (DAT_004f5ac0 < 0) {
        uVar1 = CONCAT31(uVar2,1);
      }
      else {
        uVar1 = (uint)uVar2 << 8;
      }
      break;
    case 3:
      if (DAT_004f5ac0 < 1) {
        uVar1 = (uint)uVar2 << 8;
      }
      else {
        uVar1 = CONCAT31(uVar2,1);
      }
      break;
    default:
      goto switchD_0043fb98_default;
    }
  }
  else {
    uVar1 = param_1;
    if (((&DAT_004f5aec)[param_1] & 0x80) != 0) {
      return CONCAT31(uVar2,1);
    }
switchD_0043fb98_default:
    uVar1 = uVar1 & 0xffffff00;
  }
  return uVar1;
}

