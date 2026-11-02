/* FUN_00447810 @ 00447810 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00447810(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_2 = (0xfff - (uint)*(ushort *)(param_1 + 0x24)) * 0x10;
  param_2[-1] = (0xfff - (uint)*(ushort *)(param_1 + 0x24)) * 0x10;
  param_2[-2] = (0xfff - (uint)*(ushort *)(param_1 + 0x24)) * 0x10;
  param_2[-3] = (0xfff - (uint)*(ushort *)(param_1 + 0x24)) * 0x10;
  FUN_0047d8b0();
  uStack_8 = 0x44789d;
  __chkesp();
  return;
}

