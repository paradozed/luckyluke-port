/* FUN_00477e30 @ 00477e30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00477e30(int param_1)

{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  undefined4 *puVar4;
  undefined4 local_4c [18];
  
  puVar4 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  puVar1 = *(ushort **)(param_1 + 8);
  for (uVar3 = 0; uVar3 < *puVar1; uVar3 = uVar3 + 1) {
    if (*(char *)(*(int *)(puVar1 + (uint)uVar3 * 2 + 2) + 9) == '\0') {
      *(int *)(*(int *)(puVar1 + (uint)uVar3 * 2 + 2) + 4) =
           *(int *)(*(int *)(puVar1 + (uint)uVar3 * 2 + 2) + 4) + -0x1aaaa;
    }
  }
  return;
}

