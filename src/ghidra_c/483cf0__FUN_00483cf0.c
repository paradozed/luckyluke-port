/* FUN_00483cf0 @ 00483cf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00483cf0(ushort *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [17];
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < (int)(uint)*param_1; local_8 = local_8 + 1) {
    *(int *)(param_1 + local_8 * 2 + 6) = (int)param_1 + *(int *)(param_1 + local_8 * 2 + 6);
  }
  return;
}

