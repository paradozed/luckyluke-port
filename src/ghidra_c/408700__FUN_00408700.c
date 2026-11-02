/* FUN_00408700 @ 00408700 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00408700(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6,uint param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_5 - param_2;
  if (local_8 < 0) {
    if ((int)(param_5 + (param_7 & 0xffff)) < param_2) {
      FUN_00408d40(param_6,param_1,param_2 - (param_7 & 0xffff),param_3);
    }
  }
  else if (param_2 < (int)(param_5 - (param_7 & 0xffff))) {
    FUN_00408d40(param_6,param_1,param_2 + (param_7 & 0xffff),param_3);
  }
  local_8 = 0x4087be;
  __chkesp();
  return;
}

