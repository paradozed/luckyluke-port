/* FUN_0046ecf0 @ 0046ecf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046ecf0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [19];
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = DAT_004d1e7c +
          *(short *)(DAT_004d1e78 +
                    (uint)*(ushort *)(param_3 + (uint)*(ushort *)(param_1 + 6 + param_4 * 0x14) * 4)
                    * 4) * 0x14;
  *(ushort *)(param_2 + 0x1e + param_4 * 0x20) = (ushort)*(byte *)(iVar1 + 0x12);
  *(ushort *)(param_2 + 0x1e + param_4 * 0x20) =
       *(ushort *)(param_2 + 0x1e + param_4 * 0x20) | (ushort)*(byte *)(iVar1 + 0x13) << 8;
  return;
}

