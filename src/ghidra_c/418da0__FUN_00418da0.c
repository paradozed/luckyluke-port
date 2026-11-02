/* FUN_00418da0 @ 00418da0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418da0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  ushort *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (ushort *)(DAT_004e8820 + *(int *)(DAT_004e8820 + 4 + param_1 * 4));
  iVar1 = FUN_00483d50((int)local_8);
  if (iVar1 == 0) {
    FUN_00483cf0(local_8);
  }
  local_8 = (ushort *)0x418dfc;
  __chkesp();
  return;
}

