/* FUN_004597b0 @ 004597b0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004597b0(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  bVar1 = 0;
  while (*(int *)(param_1 + 0xc + (uint)bVar1 * 4) != 0) {
    bVar1 = bVar1 + 1;
  }
  return CONCAT31(0xcccccc,bVar1);
}

