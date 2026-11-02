/* FUN_004852c0 @ 004852c0 */
/* decompiled from Lucky.exe (Game.run) */


bool __cdecl FUN_004852c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return (*(uint *)(param_1 + 8) & 0x80000000) != 0;
}

