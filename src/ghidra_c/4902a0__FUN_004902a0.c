/* FUN_004902a0 @ 004902a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004902a0(undefined4 param_1,int param_2,int param_3,int param_4)

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
    *(uint *)(param_4 + local_8 * 0x1c) = *(uint *)(param_4 + local_8 * 0x1c) & 0xffffff | 0x6000000
    ;
    *(undefined1 *)(param_4 + 7 + local_8 * 0x1c) = 0x30;
    *(uint *)(param_4 + 4 + local_8 * 0x1c) = *(uint *)(param_2 + 8 + local_8 * 0x14) & 0x3fffffff;
    *(uint *)(param_4 + 0xc + local_8 * 0x1c) =
         *(uint *)(param_2 + 0xc + local_8 * 0x14) & 0x3fffffff;
    *(uint *)(param_4 + 0x14 + local_8 * 0x1c) =
         *(uint *)(param_2 + 0x10 + local_8 * 0x14) & 0x3fffffff;
  }
  return;
}

