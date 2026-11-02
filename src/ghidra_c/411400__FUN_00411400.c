/* FUN_00411400 @ 00411400 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411400(int param_1,void *param_2)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  short sVar3;
  undefined2 extraout_var;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  uint uVar4;
  
  puVar6 = local_54;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  local_10 = FUN_00407580(param_1);
  local_14 = **(int **)(local_10 + 8);
  uVar2 = FUN_004074b0(param_2,3);
  uVar4 = CONCAT22(extraout_var,uVar2);
  sVar3 = FUN_004074b0(param_2,2);
  local_8 = (undefined4 *)FUN_00473140(DAT_004f1804,sVar3,uVar4);
  if (local_8 != (undefined4 *)0x0) {
    FUN_00411c90(local_14,*local_8,local_8[1],local_8[2]);
    local_c = local_8 + 3;
    puVar6 = local_8 + 5;
    puVar1 = local_8 + 4;
    local_8 = local_c;
    FUN_00411680(local_14,(short)*local_c,(short)*puVar1,(short)*puVar6);
  }
  local_8 = (undefined4 *)0x4114bd;
  __chkesp();
  return;
}

