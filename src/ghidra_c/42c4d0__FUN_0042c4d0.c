/* FUN_0042c4d0 @ 0042c4d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042c4d0(char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_70 [16];
  undefined4 local_30 [2];
  short local_28;
  short local_20;
  int local_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 3;
  while (*param_1 != '\0') {
    if (*(int *)(&DAT_004f6140 + *param_1 * 4) == 0) {
      param_1 = param_1 + 1;
    }
    else if (*param_1 == ' ') {
      local_8 = local_8 + 0x10;
      param_1 = param_1 + 1;
    }
    else {
      FUN_00497690(local_30,*(undefined4 **)(&DAT_004f6544 + *param_1 * 0xc),0x28);
      local_20 = (short)(((longlong)
                          (int)(((longlong)(int)local_20 * (longlong)DAT_004be3c8 & 0xffffffffU) /
                               0x280) * (longlong)DAT_004bcfe0 & 0xffffffffU) / 100);
      local_8 = local_8 + ((int)local_20 - (int)local_28);
      param_1 = param_1 + 1;
    }
  }
  local_8 = 0x42c5b6;
  __chkesp();
  return;
}

