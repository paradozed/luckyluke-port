/* FUN_004ad540 @ 004ad540 */
/* decompiled from Lucky.exe (Game.run) */


uint __fastcall FUN_004ad540(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  size_t sVar2;
  undefined4 local_8;
  
  uVar1 = param_3 & 0xffff;
  if (uVar1 == 0xffff) {
    uVar1 = param_3 & 0xffff;
  }
  else if (DAT_004e8e98 == 0) {
    if ((0x40 < (param_3 & 0xffff)) && ((param_3 & 0xffff) < 0x5b)) {
      uVar1 = (param_3 & 0xffff) + 0x20;
      param_3 = uVar1 & 0xffff;
    }
    uVar1 = CONCAT22((short)(uVar1 >> 0x10),(undefined2)param_3);
  }
  else {
    local_8 = param_1;
    if (((param_3 & 0xffff) < 0x100) &&
       (uVar1 = FUN_004add10(CONCAT22((short)((uint)param_2 >> 0x10),(undefined2)param_3),1),
       uVar1 == 0)) {
      return param_3 & 0xffff;
    }
    sVar2 = FUN_004ad9c0(DAT_004e8e98,0x100,(LPCWSTR)&param_3,1,(LPWSTR)&local_8,1,0);
    if (sVar2 == 0) {
      uVar1 = param_3 & 0xffff;
    }
    else {
      uVar1 = CONCAT22((short)(sVar2 >> 0x10),(WCHAR)local_8);
    }
  }
  return uVar1;
}

