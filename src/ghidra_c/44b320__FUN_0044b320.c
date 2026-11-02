/* FUN_0044b320 @ 0044b320 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044b320(void)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 local_84 [16];
  uint local_44;
  char local_2c;
  undefined3 uStack_2b;
  int local_28;
  uint local_24;
  undefined4 local_20;
  int *local_14;
  uint local_10;
  int local_c;
  int *local_8;
  
  puVar5 = local_84;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_c = *DAT_004e8824;
  local_14 = (int *)((int)DAT_004e8824 + local_c);
  piVar4 = local_14;
  piVar6 = &DAT_004d1e84;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar6 = piVar6 + 1;
  }
  local_10 = local_14[1] * 0x14 + *local_14 * 4 + local_14[2] * 0x10;
  local_8 = local_14;
  FUN_00458ec0();
  DAT_004d1e78 = (undefined4 *)FUN_00494c40(local_10,1);
  FUN_00497690(DAT_004d1e78,local_8 + 7,local_10);
  DAT_004d1e7c = DAT_004d1e78 + *local_14;
  DAT_004d1e80 = DAT_004d1e78 + *local_14 + local_14[1] * 5;
  FUN_00458ec0();
  DAT_004d1e70 = FUN_00494c40(local_14[3] << 5,1);
  local_28 = (int)local_8 + local_10 + 0x1c;
  FUN_00458ec0();
  local_20 = (uint)local_20._2_2_ << 0x10;
  while ((int)(local_20 & 0xffff) < local_14[3]) {
    DAT_004d1e7c[(local_20 & 0xffff) * 5 + 2] = 0;
    _memset(*(void **)(DAT_004f58a4 + (local_20 & 0xffff) * 4),0,0x20000);
    local_24 = local_24 & 0xffff0000;
    while ((local_24 & 0xffff) < 0x2000) {
      local_44 = *(uint *)(local_28 + (local_24 & 0xffff) * 4);
      *(ushort *)(*(int *)(DAT_004f58a4 + (local_20 & 0xffff) * 4) + (local_24 & 0xffff) * 0x10) =
           (ushort)local_44 & 0xf;
      *(ushort *)(*(int *)(DAT_004f58a4 + (local_20 & 0xffff) * 4) + 2 + (local_24 & 0xffff) * 0x10)
           = (ushort)(local_44 >> 4) & 0xf;
      *(ushort *)(*(int *)(DAT_004f58a4 + (local_20 & 0xffff) * 4) + 4 + (local_24 & 0xffff) * 0x10)
           = (ushort)(local_44 >> 8) & 0xf;
      *(ushort *)(*(int *)(DAT_004f58a4 + (local_20 & 0xffff) * 4) + 6 + (local_24 & 0xffff) * 0x10)
           = (ushort)(local_44 >> 0xc) & 0xf;
      uVar1 = (ushort)(local_44 >> 0x10);
      *(ushort *)(*(int *)(DAT_004f58a4 + (local_20 & 0xffff) * 4) + 8 + (local_24 & 0xffff) * 0x10)
           = uVar1 & 0xf;
      *(ushort *)
       (*(int *)(DAT_004f58a4 + (local_20 & 0xffff) * 4) + 10 + (local_24 & 0xffff) * 0x10) =
           uVar1 >> 4 & 0xf;
      *(ushort *)
       (*(int *)(DAT_004f58a4 + (local_20 & 0xffff) * 4) + 0xc + (local_24 & 0xffff) * 0x10) =
           (byte)(local_44 >> 0x18) & 0xf;
      *(ushort *)
       (*(int *)(DAT_004f58a4 + (local_20 & 0xffff) * 4) + 0xe + (local_24 & 0xffff) * 0x10) =
           uVar1 >> 0xc;
      local_24 = CONCAT22(local_24._2_2_,(short)local_24 + 1);
    }
    *(undefined2 *)(DAT_004d1e70 + (local_20 & 0xffff) * 0x20) = 0;
    *(undefined2 *)(DAT_004d1e70 + 2 + (local_20 & 0xffff) * 0x20) = 0;
    *(undefined2 *)(DAT_004d1e70 + 4 + (local_20 & 0xffff) * 0x20) = 0x40;
    *(undefined2 *)(DAT_004d1e70 + 6 + (local_20 & 0xffff) * 0x20) = 0x100;
    *(short *)(DAT_004d1e70 + 0x1a + (local_20 & 0xffff) * 0x20) = (short)local_20;
    local_28 = local_28 + 0x8000;
    local_20 = CONCAT22(local_20._2_2_,(short)local_20 + 1);
  }
  FUN_00458ec0();
  local_20 = local_20 & 0xffff0000;
  while ((int)(local_20 & 0xffff) < local_14[1]) {
    cVar2 = '\x02' - ((byte)*(undefined2 *)(DAT_004d1e7c + (local_20 & 0xffff) * 5 + 3) & 3);
    _local_2c = CONCAT31(uStack_2b,cVar2);
    if (cVar2 == '\x02') {
      *(short *)(DAT_004d1e7c + (local_20 & 0xffff) * 5) =
           (short)((int)(uint)*(byte *)(DAT_004d1e7c + (local_20 & 0xffff) * 5 + 4) >> 2);
      *(ushort *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 2) =
           (ushort)*(byte *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 0x11);
      *(undefined2 *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 0xe) =
           *(undefined2 *)
            (DAT_004d1e70 + 0x1a +
            (uint)*(ushort *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 0xe) * 0x20);
      if (0xff < (int)*(short *)(DAT_004d1e7c + (local_20 & 0xffff) * 5) +
                 (int)*(short *)(DAT_004d1e7c + (local_20 & 0xffff) * 5 + 1)) {
        *(short *)(DAT_004d1e7c + (local_20 & 0xffff) * 5 + 1) =
             0xff - *(short *)(DAT_004d1e7c + (local_20 & 0xffff) * 5);
      }
      if (0xff < (int)*(short *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 2) +
                 (int)*(short *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 6)) {
        *(short *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 6) =
             0xff - *(short *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 2);
      }
    }
    *(undefined1 *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 0x12) =
         *(undefined1 *)(DAT_004d1e7c + (local_20 & 0xffff) * 5 + 4);
    *(undefined1 *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 0x13) =
         *(undefined1 *)((int)DAT_004d1e7c + (local_20 & 0xffff) * 0x14 + 0x11);
    local_20 = CONCAT22(local_20._2_2_,(short)local_20 + 1);
  }
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_0044aaa0();
  FUN_00458ec0();
  local_20 = local_20 & 0xffff0000;
  while ((local_20 & 0xffff) < 0x10) {
    (*DAT_004e8a24)(CONCAT31((int3)((local_20 & 0xffff) >> 8),(undefined1)local_20),
                    *(undefined4 *)(DAT_004f58a4 + (local_20 & 0xffff) * 4));
    __chkesp();
    local_20 = CONCAT22(local_20._2_2_,(short)local_20 + 1);
  }
  DAT_004e8601 = 1;
  local_8 = (int *)0x44b994;
  __chkesp();
  return;
}

