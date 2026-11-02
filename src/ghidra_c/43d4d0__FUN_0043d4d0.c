/* FUN_0043d4d0 @ 0043d4d0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043d4d0(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 *puVar4;
  float10 fVar5;
  longlong lVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined4 uVar12;
  undefined8 uVar11;
  undefined4 local_7c [16];
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  float local_10;
  float local_c;
  int *local_8;
  
  puVar4 = local_7c;
  for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_10 = _DAT_004b6ae8 / (float)param_1[0xe];
  local_c = 0.0;
  for (local_8 = (int *)0x0; (int)local_8 < param_1[0xe]; local_8 = (int *)((int)local_8 + 1)) {
    local_14 = local_c + local_10;
    if (_DAT_004b6ae8 <= local_14) {
      local_14 = 99.0;
    }
    uVar12 = 199;
    lVar6 = __ftol();
    uVar11 = CONCAT44(uVar12,(int)lVar6);
    uVar10 = 199;
    lVar6 = __ftol();
    uVar9 = (undefined1)lVar6;
    uVar8 = 0;
    lVar6 = __ftol();
    uVar1 = (undefined1)lVar6;
    uVar7 = 0;
    lVar6 = __ftol();
    FUN_0043bc90(param_1[1],param_1[0xe] + (int)local_8,2,(char)lVar6,uVar7,uVar1,uVar8,uVar9,uVar10
                 ,(char)uVar11,(char)((ulonglong)uVar11 >> 0x20));
    local_c = local_14;
  }
  for (local_8 = (int *)0x0; (int)local_8 < param_1[0xe]; local_8 = (int *)((int)local_8 + 1)) {
    FUN_0043c040(param_1[1],(int)local_8 + param_1[0xe] * 2,0x62,0x3d,0x1e);
    FUN_0043c040(param_1[1],(int)local_8,0x62,0x3d,0x1e);
    FUN_0043c040(*param_1,(int)local_8,0x62,0x3d,0x1e);
  }
  local_10 = (float)_DAT_004b6aa0 / (float)param_1[0xe];
  local_c = 0.0;
  local_8 = (int *)0x0;
  piVar3 = param_1;
  while ((int)local_8 < param_1[0xe]) {
    local_14 = local_c + local_10;
    fVar5 = (float10)FUN_00497f54(piVar3);
    local_30 = (float)fVar5;
    lVar6 = __ftol();
    local_18 = (undefined4)lVar6;
    fVar5 = (float10)FUN_00498004(extraout_ECX);
    local_34 = (float)fVar5;
    lVar6 = __ftol();
    local_1c = (undefined4)lVar6;
    fVar5 = (float10)FUN_00497f54(extraout_ECX_00);
    local_38 = (float)fVar5;
    lVar6 = __ftol();
    local_20 = (undefined4)lVar6;
    fVar5 = (float10)FUN_00498004(extraout_ECX_01);
    local_3c = (float)fVar5;
    lVar6 = __ftol();
    local_24 = (undefined4)lVar6;
    local_28 = 0x96;
    local_2c = 0x32;
    FUN_0043be80(*param_1,param_1[0xe] + (int)local_8,2,0x96,0x32,(char)local_20,(char)lVar6,
                 (char)local_18,(char)local_1c);
    local_c = local_14;
    piVar3 = (int *)((int)local_8 + 1);
    local_8 = piVar3;
  }
  local_8 = (int *)0x43d737;
  __chkesp();
  return;
}

