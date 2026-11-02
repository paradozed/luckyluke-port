/* FUN_0046ea00 @ 0046ea00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046ea00(char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = local_18 & 0xffffff00;
  local_8 = *(int *)(param_1 + 4);
  local_c = *(int *)(local_8 + 0x28);
  local_10 = *(int *)(local_c + 8);
  local_14 = (DAT_004e8abc >> 5) - *(int *)(local_8 + 8);
  while (*(uint *)(local_10 + (uint)*(ushort *)(local_8 + 4) * 0xc) < local_14) {
    local_14 = local_14 - *(int *)(local_10 + (uint)*(ushort *)(local_8 + 4) * 0xc);
    *(int *)(local_8 + 8) =
         *(int *)(local_8 + 8) + *(int *)(local_10 + (uint)*(ushort *)(local_8 + 4) * 0xc);
    if ((*(char *)(local_8 + 0x12) == '\0') &&
       (*(short *)(local_8 + 4) == *(short *)(local_8 + 0xe))) {
      local_18 = CONCAT31(local_18._1_3_,1);
    }
    else if (*(char *)(local_8 + 0x13) == '\0') {
      if ((int)(uint)*(ushort *)(local_8 + 4) < (int)(*(ushort *)(local_c + 2) - 1)) {
        *(short *)(local_8 + 4) = *(short *)(local_8 + 4) + 1;
      }
      else {
        *(undefined2 *)(local_8 + 4) = 0;
      }
    }
    else if (*(short *)(local_8 + 4) == 0) {
      *(short *)(local_8 + 4) = *(short *)(local_c + 2) + -1;
    }
    else {
      *(short *)(local_8 + 4) = *(short *)(local_8 + 4) + -1;
    }
  }
  if (((local_18 & 0xff) == 0) && (*(short *)(local_8 + 4) != *(short *)(local_8 + 6))) {
    *(undefined2 *)(local_8 + 6) = *(undefined2 *)(local_8 + 4);
    FUN_0046e2f0(*(int *)(local_10 + 4 + (uint)*(ushort *)(local_8 + 4) * 0xc),
                 (uint)*(ushort *)(local_8 + 0x10),*param_1);
  }
  local_8 = 0x46ebae;
  __chkesp();
  return;
}

