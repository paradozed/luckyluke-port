/* FUN_00482760 @ 00482760 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00482760(undefined4 *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  undefined4 uStack_8;
  
  puVar11 = local_54;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar11 = 0xcccccccc;
    puVar11 = puVar11 + 1;
  }
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  DAT_00508850 = *(short *)(param_1 + 4);
  DAT_00508840 = (short)uVar1;
  DAT_00508842 = (short)((uint)uVar1 >> 0x10);
  DAT_00508844 = (short)uVar2;
  local_14 = (int)DAT_00508840 * *param_2 + (int)DAT_00508842 * param_2[1] +
             (int)DAT_00508844 * param_2[2] >> 0xc;
  DAT_00508846 = (short)((uint)uVar2 >> 0x10);
  DAT_00508848 = (short)uVar3;
  DAT_0050884a = (short)((uint)uVar3 >> 0x10);
  local_10 = (int)DAT_00508846 * *param_2 + (int)DAT_00508848 * param_2[1] +
             (int)DAT_0050884a * param_2[2] >> 0xc;
  DAT_0050884c = (short)uVar4;
  iVar9 = (int)DAT_0050884c;
  iVar8 = *param_2;
  DAT_0050884e = (short)((uint)uVar4 >> 0x10);
  iVar10 = (int)DAT_0050884e;
  iVar5 = param_2[1];
  iVar7 = (int)DAT_00508850;
  iVar6 = param_2[2];
  _DAT_00508840 = uVar1;
  _DAT_00508844 = uVar2;
  _DAT_00508848 = uVar3;
  _DAT_0050884c = uVar4;
  *param_3 = local_14;
  param_3[1] = local_10;
  param_3[2] = iVar9 * iVar8 + iVar10 * iVar5 + iVar7 * iVar6 >> 0xc;
  uStack_8 = 0x482818;
  __chkesp();
  return;
}

