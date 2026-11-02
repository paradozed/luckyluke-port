/* FUN_00465630 @ 00465630 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00465630(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8914 == 0x16) {
    *param_1 = 2;
    *param_2 = 0x14;
  }
  else {
    *param_1 = 2;
    if (DAT_004f2596 == 0) {
      *param_2 = 0x12;
    }
    else if (DAT_004f2596 == 1) {
      *param_2 = 0x14;
    }
    else {
      *param_2 = 0x16;
    }
  }
  return;
}

