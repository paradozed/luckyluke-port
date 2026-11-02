/* FUN_00490380 @ 00490380 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00490380(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; local_8 = param_3, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = local_8 + -1, -1 < local_8) {
    *(uint *)(param_1 + local_8 * 0xc) = param_4 + (uint)*(ushort *)(param_2 + local_8 * 0x14) * 8;
    *(uint *)(param_1 + 4 + local_8 * 0xc) =
         param_4 + (uint)*(ushort *)(param_2 + 2 + local_8 * 0x14) * 8;
    *(uint *)(param_1 + 8 + local_8 * 0xc) =
         param_4 + (uint)*(ushort *)(param_2 + 4 + local_8 * 0x14) * 8;
  }
  return;
}

