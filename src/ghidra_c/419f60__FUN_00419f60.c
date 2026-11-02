/* FUN_00419f60 @ 00419f60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00419f60(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = **(int **)(param_1 + 8);
  local_c = **(int **)(param_2 + 8);
  FUN_00486d00(local_8,local_c);
  *(undefined1 *)(param_1 + 0x10) = 1;
  local_8 = 0x419fb2;
  __chkesp();
  return;
}

