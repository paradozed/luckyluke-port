/* FUN_00478360 @ 00478360 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00478360(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_00497360();
  iVar1 = ((int)uVar3 * 0x3c) / 1000;
  DAT_004e89e4 = iVar1 - _DAT_004e89ec;
  DAT_004e89e0 = DAT_004e89e0 + DAT_004e89e4;
  DAT_004e8abc = DAT_004e8abc + DAT_004e89e4 * DAT_004be2e8;
  _DAT_004e89e8 = DAT_004e89e4 * DAT_004e89e4;
  local_8 = 0x4783ed;
  _DAT_004e89ec = iVar1;
  __chkesp();
  return;
}

