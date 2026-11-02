/* FUN_004714a0 @ 004714a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004714a0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  void *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (void *)FUN_00439a90(DAT_004e85ec,0x18);
  _memset(local_8,0,0x18);
  *(void **)(*param_1 + (uint)*(ushort *)(param_1 + 1) * 4) = local_8;
  *(short *)(param_1 + 1) = (short)param_1[1] + 1;
  local_8 = (void *)0x471511;
  __chkesp();
  return;
}

