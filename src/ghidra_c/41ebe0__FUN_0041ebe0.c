/* FUN_0041ebe0 @ 0041ebe0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0041ebe0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_5c [16];
  uint local_1c;
  LPCSTR local_18;
  uint local_14;
  int local_10;
  uint *local_c;
  uint *local_8;
  
  puVar3 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = *(int *)(DAT_004e8824 + 4);
  if (local_10 != 0) {
    DAT_004d238e = 0;
    DAT_004d2880 = 0;
    local_8 = (uint *)(DAT_004e8824 + local_10);
    local_14 = *local_8;
    local_c = local_8 + 1;
    FUN_00458ec0();
    local_1c = local_1c & 0xffff0000;
    while ((local_1c & 0xffff) < local_14) {
      local_18 = (LPCSTR)((int)local_8 + *local_c);
      local_c = local_c + 1;
      if (DAT_004bcfd0 != 0) {
        uVar1 = FUN_004930f0(local_18,1,0);
        *(undefined4 *)(&DAT_004d2790 + (local_1c & 0xffff) * 4) = uVar1;
      }
      local_1c = CONCAT22(local_1c._2_2_,(short)local_1c + 1);
    }
  }
  if (DAT_004bcfd0 == 0) {
    local_1c = local_1c & 0xffff0000;
    while ((local_1c & 0xffff) < 0x3c) {
      *(undefined4 *)(&DAT_004d2790 + (local_1c & 0xffff) * 4) = 0;
      local_1c = CONCAT22(local_1c._2_2_,(short)local_1c + 1);
    }
  }
  local_8 = (uint *)0x41ecfd;
  __chkesp();
  return;
}

