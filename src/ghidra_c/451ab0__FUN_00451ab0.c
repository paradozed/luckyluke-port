/* FUN_00451ab0 @ 00451ab0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00451ab0(int *param_1,short *param_2,int param_3)

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
  FUN_0047ca90(param_1,param_2,param_3);
  DAT_004e865c = param_3;
  DAT_004e9370 = *param_1;
  DAT_004e9374 = param_1[1];
  DAT_004e9378 = param_1[2];
  _DAT_004e937c = param_1[3];
  _DAT_004f2b40 = DAT_00508194;
  _DAT_004f2b44 = DAT_00508198;
  DAT_004f2b48 = DAT_0050819c;
  iVar1 = FUN_00452bb0(*DAT_004f2458);
  DAT_004e8670 = (int)(short)iVar1;
  iVar1 = FUN_00452bf0(*DAT_004f2458);
  DAT_004e8674 = (int)(short)iVar1;
  iVar1 = FUN_00452c30(*DAT_004f2458);
  DAT_004e8678 = (int)(short)iVar1;
  DAT_004e866a = FUN_00452ec0(*DAT_004f2458);
  if (DAT_004e866a == -1) {
    DAT_004e866a = DAT_004e8646;
  }
  if (DAT_004e866a != DAT_004e8646) {
    for (local_8 = 0; local_8 < (int)(uint)DAT_004e89fa; local_8 = local_8 + 1) {
      *(undefined1 *)(DAT_004e89f0 + 4 + local_8 * 0x20) =
           *(undefined1 *)(DAT_004e89f0 + 5 + local_8 * 0x20);
      *(undefined1 *)(DAT_004e89f0 + 5 + local_8 * 0x20) = 0;
    }
    *(undefined1 *)(DAT_004e89f0 + 5 + DAT_004e866a * 0x20) = 1;
    *(undefined4 *)(DAT_004e89f0 + 8 + DAT_004e866a * 0x20) = 0;
    *(undefined4 *)(DAT_004e89f0 + 0xc + DAT_004e866a * 0x20) = 0;
    *(undefined4 *)(DAT_004e89f0 + 0x10 + DAT_004e866a * 0x20) = 0;
    FUN_004519e0();
    DAT_004e8646 = DAT_004e866a;
  }
  FUN_0047a7c0();
  local_18 = *param_1 - DAT_004e8670 * DAT_004bc4e8;
  local_14 = param_1[1] - DAT_004e8674 * DAT_004bc4ea;
  local_10 = param_1[2] - DAT_004e8678 * DAT_004bc4ec;
  FUN_00482760((undefined4 *)&DAT_00508180,&local_18,&DAT_00508194);
  DAT_00508194 = -DAT_00508194;
  DAT_00508198 = -DAT_00508198;
  DAT_0050819c = DAT_004e865c - DAT_0050819c;
  FUN_00450d80();
  if (DAT_004e8700 == '\x01') {
    FUN_0045e170((ushort *)&DAT_004bd628);
    if (DAT_004e8664 < 0) {
      FUN_004551a0();
    }
    if (DAT_004e8662 != '\0') {
      FUN_00455270();
    }
  }
  local_8 = 0x451d61;
  __chkesp();
  return;
}

