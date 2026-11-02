/* FUN_00411800 @ 00411800 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411800(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 *local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004f1792 = 0x10;
  DAT_004f1674 = FUN_00474440;
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004f1798 + local_8 * 4) = 0;
  }
  local_c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  local_c[1] = FUN_00474320;
  *(undefined1 *)(local_c + 4) = 1;
  *local_c = FUN_004743d0;
  *(undefined1 *)((int)local_c + 0x11) = 1;
  FUN_00412c50(param_1,local_c);
  FUN_00412ee0(param_1,FUN_00473b60);
  local_8 = 0x4118ac;
  __chkesp();
  return;
}

