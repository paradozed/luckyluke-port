/* FUN_00482820 @ 00482820 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00482820(undefined4 *param_1,short *param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short sVar5;
  short sVar6;
  short sVar7;
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
  local_14 = (int)DAT_00508840 * (int)*param_2 + (int)DAT_00508842 * (int)param_2[1] +
             (int)DAT_00508844 * (int)param_2[2] >> 0xc;
  DAT_00508846 = (short)((uint)uVar2 >> 0x10);
  DAT_00508848 = (short)uVar3;
  DAT_0050884a = (short)((uint)uVar3 >> 0x10);
  local_10 = (int)DAT_00508846 * (int)*param_2 + (int)DAT_00508848 * (int)param_2[1] +
             (int)DAT_0050884a * (int)param_2[2] >> 0xc;
  DAT_0050884c = (short)uVar4;
  iVar8 = (int)DAT_0050884c;
  sVar5 = *param_2;
  DAT_0050884e = (short)((uint)uVar4 >> 0x10);
  iVar9 = (int)DAT_0050884e;
  sVar6 = param_2[1];
  iVar10 = (int)DAT_00508850;
  sVar7 = param_2[2];
  _DAT_00508840 = uVar1;
  _DAT_00508844 = uVar2;
  _DAT_00508848 = uVar3;
  _DAT_0050884c = uVar4;
  *param_3 = local_14;
  param_3[1] = local_10;
  param_3[2] = iVar8 * sVar5 + iVar9 * sVar6 + iVar10 * sVar7 >> 0xc;
  uStack_8 = 0x4828ea;
  __chkesp();
  return;
}

