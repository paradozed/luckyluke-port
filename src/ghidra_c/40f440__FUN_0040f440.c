/* FUN_0040f440 @ 0040f440 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040f440(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 local_5c [16];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_c;
  undefined4 local_8;
  
  puVar3 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar4 = FUN_00497360();
  _DAT_004d1e28 = (undefined4)uVar4;
  sVar1 = FUN_004074b0(param_2,2);
  DAT_004d1e2c = sVar1 * 100;
  sVar1 = FUN_004074b0(param_2,3);
  _DAT_004d1e38 = (int)sVar1;
  _DAT_004d1e40 = 0;
  iVar2 = FUN_00407580(param_1);
  DAT_004d1e44 = **(int **)(iVar2 + 8);
  DAT_004d1e3c = 1;
  local_1c = *(undefined4 *)(DAT_004d1e44 + 0x90);
  _DAT_004d1e30 = *(undefined4 *)(DAT_004d1e44 + 0x94);
  local_14 = *(undefined4 *)(DAT_004d1e44 + 0x98);
  local_8 = 0x40f506;
  DAT_004d1e34 = _DAT_004d1e30;
  local_18 = _DAT_004d1e30;
  local_c = DAT_004d1e44;
  __chkesp();
  return;
}

