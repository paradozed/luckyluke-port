/* FUN_00425ec0 @ 00425ec0 */
/* decompiled from Lucky.exe (Game.run) */


int __fastcall FUN_00425ec0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0x10 - (uint)*(byte *)(param_1 + 1);
}

