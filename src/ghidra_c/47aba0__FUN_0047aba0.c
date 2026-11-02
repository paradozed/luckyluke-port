/* FUN_0047aba0 @ 0047aba0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047aba0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_58 [21];
  
  puVar5 = local_58;
  for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  iVar4 = **(int **)(param_1 + 8);
  iVar1 = *(int *)(*(int *)(iVar4 + 8) + 0x90);
  iVar2 = *(int *)(*(int *)(iVar4 + 8) + 0x94);
  iVar3 = *(int *)(*(int *)(iVar4 + 8) + 0x98);
  if (((iVar1 < 0xdac) || (0x2904 < iVar1)) || (iVar2 < -2000)) {
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x14) = 1;
    *(int *)(iVar4 + 0x90) = iVar1;
    *(int *)(iVar4 + 0x94) = iVar2;
    *(int *)(iVar4 + 0x98) = 20000 - iVar3;
  }
  return;
}

