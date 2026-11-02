/* FUN_00478030 @ 00478030 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00478030(short param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = 0;
  while( true ) {
    if (*DAT_004f13a0 <= uVar1) {
      return;
    }
    if (**(short **)(DAT_004f13a0 + (uint)uVar1 * 2 + 2) == param_1) break;
    uVar1 = uVar1 + 1;
  }
  *(undefined1 *)(*(int *)(DAT_004f13a0 + (uint)uVar1 * 2 + 2) + 9) = 0;
  return;
}

