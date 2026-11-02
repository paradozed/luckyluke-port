/* FUN_00485680 @ 00485680 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00485680(short *param_1,short param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 == 0) {
    *param_1 = param_2;
  }
  else {
    *param_1 = *param_1 + -1;
  }
  return;
}

