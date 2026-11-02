/* FUN_0049f740 @ 0049f740 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_0049f740(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  if ((param_1 == (undefined4 *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4bb444,0x41,0,(byte *)"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  iVar2 = __isatty(param_1[4]);
  if (iVar2 == 0) {
    return 0;
  }
  if (param_1 == (undefined4 *)&DAT_004c7280) {
    local_c = 0;
  }
  else {
    if (param_1 != (undefined4 *)&DAT_004c72a0) {
      return 0;
    }
    local_c = 1;
  }
  DAT_004e8d00 = DAT_004e8d00 + 1;
  if ((param_1[3] & 0x10c) != 0) {
    return 0;
  }
  if (*(int *)(&DAT_004e8cf8 + local_c * 4) == 0) {
    uVar3 = FUN_00494860(0x1000,2,0x4bb444,0x5e);
    *(undefined4 *)(&DAT_004e8cf8 + local_c * 4) = uVar3;
    if (*(int *)(&DAT_004e8cf8 + local_c * 4) == 0) {
      param_1[2] = param_1 + 5;
      *param_1 = param_1[2];
      param_1[6] = 2;
      param_1[1] = 2;
      goto LAB_0049f879;
    }
  }
  param_1[2] = *(undefined4 *)(&DAT_004e8cf8 + local_c * 4);
  *param_1 = param_1[2];
  param_1[6] = 0x1000;
  param_1[1] = 0x1000;
LAB_0049f879:
  param_1[3] = param_1[3] | 0x1102;
  return 1;
}

