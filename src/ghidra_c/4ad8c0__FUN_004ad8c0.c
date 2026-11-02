/* FUN_004ad8c0 @ 004ad8c0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_004ad8c0(uint param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 < DAT_00509260) &&
     (iVar2 = (int)param_1 >> 5,
     (*(byte *)((&DAT_00509160)[iVar2] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    cVar1 = *(char *)((&DAT_00509160)[iVar2] + 4 + (param_1 & 0x1f) * 8);
    if (param_2 == 0x8000) {
      *(byte *)((&DAT_00509160)[iVar2] + 4 + (param_1 & 0x1f) * 8) =
           *(byte *)((&DAT_00509160)[iVar2] + 4 + (param_1 & 0x1f) * 8) & 0x7f;
    }
    else {
      if (param_2 != 0x4000) {
        DAT_004e8c64 = 0x16;
        return -1;
      }
      *(byte *)((&DAT_00509160)[iVar2] + 4 + (param_1 & 0x1f) * 8) =
           *(byte *)((&DAT_00509160)[iVar2] + 4 + (param_1 & 0x1f) * 8) | 0x80;
    }
    iVar2 = (-(uint)(((int)cVar1 & 0x80U) != 0) & 0xffffc000) + 0x8000;
  }
  else {
    DAT_004e8c64 = 9;
    iVar2 = -1;
  }
  return iVar2;
}

