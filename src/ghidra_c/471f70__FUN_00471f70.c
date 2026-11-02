/* FUN_00471f70 @ 00471f70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00471f70(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(&DAT_004f1c20 + param_1 * 4) != 0) {
    *(undefined4 *)(&DAT_004f1ca0 + param_1 * 4) = 1;
  }
  return;
}

