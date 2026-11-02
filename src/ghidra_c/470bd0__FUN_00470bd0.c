/* FUN_00470bd0 @ 00470bd0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_00470bd0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = (uint)*(ushort *)(DAT_004d1e78 + param_1 * 4) * 0x14;
  return CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(DAT_004d1e7c + 0xe + iVar1));
}

