/* FUN_00450f20 @ 00450f20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00450f20(short param_1,short param_2,short param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_70 [16];
  short local_30;
  short local_2c;
  short local_28;
  int local_24;
  int local_20;
  int local_1c;
  short local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar3 = local_70;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_28 = param_1 * DAT_004bc4e8;
  local_2c = param_2 * DAT_004bc4ea;
  local_30 = param_3 * DAT_004bc4ec;
  local_1c = (int)(short)(param_1 + (short)DAT_004e8670) * (int)DAT_004bc4e8;
  local_20 = (int)(short)(param_2 + (short)DAT_004e8674) * (int)DAT_004bc4ea;
  local_24 = (int)(short)(param_3 + (short)DAT_004e8678) * (int)DAT_004bc4ec;
  iVar2 = FUN_00452cc0(param_1 + (short)DAT_004e8670,param_2 + (short)DAT_004e8674,
                       param_3 + (short)DAT_004e8678);
  local_18 = (short)iVar2;
  if (local_18 != -1) {
    local_14 = local_1c;
    local_10 = local_20;
    local_c = local_24;
    cVar1 = FUN_00451f40(&local_14);
    if (cVar1 == '\x01') {
      *(undefined1 *)(DAT_004e89f0 + 5 + local_18 * 0x20) = 1;
      *(int *)(DAT_004e89f0 + 8 + local_18 * 0x20) = (int)local_28;
      *(int *)(DAT_004e89f0 + 0xc + local_18 * 0x20) = (int)local_2c;
      *(int *)(DAT_004e89f0 + 0x10 + local_18 * 0x20) = (int)local_30;
    }
  }
  uStack_8 = 0x451074;
  __chkesp();
  return;
}

