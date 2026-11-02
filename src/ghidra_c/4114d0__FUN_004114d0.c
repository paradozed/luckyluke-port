/* FUN_004114d0 @ 004114d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004114d0(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  undefined2 extraout_var;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_48 [16];
  int *local_8;
  uint uVar3;
  
  puVar5 = local_48;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  uVar1 = FUN_004074b0(param_2,3);
  uVar3 = CONCAT22(extraout_var,uVar1);
  sVar2 = FUN_004074b0(param_2,2);
  local_8 = (int *)FUN_00473140(DAT_004f1804,sVar2,uVar3);
  if (DAT_004e85b8 == 0x11) {
    sVar2 = FUN_004074b0(param_2,3);
    if ((sVar2 == 0x22) && (local_8 != (int *)0x0)) {
      *local_8 = *local_8 + 2000;
      local_8[1] = local_8[1] + -2000;
    }
  }
  if (local_8 != (int *)0x0) {
    FUN_00497690((undefined4 *)&DAT_004e85d8,local_8,0x10);
  }
  local_8 = (int *)0x411576;
  __chkesp();
  return;
}

