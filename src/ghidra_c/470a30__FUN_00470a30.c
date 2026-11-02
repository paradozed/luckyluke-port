/* FUN_00470a30 @ 00470a30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470a30(int param_1,short param_2)

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
  if (param_2 == 0) {
    *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) & 0xfff7;
    if ((*(ushort *)(param_1 + 0x40) & 0x30) != 0) {
      FUN_0047c7f0((undefined2 *)(*(int *)(param_1 + 0x48) + 0x5c),*(short *)(param_1 + 0x44),
                   *(short *)(param_1 + 0x42),0);
    }
  }
  else {
    *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) | 8;
    if ((*(ushort *)(param_1 + 0x40) & 0x30) != 0) {
      FUN_0047c7f0((undefined2 *)(*(int *)(param_1 + 0x48) + 0x5c),-*(short *)(param_1 + 0x44),
                   -*(short *)(param_1 + 0x42),0);
    }
  }
  uStack_8 = 0x470aef;
  __chkesp();
  return;
}

