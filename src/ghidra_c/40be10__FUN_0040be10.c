/* FUN_0040be10 @ 0040be10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040be10(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_80 [16];
  short *local_40;
  int *local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  uint uVar3;
  
  puVar6 = local_80;
  for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_38 = *(int *)(&DAT_004f13c0 + sVar1 * 0x2c);
  uVar2 = FUN_004074b0(param_2,4);
  uVar3 = CONCAT22(extraout_var,uVar2);
  sVar1 = FUN_004074b0(param_2,3);
  local_3c = (int *)FUN_00473140(DAT_004f1804,sVar1,uVar3);
  if (local_3c == (int *)0x0) {
    local_3c = (int *)0x0;
  }
  else {
    local_34 = *local_3c;
    local_30 = local_3c[1];
    local_2c = local_3c[2];
    local_28 = local_3c[3];
    local_24 = local_3c[4];
    local_20 = local_3c[5];
    local_3c = local_3c + 6;
    FUN_0040b070(local_38,&local_1c);
    local_10 = local_10 + *(int *)(local_38 + 0x90);
    local_1c = local_1c + *(int *)(local_38 + 0x90);
    local_c = local_c + *(int *)(local_38 + 0x94);
    local_18 = local_18 + *(int *)(local_38 + 0x94);
    local_8 = local_8 + *(int *)(local_38 + 0x98);
    local_14 = local_14 + *(int *)(local_38 + 0x98);
    uVar4 = FUN_0040d810(&local_34,&local_1c);
    if ((short)uVar4 != 0) {
      sVar1 = FUN_004074b0(param_2,2);
      local_40 = (short *)(&DAT_004f13e0 + sVar1 * 0x2c);
      *local_40 = *local_40 + -1;
      sVar1 = FUN_004074b0(param_2,2);
      *(undefined2 *)(&DAT_004f13ca + sVar1 * 0x2c) = 0;
    }
  }
  local_8 = 0x40bfb6;
  __chkesp();
  return;
}

