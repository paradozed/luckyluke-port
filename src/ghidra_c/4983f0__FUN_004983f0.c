/* FUN_004983f0 @ 004983f0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004983f0(uint param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint local_10;
  
  if ((param_2 == (int *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4bafc0,0x2d,0,(byte *)"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  param_2[1] = param_2[1] + -1;
  if (param_2[1] < 0) {
    local_10 = FUN_0049d920(param_1,param_2);
  }
  else {
    *(undefined1 *)*param_2 = (undefined1)param_1;
    local_10 = param_1 & 0xff;
    *param_2 = *param_2 + 1;
  }
  return local_10;
}

