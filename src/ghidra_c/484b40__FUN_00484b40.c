/* FUN_00484b40 @ 00484b40 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00484b40(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (*(short *)(param_1 + 0x26) == 0) {
    uVar1 = (uint)**(short **)(param_1 + 0xc);
  }
  else {
    uVar1 = (int)**(short **)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 0x26) >> 0xc;
  }
  return uVar1 << 5;
}

