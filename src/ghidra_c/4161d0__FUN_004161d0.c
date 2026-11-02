/* FUN_004161d0 @ 004161d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004161d0(int param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 extraout_var;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_50 [16];
  uint *local_10;
  int local_c;
  int local_8;
  uint uVar4;
  
  puVar6 = local_50;
  for (iVar5 = 0x13; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_c = **(int **)(local_8 + 8);
  uVar1 = FUN_004074b0(param_2,3);
  uVar4 = CONCAT22(extraout_var,uVar1);
  sVar2 = FUN_004074b0(param_2,2);
  local_10 = (uint *)FUN_00473140(DAT_004f1804,sVar2,uVar4);
  if (local_10 != (uint *)0x0) {
    if (*local_10 < 0x12d) {
      if (local_10[4] == 0) {
        FUN_004074b0(param_2,3);
        FUN_004074b0(param_2,2);
        FUN_00497610((byte *)"LinkPerso3DX2Path %d %d\n");
      }
      else {
        uVar3 = FUN_004074b0(param_2,4);
        FUN_00470860(local_c,(int)local_10,uVar3);
      }
    }
    else {
      FUN_004074b0(param_2,3);
      FUN_004074b0(param_2,2);
      FUN_00497610((byte *)"LinkPerso3DX2Path %d %d\n");
    }
  }
  local_8 = 0x4162c2;
  __chkesp();
  return;
}

