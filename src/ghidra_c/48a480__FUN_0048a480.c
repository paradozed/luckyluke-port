/* FUN_0048a480 @ 0048a480 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048a480(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; local_8 = param_1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = local_8 + -1, -1 < local_8) {
    *(char *)(param_2 + 4 + local_8 * 0x28) =
         (char)((uint)*(byte *)(param_2 + 4 + local_8 * 0x28) * param_3 >> 8);
    *(char *)(param_2 + 5 + local_8 * 0x28) =
         (char)((uint)*(byte *)(param_2 + 5 + local_8 * 0x28) * param_3 >> 8);
    *(char *)(param_2 + 6 + local_8 * 0x28) =
         (char)((uint)*(byte *)(param_2 + 6 + local_8 * 0x28) * param_3 >> 8);
    *(char *)(param_2 + 0x10 + local_8 * 0x28) =
         (char)((uint)*(byte *)(param_2 + 0x10 + local_8 * 0x28) * param_3 >> 8);
    *(char *)(param_2 + 0x11 + local_8 * 0x28) =
         (char)((uint)*(byte *)(param_2 + 0x11 + local_8 * 0x28) * param_3 >> 8);
    *(char *)(param_2 + 0x12 + local_8 * 0x28) =
         (char)((uint)*(byte *)(param_2 + 0x12 + local_8 * 0x28) * param_3 >> 8);
    *(char *)(param_2 + 0x1c + local_8 * 0x28) =
         (char)((uint)*(byte *)(param_2 + 0x1c + local_8 * 0x28) * param_3 >> 8);
    *(char *)(param_2 + 0x1d + local_8 * 0x28) =
         (char)((uint)*(byte *)(param_2 + 0x1d + local_8 * 0x28) * param_3 >> 8);
    *(char *)(param_2 + 0x1e + local_8 * 0x28) =
         (char)((uint)*(byte *)(param_2 + 0x1e + local_8 * 0x28) * param_3 >> 8);
  }
  return;
}

