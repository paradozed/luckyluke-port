/* FUN_0040e5f0 @ 0040e5f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040e5f0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_2 = *(undefined4 *)(param_1 + 0xa4);
  param_2[3] = *(undefined4 *)(param_1 + 0xb0);
  param_2[1] = *(undefined4 *)(param_1 + 0xa8);
  param_2[4] = *(undefined4 *)(param_1 + 0xb4);
  param_2[2] = *(undefined4 *)(param_1 + 0xac);
  param_2[5] = *(undefined4 *)(param_1 + 0xb8);
  return;
}

