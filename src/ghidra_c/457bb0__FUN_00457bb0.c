/* FUN_00457bb0 @ 00457bb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00457bb0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(int *)(param_1 + 8);
  FUN_0047ab10(param_1);
  local_c = (uint)local_c._2_2_ << 0x10;
  while ((local_c & 0xffff) < 3) {
    if (*(int *)(local_8 + 0x44 + (local_c & 0xffff) * 0xc) != 0) {
      (**(code **)(local_8 + 0x40 + (local_c & 0xffff) * 0xc))
                (local_8,local_8 + 0x40 + (local_c & 0xffff) * 0xc);
      __chkesp();
    }
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  local_8 = 0x457c5b;
  __chkesp();
  return;
}

