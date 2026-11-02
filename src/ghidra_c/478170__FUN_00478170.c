/* FUN_00478170 @ 00478170 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00478170(short param_1,int param_2)

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
  for (uVar1 = 0; uVar1 < *DAT_004f13a0; uVar1 = uVar1 + 1) {
    if (**(short **)(DAT_004f13a0 + (uint)uVar1 * 2 + 2) == param_1) {
      *(int *)(*(int *)(DAT_004f13a0 + (uint)uVar1 * 2 + 2) + 4) = param_2 << 0x10;
    }
  }
  return;
}

