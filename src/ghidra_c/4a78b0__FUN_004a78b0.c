/* FUN_004a78b0 @ 004a78b0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004a78b0(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_1 < DAT_00509260) &&
      (iVar2 = (int)param_1 >> 5,
      (*(byte *)((&DAT_00509160)[iVar2] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) &&
     (*(int *)((&DAT_00509160)[iVar2] + (param_1 & 0x1f) * 8) != -1)) {
    if (DAT_004c6f84 == 1) {
      if (param_1 == 0) {
        SetStdHandle(0xfffffff6,(HANDLE)0x0);
      }
      else if (param_1 == 1) {
        SetStdHandle(0xfffffff5,(HANDLE)0x0);
      }
      else if (param_1 == 2) {
        SetStdHandle(0xfffffff4,(HANDLE)0x0);
      }
    }
    *(undefined4 *)((&DAT_00509160)[iVar2] + (param_1 & 0x1f) * 8) = 0xffffffff;
    uVar1 = 0;
  }
  else {
    DAT_004e8c64 = 9;
    DAT_004e8c68 = 0;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

