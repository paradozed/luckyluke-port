/* FUN_004156c0 @ 004156c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004156c0(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  undefined2 extraout_var;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_48 [16];
  undefined4 local_8;
  uint uVar3;
  
  puVar4 = local_48;
  for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_004074b0(param_2,3);
  uVar3 = CONCAT22(extraout_var,uVar1);
  sVar2 = FUN_004074b0(param_2,2);
  puVar4 = (undefined4 *)FUN_00473140(DAT_004f1804,sVar2,uVar3);
  if (puVar4 != (undefined4 *)0x0) {
    DAT_004f2e10 = *puVar4;
    DAT_004f2e14 = puVar4[1];
    DAT_004f2e18 = puVar4[2];
    DAT_004f2e1c = 1;
  }
  local_8 = 0x41573d;
  __chkesp();
  return;
}

