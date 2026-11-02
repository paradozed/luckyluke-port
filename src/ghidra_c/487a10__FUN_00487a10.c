/* FUN_00487a10 @ 00487a10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00487a10(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_2 < *param_3) {
    local_8 = *param_2;
  }
  else {
    local_8 = *param_3;
  }
  *param_1 = local_8;
  if (param_3[3] < param_2[3]) {
    local_c = param_2[3];
  }
  else {
    local_c = param_3[3];
  }
  param_1[3] = local_c;
  if (param_2[1] < param_3[1]) {
    local_10 = param_2[1];
  }
  else {
    local_10 = param_3[1];
  }
  param_1[1] = local_10;
  if (param_3[4] < param_2[4]) {
    local_14 = param_2[4];
  }
  else {
    local_14 = param_3[4];
  }
  param_1[4] = local_14;
  if (param_2[2] < param_3[2]) {
    local_18 = param_2[2];
  }
  else {
    local_18 = param_3[2];
  }
  param_1[2] = local_18;
  if (param_3[5] < param_2[5]) {
    local_1c = param_2[5];
  }
  else {
    local_1c = param_3[5];
  }
  param_1[5] = local_1c;
  return;
}

