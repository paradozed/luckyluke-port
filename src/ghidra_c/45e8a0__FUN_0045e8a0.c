/* FUN_0045e8a0 @ 0045e8a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045e8a0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(&DAT_004f2604 + param_1 * 0x14) = 2;
  *(int *)(&DAT_004f2600 + param_1 * 0x14) = param_1;
  *(undefined4 *)(&DAT_004f2608 + param_1 * 0x14) = param_2;
  return;
}

