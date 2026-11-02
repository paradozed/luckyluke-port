/* FUN_0049d3d0 @ 0049d3d0 */
/* decompiled from Lucky.exe (Game.run) */


undefined1 * __cdecl FUN_0049d3d0(undefined4 param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint *puVar1;
  int local_10;
  int *local_c;
  undefined1 *local_8;
  
  if (DAT_004e8cec == '\0') {
    local_c = (int *)FUN_004a69b0();
    FUN_004a68b0(param_2 + (uint)(0 < param_3) + (uint)(*local_c == 0x2d),param_3 + 1,(int)local_c);
  }
  else {
    local_c = DAT_004e8ce8;
    __shift(param_2 + (*DAT_004e8ce8 == 0x2d),(uint)(0 < param_3));
  }
  local_8 = param_2;
  if (*local_c == 0x2d) {
    *param_2 = 0x2d;
    local_8 = param_2 + 1;
  }
  if (0 < param_3) {
    *local_8 = local_8[1];
    local_8 = local_8 + 1;
    *local_8 = DAT_004c71ec;
  }
  puVar1 = FUN_00497270((uint *)(local_8 + (uint)(DAT_004e8cec == '\0') + param_3),(uint *)"e+000");
  if (param_4 != 0) {
    *(undefined1 *)puVar1 = 0x45;
  }
  if (*(char *)local_c[3] != '0') {
    local_10 = local_c[1] + -1;
    if (local_10 < 0) {
      local_10 = -local_10;
      *(undefined1 *)((int)puVar1 + 1) = 0x2d;
    }
    if (99 < local_10) {
      *(char *)((int)puVar1 + 2) = *(char *)((int)puVar1 + 2) + (char)(local_10 / 100);
      local_10 = local_10 % 100;
    }
    if (9 < local_10) {
      *(char *)((int)puVar1 + 3) = *(char *)((int)puVar1 + 3) + (char)(local_10 / 10);
      local_10 = local_10 % 10;
    }
    *(char *)(puVar1 + 1) = (char)puVar1[1] + (char)local_10;
  }
  return param_2;
}

