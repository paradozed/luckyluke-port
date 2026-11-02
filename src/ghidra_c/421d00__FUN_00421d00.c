/* FUN_00421d00 @ 00421d00 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00421d00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)(param_1 + 0x7c) =
       *(undefined2 *)(*(int *)(param_1 + 0x88) + (uint)*(ushort *)(param_1 + 0x70) * 2);
  return;
}

