/* FUN_004730a0 @ 004730a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004730a0(int *param_1,ushort param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int *local_14;
  undefined4 uStack_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_14 = (int *)FUN_00439a90(DAT_004e85ec,8);
  *(int **)(*param_1 + (uint)*(ushort *)(param_1 + 1) * 4) = local_14;
  *(short *)(param_1 + 1) = (short)param_1[1] + 1;
  _memset(local_14,0,8);
  *local_14 = DAT_004e8820 + *(int *)(DAT_004e8820 + 4 + (uint)param_2 * 4);
  *(ushort *)(local_14 + 1) = param_2;
  uStack_8 = 0x473136;
  __chkesp();
  return;
}

