/* FUN_004add10 @ 004add10 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004add10(uint param_1,uint param_2)

{
  uint uVar1;
  BOOL BVar2;
  uint local_8;
  
  if ((param_1 & 0xffff) == 0xffff) {
    uVar1 = 0;
  }
  else {
    if ((param_1 & 0xffff) < 0x100) {
      local_8 = (uint)*(ushort *)(PTR_DAT_004c6fe0 + (param_1 & 0xffff) * 2);
    }
    else {
      BVar2 = FUN_004addb0(1,(LPCWSTR)&param_1,1,(LPWORD)&local_8,0,0);
      if (BVar2 == 0) {
        return 0;
      }
    }
    uVar1 = local_8 & 0xffff & param_2 & 0xffff;
  }
  return uVar1;
}

