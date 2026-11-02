/* FUN_00484150 @ 00484150 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00484150(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
            uint param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [17];
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = param_7 & 0xffff; (int)local_8 < (int)(param_6 & 0xffff); local_8 = local_8 + 1) {
    *(byte *)(param_2 + 0x14 + local_8 * 0x28) =
         (byte)*(undefined2 *)(param_3 + local_8 * 0x14) |
         (byte)*(undefined2 *)(param_4 + local_8 * 0x14);
    if ((*(byte *)(param_2 + 0x14 + local_8 * 0x28) & 1) != 0) {
      iVar1 = (int)*(short *)(param_4 + 2 + local_8 * 0x14) -
              (int)*(short *)(param_3 + 2 + local_8 * 0x14);
      if (iVar1 < 0x801) {
        if (iVar1 < -0x800) {
          *(short *)(param_2 + 0x16 + local_8 * 0x28) =
               *(short *)(param_3 + 2 + local_8 * 0x14) +
               (short)((uint)((iVar1 + 0x1000) * param_5) >> 0x10);
        }
        else {
          *(short *)(param_2 + 0x16 + local_8 * 0x28) =
               *(short *)(param_3 + 2 + local_8 * 0x14) + (short)((uint)(iVar1 * param_5) >> 0x10);
        }
      }
      else {
        *(short *)(param_2 + 0x16 + local_8 * 0x28) =
             *(short *)(param_3 + 2 + local_8 * 0x14) +
             (short)((uint)((iVar1 + -0x1000) * param_5) >> 0x10);
      }
      iVar1 = (int)*(short *)(param_4 + 4 + local_8 * 0x14) -
              (int)*(short *)(param_3 + 4 + local_8 * 0x14);
      if (iVar1 < 0x801) {
        if (iVar1 < -0x800) {
          *(short *)(param_2 + 0x18 + local_8 * 0x28) =
               *(short *)(param_3 + 4 + local_8 * 0x14) +
               (short)((uint)((iVar1 + 0x1000) * param_5) >> 0x10);
        }
        else {
          *(short *)(param_2 + 0x18 + local_8 * 0x28) =
               *(short *)(param_3 + 4 + local_8 * 0x14) + (short)((uint)(iVar1 * param_5) >> 0x10);
        }
      }
      else {
        *(short *)(param_2 + 0x18 + local_8 * 0x28) =
             *(short *)(param_3 + 4 + local_8 * 0x14) +
             (short)((uint)((iVar1 + -0x1000) * param_5) >> 0x10);
      }
      iVar1 = (int)*(short *)(param_4 + 6 + local_8 * 0x14) -
              (int)*(short *)(param_3 + 6 + local_8 * 0x14);
      if (iVar1 < 0x801) {
        if (iVar1 < -0x800) {
          *(short *)(param_2 + 0x1a + local_8 * 0x28) =
               *(short *)(param_3 + 6 + local_8 * 0x14) +
               (short)((uint)((iVar1 + 0x1000) * param_5) >> 0x10);
        }
        else {
          *(short *)(param_2 + 0x1a + local_8 * 0x28) =
               *(short *)(param_3 + 6 + local_8 * 0x14) + (short)((uint)(iVar1 * param_5) >> 0x10);
        }
      }
      else {
        *(short *)(param_2 + 0x1a + local_8 * 0x28) =
             *(short *)(param_3 + 6 + local_8 * 0x14) +
             (short)((uint)((iVar1 + -0x1000) * param_5) >> 0x10);
      }
    }
    if ((*(byte *)(param_2 + 0x14 + local_8 * 0x28) & 2) != 0) {
      *(short *)(param_2 + 0x1c + local_8 * 0x28) =
           *(short *)(param_3 + 8 + local_8 * 0x14) +
           (short)((uint)(((int)*(short *)(param_4 + 8 + local_8 * 0x14) -
                          (int)*(short *)(param_3 + 8 + local_8 * 0x14)) * param_5) >> 0x10);
      *(short *)(param_2 + 0x1e + local_8 * 0x28) =
           *(short *)(param_3 + 10 + local_8 * 0x14) +
           (short)((uint)(((int)*(short *)(param_4 + 10 + local_8 * 0x14) -
                          (int)*(short *)(param_3 + 10 + local_8 * 0x14)) * param_5) >> 0x10);
      *(short *)(param_2 + 0x20 + local_8 * 0x28) =
           *(short *)(param_3 + 0xc + local_8 * 0x14) +
           (short)((uint)(((int)*(short *)(param_4 + 0xc + local_8 * 0x14) -
                          (int)*(short *)(param_3 + 0xc + local_8 * 0x14)) * param_5) >> 0x10);
    }
    if ((*(byte *)(param_2 + 0x14 + local_8 * 0x28) & 4) != 0) {
      *(short *)(param_2 + 0x22 + local_8 * 0x28) =
           *(short *)(param_3 + 0xe + local_8 * 0x14) +
           (short)((uint)(((int)*(short *)(param_4 + 0xe + local_8 * 0x14) -
                          (int)*(short *)(param_3 + 0xe + local_8 * 0x14)) * param_5) >> 0x10);
      *(short *)(param_2 + 0x24 + local_8 * 0x28) =
           *(short *)(param_3 + 0x10 + local_8 * 0x14) +
           (short)((uint)(((int)*(short *)(param_4 + 0x10 + local_8 * 0x14) -
                          (int)*(short *)(param_3 + 0x10 + local_8 * 0x14)) * param_5) >> 0x10);
      *(short *)(param_2 + 0x26 + local_8 * 0x28) =
           *(short *)(param_3 + 0x12 + local_8 * 0x14) +
           (short)((uint)(((int)*(short *)(param_4 + 0x12 + local_8 * 0x14) -
                          (int)*(short *)(param_3 + 0x12 + local_8 * 0x14)) * param_5) >> 0x10);
    }
  }
  return;
}

