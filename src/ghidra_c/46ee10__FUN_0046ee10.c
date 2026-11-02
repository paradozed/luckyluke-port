/* FUN_0046ee10 @ 0046ee10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046ee10(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [17];
  uint local_c;
  int *local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != 0) {
    local_8 = *(int **)(param_1 + 8);
    local_c = local_c & 0xffff0000;
    while ((local_c & 0xffff) < (uint)*(ushort *)(local_8 + 1)) {
      FUN_0046ea00(*(char **)(*local_8 + (local_c & 0xffff) * 4));
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
  }
  local_8 = (int *)0x46ee88;
  __chkesp();
  return;
}

