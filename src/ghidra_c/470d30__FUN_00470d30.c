/* FUN_00470d30 @ 00470d30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470d30(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar2 = (uint)*(ushort *)(DAT_004d1e78 + param_1 * 4);
  *param_2 = *(undefined1 *)(DAT_004d1e7c + 0x12 + uVar2 * 0x14);
  *param_3 = *(undefined1 *)(DAT_004d1e7c + 0x13 + uVar2 * 0x14);
  return;
}

