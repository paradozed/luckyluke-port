/* FUN_00486270 @ 00486270 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00486270(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_00470bd0(param_2 & 0xffff);
  *(short *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0x16) = (short)uVar1;
  uVar1 = FUN_00470c20(param_2 & 0xffff);
  *(short *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0xe) = (short)uVar1;
  uStack_8 = 0x4862da;
  __chkesp();
  return;
}

