/* FUN_004014c0 @ 004014c0 */
/* decompiled from Lucky.exe (Game.run) */


bool __fastcall FUN_004014c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(int *)(param_1 + 0xd8) - 1U <= *(uint *)(param_1 + 0x60);
}

