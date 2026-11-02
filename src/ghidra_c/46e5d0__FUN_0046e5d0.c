/* FUN_0046e5d0 @ 0046e5d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e5d0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined4 local_10;
  int *local_c;
  undefined4 local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (int *)0xdddddddd) {
    local_10 = 0;
    for (local_c = DAT_004e8908; local_c != (int *)0x0; local_c = (int *)local_c[1]) {
      if ((int *)*local_c == param_1) {
        if (local_c == DAT_004e8908) {
          DAT_004e8908 = (int *)local_c[1];
        }
        if (local_c == DAT_004e890c) {
          DAT_004e890c = (int *)local_c[2];
        }
        if (local_c[2] != 0) {
          *(int *)(local_c[2] + 4) = local_c[1];
        }
        if (local_c[1] != 0) {
          *(int *)(local_c[1] + 8) = local_c[2];
        }
        FUN_00439c30(local_c);
        break;
      }
    }
    local_8 = (uint)local_8._2_2_ << 0x10;
    while ((local_8 & 0xffff) < (uint)*(ushort *)((int)param_1 + 6)) {
      FUN_0046e580(*(PVOID *)(*param_1 + (local_8 & 0xffff) * 4));
      local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
    }
    FUN_00439c30((PVOID)*param_1);
    FUN_00439c30(param_1);
  }
  local_8 = 0x46e6fd;
  __chkesp();
  return;
}

