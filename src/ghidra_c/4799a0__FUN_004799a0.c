/* FUN_004799a0 @ 004799a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004799a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(code **)(param_1 + 4) = FUN_004799d0;
  return;
}

