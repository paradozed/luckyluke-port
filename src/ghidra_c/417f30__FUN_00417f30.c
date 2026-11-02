/* FUN_00417f30 @ 00417f30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00417f30(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (int *)FUN_00439a90(DAT_004e85ec,0x74);
  _memset(local_8,0,0x74);
  *local_8 = param_1;
  *(undefined2 *)(local_8 + 6) = 0;
  *(undefined4 *)(*local_8 + 0xe4) = 0;
  *(undefined4 *)(*local_8 + 0xe0) = 0;
  local_8 = (int *)0x417faa;
  __chkesp();
  return;
}

