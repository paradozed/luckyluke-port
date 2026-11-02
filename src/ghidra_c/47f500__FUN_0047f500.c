/* FUN_0047f500 @ 0047f500 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047f500(int param_1,int param_2,int param_3)

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
    *(undefined2 *)(param_2 + local_8 * 8) = *(undefined2 *)(param_1 + local_8 * 8);
    *(undefined2 *)(param_2 + 2 + local_8 * 8) = *(undefined2 *)(param_1 + 2 + local_8 * 8);
    *(undefined2 *)(param_2 + 4 + local_8 * 8) = *(undefined2 *)(param_1 + 4 + local_8 * 8);
  }
  return;
}

