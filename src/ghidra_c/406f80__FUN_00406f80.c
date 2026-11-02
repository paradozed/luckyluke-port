/* FUN_00406f80 @ 00406f80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00406f80(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00407580(param_1);
  local_c = *(undefined4 *)(**(int **)(iVar1 + 8) + 0xcc);
  local_8 = 0x406fe6;
  __chkesp();
  return;
}

