/* FUN_004453f0 @ 004453f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004453f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e85cc < 0x32) {
    local_8 = (undefined4 *)(DAT_004e85c0 + DAT_004e85cc * 0x18);
    DAT_004e85cc = DAT_004e85cc + 1;
    FUN_00497690(local_8,param_1,0x18);
  }
  local_8 = (undefined4 *)0x445459;
  __chkesp();
  return;
}

