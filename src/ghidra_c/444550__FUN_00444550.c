/* FUN_00444550 @ 00444550 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00444550(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = DAT_004e8578; local_8 != (int *)0x0; local_8 = (int *)local_8[4]) {
    if (*local_8 == param_2) {
      *local_8 = 0;
    }
  }
  *param_1 = param_2;
  return;
}

