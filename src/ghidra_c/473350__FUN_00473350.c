/* FUN_00473350 @ 00473350 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00473350(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  ushort *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  if ((param_1 != -0x22222223) &&
     (local_8 = *(ushort **)(param_1 + 8), local_8 != (ushort *)0xdddddddd)) {
    for (local_c = 0; local_c < (int)(uint)*local_8; local_c = local_c + 1) {
      FUN_0047f190(*(byte **)(*(int *)(local_8 + 8) + local_c * 0x20));
      if (*(int *)(*(int *)(local_8 + 8) + local_c * 0x20) != 0) {
        FUN_00439c30(*(PVOID *)(*(int *)(local_8 + 8) + local_c * 0x20));
        *(undefined4 *)(*(int *)(local_8 + 8) + local_c * 0x20) = 0;
      }
    }
    FUN_00439c30(*(PVOID *)(local_8 + 8));
    if (local_8 != (ushort *)0x0) {
      FUN_00439c30(local_8);
    }
  }
  local_8 = (ushort *)0x473443;
  __chkesp();
  return;
}

