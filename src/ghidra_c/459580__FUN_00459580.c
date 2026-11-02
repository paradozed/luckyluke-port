/* FUN_00459580 @ 00459580 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00459580(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  undefined2 local_14;
  undefined2 local_10;
  undefined4 local_c;
  int *local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = *(int **)(param_1 + 8);
  if (((DAT_004f2744 == 0x300) || (DAT_004e8706 != '\0')) || (DAT_004e8700 != '\0')) {
    DAT_004e8706 = '\x01';
    for (; local_8[1] != 0; local_8 = (int *)local_8[1]) {
    }
    uVar1 = FUN_004597b0((int)local_8);
    FUN_00459730((ushort *)(local_8 + 2),
                 CONCAT31((int3)((uint)extraout_EDX >> 8),(char)uVar1) & 0xffff00ff);
    local_c = (uint)local_c._2_2_ << 0x10;
    while (local_8[(local_c & 0xffff) + 3] != 0) {
      if ((uint)*(ushort *)(local_8 + 2) == (local_c & 0xffff)) {
        DAT_004f282c = DAT_004f2830;
        if (DAT_004f2750 == *(uint *)(local_8[(local_c & 0xffff) + 3] + 4)) {
          local_10 = 2;
        }
        else {
          local_10 = 1;
        }
      }
      else {
        DAT_004f282c = DAT_004f2a0c;
        local_10 = 0;
      }
      local_14 = (undefined2)local_8[2];
      *(short *)(local_8 + 2) = (short)local_c;
      (**(code **)(local_8[(local_c & 0xffff) + 3] + 8))(local_10,local_8);
      __chkesp();
      *(undefined2 *)(local_8 + 2) = local_14;
      if (((DAT_004f2750 & 0x1000) != 0) && (DAT_004f2744 == 0x1000)) {
        if (*local_8 == 0) {
          DAT_004e8706 = '\0';
        }
        else {
          *(undefined4 *)(*local_8 + 4) = 0;
          *(undefined2 *)(local_8 + 2) = 0;
        }
      }
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
  }
  local_8 = (int *)0x459727;
  __chkesp();
  return;
}

