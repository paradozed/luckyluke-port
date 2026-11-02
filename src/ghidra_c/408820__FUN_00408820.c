/* FUN_00408820 @ 00408820 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00408820(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
            int param_6,uint param_7)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = (short)param_5 - (short)param_3;
  local_8 = CONCAT22(local_8._2_2_,sVar1);
  if (sVar1 < 0) {
    if ((int)(param_5 + (param_7 & 0xffff)) < param_3) {
      FUN_00408d40(param_6,param_1,param_2,param_3 - (param_7 & 0xffff));
    }
  }
  else if (param_3 < (int)(param_5 - (param_7 & 0xffff))) {
    FUN_00408d40(param_6,param_1,param_2,param_3 + (param_7 & 0xffff));
  }
  local_8 = 0x4088e2;
  __chkesp();
  return;
}

