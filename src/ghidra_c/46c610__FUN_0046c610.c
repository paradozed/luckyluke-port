/* FUN_0046c610 @ 0046c610 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046c610(uint param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_70 [16];
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  short local_28;
  undefined2 uStack_26;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar4 = local_70;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_14 = *(int *)(*DAT_004f2458 + 0x90);
  local_10 = *(int *)(*DAT_004f2458 + 0x94);
  local_c = *(int *)(*DAT_004f2458 + 0x98);
  sVar2 = FUN_00467130(*DAT_004f2458);
  _local_28 = CONCAT22(uStack_26,sVar2);
  sVar1 = *(short *)(&DAT_004be0c0 + (param_1 & 0xffff) * 8);
  sVar2 = FUN_00482c60(sVar2);
  local_24 = (int)sVar1 * (int)sVar2;
  sVar1 = *(short *)(&DAT_004be0c4 + (param_1 & 0xffff) * 8);
  sVar2 = FUN_00482cb0((short)_local_28);
  local_24 = local_24 + (int)sVar1 * (int)sVar2 >> 0xc;
  local_20 = (int)*(short *)(&DAT_004be0c2 + (param_1 & 0xffff) * 8);
  sVar1 = *(short *)(&DAT_004be0c4 + (param_1 & 0xffff) * 8);
  sVar2 = FUN_00482c60((short)_local_28);
  local_1c = -(int)sVar1 * (int)sVar2;
  sVar1 = *(short *)(&DAT_004be0c0 + (param_1 & 0xffff) * 8);
  sVar2 = FUN_00482cb0((short)_local_28);
  local_1c = local_1c - (int)sVar1 * (int)sVar2 >> 0xc;
  local_14 = local_14 + local_24;
  local_10 = local_10 + local_20;
  local_c = local_c + local_1c;
  local_30 = 0;
  local_2e = DAT_004f13a4;
  local_2c = DAT_004f1670;
  FUN_00476b40(&local_14,(int)&local_30,1,2);
  uStack_8 = 0x46c7a1;
  __chkesp();
  return;
}

