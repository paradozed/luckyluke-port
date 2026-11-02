/* FUN_00473240 @ 00473240 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_00473240(int *param_1,short param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [19];
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = 0;
  while ((uVar1 < *(ushort *)(param_1 + 1) &&
         (*(short *)(*(int *)(*param_1 + (uint)uVar1 * 4) + 4) != param_2))) {
    uVar1 = uVar1 + 1;
  }
  return *(uint *)**(undefined4 **)(*param_1 + (uint)uVar1 * 4) >> 2;
}

