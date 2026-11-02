/* FUN_00471aa0 @ 00471aa0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00471aa0(void)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 local_5c [16];
  undefined8 local_1c;
  uint local_14;
  uint local_10;
  undefined8 local_c;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8954 = DAT_004e8954 + 1;
  local_c = __allmul(DAT_004e8954 - _DAT_004e8938,DAT_004e8954 - _DAT_004e8938 >> 0x1f,DAT_004e8948,
                     DAT_004e894c);
  if (DAT_004be114 == 0) {
    QueryPerformanceCounter((LARGE_INTEGER *)&DAT_004e8928);
    __chkesp();
  }
  else {
    uVar4 = FUN_00497360();
    DAT_004e8928 = (uint)uVar4;
    DAT_004e892c = (int)DAT_004e8928 >> 0x1f;
  }
  local_14 = DAT_004e8928 - DAT_004e8930;
  local_10 = (DAT_004e892c - DAT_004e8934) - (uint)(DAT_004e8928 < DAT_004e8930);
  if (((int)local_10 < 1) && ((int)local_10 < 0)) {
    local_14 = DAT_004be108;
    local_10 = DAT_004be10c;
  }
  _DAT_004e8958 = 0;
  if ((local_c._4_4_ < (int)local_10) ||
     ((local_c._4_4_ <= (int)local_10 && ((uint)local_c <= local_14)))) {
    lVar5 = __allmul(local_14 - (uint)local_c,
                     (local_10 - local_c._4_4_) - (uint)(local_14 < (uint)local_c),2,0);
    local_1c._4_4_ = (int)((ulonglong)lVar5 >> 0x20);
    if ((DAT_004e894c <= local_1c._4_4_) &&
       ((DAT_004e894c < local_1c._4_4_ ||
        (local_1c._0_4_ = (uint)lVar5, DAT_004e8948 < (uint)local_1c)))) {
      _DAT_004e8958 = 1;
    }
  }
  else {
    bVar3 = CARRY4(DAT_004e8968,(uint)local_c - local_14);
    DAT_004e8968 = DAT_004e8968 + ((uint)local_c - local_14);
    DAT_004e896c = DAT_004e896c + ((local_c._4_4_ - local_10) - (uint)((uint)local_c < local_14)) +
                   (uint)bVar3;
    lVar5 = local_1c;
    if (DAT_004e895c == 0) {
      FUN_00472280((uint)local_c - local_14,
                   (local_c._4_4_ - local_10) - (uint)((uint)local_c < local_14));
      lVar5 = local_1c;
    }
  }
  local_1c = lVar5;
  if (((int)DAT_004be10c <= (int)local_10) &&
     (((int)DAT_004be10c < (int)local_10 || (DAT_004be108 <= local_14)))) {
    DAT_004e8950 = DAT_004e8954 - _DAT_004e8938;
    bVar3 = CARRY4(DAT_004e8930,DAT_004be108);
    DAT_004e8930 = DAT_004e8930 + DAT_004be108;
    DAT_004e8934 = DAT_004e8934 + DAT_004be10c + (uint)bVar3;
    _DAT_004e8938 = DAT_004e8954;
    DAT_004e8960 = DAT_004e8968;
    DAT_004e8964 = DAT_004e896c;
    lVar5 = __allmul(DAT_004e8968,DAT_004e896c,100,0);
    uVar4 = __alldiv((uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20),DAT_004be108,DAT_004be10c);
    _DAT_004e8970 = (undefined4)uVar4;
    DAT_004e8968 = 0;
    DAT_004e896c = 0;
  }
  local_c = CONCAT44(0x471cd6,(uint)local_c);
  __chkesp();
  return;
}

