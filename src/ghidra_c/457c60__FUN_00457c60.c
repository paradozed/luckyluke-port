/* FUN_00457c60 @ 00457c60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00457c60(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  uint local_c;
  int local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1[2];
  local_c = local_c & 0xffff0000;
  while ((local_c & 0xffff) < 3) {
    if (*(int *)(local_8 + 0x44 + (local_c & 0xffff) * 0xc) != 0) {
      local_10 = *(int *)(local_8 + 0x44 + (local_c & 0xffff) * 0xc);
      *(undefined4 *)(local_8 + 0x44 + (local_c & 0xffff) * 0xc) =
           *(undefined4 *)(*(int *)(&DAT_004f1e40 + local_10 * 4) + 8);
    }
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  *param_1 = FUN_00457bb0;
  (*(code *)*param_1)(param_1);
  __chkesp();
  local_8 = 0x457d1a;
  __chkesp();
  return;
}

