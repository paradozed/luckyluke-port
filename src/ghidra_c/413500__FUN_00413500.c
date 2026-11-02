/* FUN_00413500 @ 00413500 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00413500(void *param_1)

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
  local_8 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  local_8[1] = 0;
  *(undefined1 *)(local_8 + 4) = 0;
  *local_8 = 0;
  *(undefined1 *)((int)local_8 + 0x11) = 0;
  FUN_00412c50(param_1,local_8);
  FUN_00412ee0(param_1,FUN_004653b0);
  local_8 = (undefined4 *)0x413570;
  __chkesp();
  return;
}

