/* FUN_00425ba0 @ 00425ba0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00425ba0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  int local_10;
  uint local_c;
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = 0;
  local_c = local_c & 0xffff0000;
  while ((local_c & 0xffff) < 0x10) {
    uVar1 = FUN_00494840(0x4020);
    *(undefined4 *)(local_8 + 4 + (local_c & 0xffff) * 4) = uVar1;
    if (*(int *)(local_8 + 4 + (local_c & 0xffff) * 4) == 0) break;
    *(undefined4 *)(*(int *)(local_8 + 4 + (local_c & 0xffff) * 4) + 4) = 0x4000;
    *(undefined4 *)(*(int *)(local_8 + 4 + (local_c & 0xffff) * 4) + 0x10) = 1;
    **(int **)(local_8 + 4 + (local_c & 0xffff) * 4) =
         *(int *)(local_8 + 4 + (local_c & 0xffff) * 4) + 0x20;
    local_10 = local_10 + 0x4020;
    waveOutPrepareHeader
              (*(HWAVEOUT *)(local_8 + 0x48),*(LPWAVEHDR *)(local_8 + 4 + (local_c & 0xffff) * 4),
               0x20);
    __chkesp();
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  local_8 = 0x425cbd;
  __chkesp();
  return;
}

