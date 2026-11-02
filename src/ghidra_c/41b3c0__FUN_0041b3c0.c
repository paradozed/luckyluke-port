/* FUN_0041b3c0 @ 0041b3c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0041b3c0(byte *param_1,short param_2,short param_3,short param_4,short param_5,short param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  undefined2 *local_10;
  short local_c;
  undefined4 local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = (undefined2 *)FUN_0046e8d0((int)param_2);
  if ((param_1[1] == 5) || (param_1[1] == 7)) {
    local_8 = CONCAT22(local_8._2_2_,*(undefined2 *)(*(int *)(local_10 + 4) + 4));
  }
  else if (param_3 == -1) {
    local_8 = CONCAT22(local_8._2_2_,*local_10);
  }
  else {
    local_8 = CONCAT22(local_8._2_2_,*(undefined2 *)(DAT_004e8820 + 4 + param_3 * 4));
  }
  local_14 = (int)param_6;
  if (local_14 == -1) {
    FUN_00485a70(param_1,(int)local_10,(undefined2)local_8,0,0,1,0,(int)param_4);
  }
  else if (local_14 == 0) {
    local_c = FUN_0041b500((int)local_10);
    local_c = local_c + -1;
    FUN_00485a70(param_1,(int)local_10,(undefined2)local_8,param_5,local_c,0,0,(int)param_4);
  }
  else {
    local_c = param_5 + -1 + param_6;
    FUN_00485a70(param_1,(int)local_10,(undefined2)local_8,param_5,local_c,0,0,(int)param_4);
  }
  local_8 = 0x41b4f9;
  __chkesp();
  return;
}

