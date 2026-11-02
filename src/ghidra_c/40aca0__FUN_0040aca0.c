/* FUN_0040aca0 @ 0040aca0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040aca0(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_7c [16];
  int *local_3c;
  int *local_38;
  int local_34 [6];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  uint uVar3;
  
  puVar5 = local_7c;
  for (iVar4 = 0x1e; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_38 = *(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  uVar2 = FUN_004074b0(param_2,4);
  uVar3 = CONCAT22(extraout_var,uVar2);
  sVar1 = FUN_004074b0(param_2,3);
  local_3c = (int *)FUN_00473140(DAT_004f1804,sVar1,uVar3);
  if (local_3c == (int *)0x0) {
    local_3c = (int *)0x0;
  }
  else {
    local_1c = *local_3c;
    local_18 = local_3c[1];
    local_14 = local_3c[2];
    local_10 = local_3c[3];
    local_c = local_3c[4];
    local_8 = local_3c[5];
    local_3c = local_3c + 6;
    FUN_0040da10(local_38,0,local_34);
    FUN_0040d810(local_34,&local_1c);
  }
  local_8 = 0x40adac;
  __chkesp();
  return;
}

