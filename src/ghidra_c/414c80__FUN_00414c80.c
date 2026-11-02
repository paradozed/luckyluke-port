/* FUN_00414c80 @ 00414c80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00414c80(int param_1,void *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_48 [16];
  undefined1 *local_8;
  uint uVar3;
  
  puVar5 = local_48;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  uVar1 = FUN_004074b0(param_2,3);
  uVar2 = FUN_004074b0(param_2,2);
  uVar3 = CONCAT22(extraout_var,uVar2);
  iVar4 = FUN_00407580(param_1);
  local_8 = (undefined1 *)FUN_0046e930(*(int **)(iVar4 + 8),uVar3,uVar1);
  FUN_00414c50(local_8,1,0);
  local_8 = (undefined1 *)0x414ce2;
  __chkesp();
  return;
}

