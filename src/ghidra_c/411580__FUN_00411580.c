/* FUN_00411580 @ 00411580 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411580(int param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  undefined2 extraout_var;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_74 [16];
  int local_34;
  undefined4 *local_30;
  int *local_2c;
  int local_28 [2];
  int local_20;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  uint uVar3;
  
  puVar5 = local_74;
  for (iVar4 = 0x1c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_30 = (undefined4 *)FUN_00407580(param_1);
  local_34 = *(int *)local_30[2];
  uVar1 = FUN_004074b0(param_2,3);
  uVar3 = CONCAT22(extraout_var,uVar1);
  sVar2 = FUN_004074b0(param_2,2);
  local_2c = (int *)FUN_00473140(DAT_004f1804,sVar2,uVar3);
  if (local_2c != (int *)0x0) {
    FUN_00411c90(local_34,*local_2c,local_2c[1],local_2c[2]);
    (*(code *)*local_30)(local_30);
    __chkesp();
    FUN_0047fbe0(local_34,local_28);
    local_8 = *local_2c - local_28[0];
    local_c = local_2c[1] - local_18;
    local_10 = local_2c[2] - local_20;
    FUN_00411c90(local_34,local_8,local_c,local_10);
  }
  local_8 = 0x41166d;
  __chkesp();
  return;
}

