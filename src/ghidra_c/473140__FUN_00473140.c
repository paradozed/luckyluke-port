/* FUN_00473140 @ 00473140 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00473140(int *param_1,short param_2,uint param_3)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_54 [20];
  
  puVar4 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (param_1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    for (uVar2 = 0; uVar2 < *(ushort *)(param_1 + 1); uVar2 = uVar2 + 1) {
      if (9 < uVar2) {
        return 0;
      }
      uVar1 = *(uint *)(*param_1 + (uint)uVar2 * 4);
      if (((9999 < uVar1) && ((uVar1 & 0xa0000000) == 0)) && (*(short *)(uVar1 + 4) == param_2))
      break;
    }
    if (uVar2 < *(ushort *)(param_1 + 1)) {
      iVar3 = **(int **)(*param_1 + (uint)uVar2 * 4);
      iVar3 = iVar3 + *(int *)(iVar3 + (param_3 & 0xffff) * 4);
    }
    else {
      iVar3 = 0;
    }
  }
  return iVar3;
}

