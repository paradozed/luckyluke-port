/* FUN_00487ec0 @ 00487ec0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00487ec0(short param_1,undefined2 *param_2,undefined2 param_3,undefined2 param_4,
            undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 == 0) {
    *param_2 = param_3;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[4] = 0;
    param_2[5] = param_7;
    param_2[6] = param_8;
  }
  else if (param_1 == 1) {
    *param_2 = 0;
    param_2[1] = param_4;
    param_2[2] = 0;
    param_2[4] = param_6;
    param_2[5] = 0;
    param_2[6] = param_8;
  }
  else if (param_1 == 2) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = param_5;
    param_2[4] = param_6;
    param_2[5] = param_7;
    param_2[6] = 0;
  }
  return;
}

