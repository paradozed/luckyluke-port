/* FUN_00459e90 @ 00459e90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00459e90(uint param_1,ushort param_2)

{
  int iVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 local_4c [18];
  
  puVar3 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  *(uint *)(&DAT_004e86a8 + (uint)DAT_004e89d8 * 0x28) =
       *(uint *)(&DAT_004e86a8 + (uint)DAT_004e89d8 * 0x28) & 0xffffff | 0x9000000;
  (&DAT_004e86af)[(uint)DAT_004e89d8 * 0x28] = 0x2c;
  (&DAT_004e86ac)[(uint)DAT_004e89d8 * 0x28] = 0x80;
  (&DAT_004e86ad)[(uint)DAT_004e89d8 * 0x28] = 0x80;
  (&DAT_004e86ae)[(uint)DAT_004e89d8 * 0x28] = 0x80;
  *(ushort *)(&DAT_004e86be + (uint)DAT_004e89d8 * 0x28) =
       (param_2 & 3) << 7 | (ushort)((int)((param_1 & 0x10) << 4) >> 4) |
       (ushort)((int)((param_1 & 0xf) << 6) >> 6);
  *(undefined2 *)(&DAT_004e86b6 + (uint)DAT_004e89d8 * 0x28) = 0x30;
  sVar2 = (short)(0x100 >> ((byte)param_2 & 0x1f));
  sVar2 = sVar2 - (ushort)(sVar2 == 0x100);
  (&DAT_004e86b4)[(uint)DAT_004e89d8 * 0x28] = 0;
  (&DAT_004e86b5)[(uint)DAT_004e89d8 * 0x28] = 0;
  (&DAT_004e86bc)[(uint)DAT_004e89d8 * 0x28] = (char)sVar2;
  (&DAT_004e86bd)[(uint)DAT_004e89d8 * 0x28] = 0;
  (&DAT_004e86c4)[(uint)DAT_004e89d8 * 0x28] = 0;
  (&DAT_004e86c5)[(uint)DAT_004e89d8 * 0x28] = 0xff;
  (&DAT_004e86cc)[(uint)DAT_004e89d8 * 0x28] = (char)sVar2;
  (&DAT_004e86cd)[(uint)DAT_004e89d8 * 0x28] = 0xff;
  *(short *)(&DAT_004e86b0 + (uint)DAT_004e89d8 * 0x28) = 0x1f0 - sVar2;
  *(undefined2 *)(&DAT_004e86b2 + (uint)DAT_004e89d8 * 0x28) = 0x10;
  *(undefined2 *)(&DAT_004e86b8 + (uint)DAT_004e89d8 * 0x28) = 0x1f0;
  *(undefined2 *)(&DAT_004e86ba + (uint)DAT_004e89d8 * 0x28) = 0x10;
  *(short *)(&DAT_004e86c0 + (uint)DAT_004e89d8 * 0x28) = 0x1f0 - sVar2;
  *(undefined2 *)(&DAT_004e86c2 + (uint)DAT_004e89d8 * 0x28) = 0xe0;
  *(undefined2 *)(&DAT_004e86c8 + (uint)DAT_004e89d8 * 0x28) = 0x1f0;
  *(undefined2 *)(&DAT_004e86ca + (uint)DAT_004e89d8 * 0x28) = 0xe0;
  return;
}

