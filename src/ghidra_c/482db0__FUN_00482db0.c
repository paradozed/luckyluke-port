/* FUN_00482db0 @ 00482db0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00482db0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  int local_20;
  short local_1c;
  short local_18;
  short local_14;
  short local_10;
  short local_c;
  undefined4 local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (short)((uint)param_1 >> 0x10);
  local_10 = (short)param_2;
  local_14 = (short)((uint)param_2 >> 0x10);
  local_18 = (short)param_3;
  local_1c = (short)((uint)param_3 >> 0x10);
  local_20 = ((((int)(short)param_1 * (int)local_14 + (int)local_10 * (int)local_1c +
               (int)local_18 * (int)local_c) - (int)(short)param_1 * (int)local_1c) -
             (int)local_10 * (int)local_c) - (int)local_18 * (int)local_14;
  local_8 = 0x482e51;
  __chkesp();
  return;
}

