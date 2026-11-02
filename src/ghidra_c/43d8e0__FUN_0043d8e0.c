/* FUN_0043d8e0 @ 0043d8e0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043d8e0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0x3dc90fdb;
  if ((param_1[7] == 2) && ((float)_DAT_004b6af0 < (float)param_1[5])) {
    param_1[5] = (int)((float)param_1[5] - 0.09817477);
  }
  if ((param_1[7] == 1) && ((float)param_1[5] < -0.09817477)) {
    param_1[5] = (int)((float)param_1[5] + 0.09817477);
  }
  FUN_0043d740(param_1);
  FUN_0043bc30((int *)*param_1);
  local_8 = 0x43d97b;
  __chkesp();
  return;
}

