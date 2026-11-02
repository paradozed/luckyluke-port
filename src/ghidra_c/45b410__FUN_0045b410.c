/* FUN_0045b410 @ 0045b410 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045b410(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = param_1 & 0xffff;
  if (local_20 == 0) {
    FUN_004594c0();
  }
  else {
    if (local_20 == 1) {
      if (((DAT_004f2750 & 0x80) != 0) && (DAT_004e871c != 0)) {
        DAT_004e871c = DAT_004e871c - 1;
      }
      if (((DAT_004f2750 & 0x20) != 0) && ((int)(uint)DAT_004e871c < (int)(DAT_004e89fa - 1))) {
        DAT_004e871c = DAT_004e871c + 1;
      }
    }
    else if (local_20 != 2) {
      FUN_00497610((byte *)"Error: File %s, Line %d");
      goto LAB_0045b751;
    }
    local_10 = local_10 & 0xffff0000;
    while ((local_10 & 0xffff) == 0) {
      FUN_004594c0();
      if (*(short *)(DAT_004e89f0 + ((uint)DAT_004e871c + (local_10 & 0xffff)) * 0x20) != 0) {
        local_c = local_c & 0xffff0000;
        while ((local_c & 0xffff) <
               (uint)*(ushort *)(DAT_004e89f0 + ((uint)DAT_004e871c + (local_10 & 0xffff)) * 0x20))
        {
          FUN_004266b0();
          local_14 = local_14 +
                     *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 +
                                               ((uint)DAT_004e871c + (local_10 & 0xffff)) * 0x20) +
                                      (local_c & 0xffff) * 4) + 0x10);
          local_18 = local_18 +
                     *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 +
                                               ((uint)DAT_004e871c + (local_10 & 0xffff)) * 0x20) +
                                      (local_c & 0xffff) * 4) + 0x2c);
          local_1c = local_1c +
                     *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 +
                                               ((uint)DAT_004e871c + (local_10 & 0xffff)) * 0x20) +
                                      (local_c & 0xffff) * 4) + 0x48) * 2;
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
        }
      }
      local_10 = CONCAT22(local_10._2_2_,(short)local_10 + 1);
    }
    FUN_004594c0();
    FUN_004594c0();
  }
LAB_0045b751:
  local_8 = 0x45b75e;
  __chkesp();
  return;
}

