/* FUN_00470d90 @ 00470d90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470d90(int param_1,undefined2 *param_2)

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
  *param_2 = *(undefined2 *)(DAT_004d1e7c + uVar2 * 0x14);
  param_2[1] = *(undefined2 *)(DAT_004d1e7c + 2 + uVar2 * 0x14);
  param_2[2] = *(undefined2 *)(DAT_004d1e7c + 4 + uVar2 * 0x14);
  param_2[3] = *(undefined2 *)(DAT_004d1e7c + 6 + uVar2 * 0x14);
  return;
}

