/* FUN_00451500 @ 00451500 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00451500(int *param_1,short *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e89f0 != 0) {
    FUN_0047ca90(param_1,param_2,param_3);
    DAT_004e865c = param_3;
    DAT_004e9370 = *param_1;
    DAT_004e9374 = param_1[1];
    DAT_004e9378 = param_1[2];
    _DAT_004e937c = param_1[3];
    _DAT_004f2b40 = DAT_00508194;
    _DAT_004f2b44 = DAT_00508198;
    DAT_004f2b48 = DAT_0050819c;
    DAT_004e8670 = FUN_00452a60();
    DAT_004e8674 = FUN_00452ad0();
    DAT_004e8678 = FUN_00452b40();
    iVar1 = FUN_00452cc0((short)DAT_004e8670,(short)DAT_004e8674,(short)DAT_004e8678);
    DAT_004f2b50 = (short)iVar1;
    for (local_8 = 0; local_8 < (int)(uint)DAT_004e89fa; local_8 = local_8 + 1) {
      *(undefined1 *)(DAT_004e89f0 + 4 + local_8 * 0x20) =
           *(undefined1 *)(DAT_004e89f0 + 5 + local_8 * 0x20);
      *(undefined1 *)(DAT_004e89f0 + 5 + local_8 * 0x20) = 0;
    }
    if (DAT_004f2b50 != -1) {
      *(undefined1 *)(DAT_004e89f0 + 5 + DAT_004f2b50 * 0x20) = 1;
      *(undefined4 *)(DAT_004e89f0 + 8 + DAT_004f2b50 * 0x20) = 0;
      *(undefined4 *)(DAT_004e89f0 + 0xc + DAT_004f2b50 * 0x20) = 0;
      *(undefined4 *)(DAT_004e89f0 + 0x10 + DAT_004f2b50 * 0x20) = 0;
    }
    FUN_00451080(param_2);
    FUN_0047a7c0();
    local_18 = *param_1 - DAT_004e8670 * DAT_004bc4e8;
    local_14 = param_1[1] - DAT_004e8674 * DAT_004bc4ea;
    local_10 = param_1[2] - DAT_004e8678 * DAT_004bc4ec;
    FUN_00482760((undefined4 *)&DAT_00508180,&local_18,&DAT_00508194);
    DAT_00508194 = -DAT_00508194;
    DAT_00508198 = -DAT_00508198;
    DAT_0050819c = DAT_004e865c - DAT_0050819c;
    FUN_00450d80();
  }
  local_8 = 0x45173c;
  __chkesp();
  return;
}

