/* FUN_00470780 @ 00470780 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470780(int param_1,int *param_2,ushort param_3)

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
  local_8 = (undefined4 *)FUN_00439a90(DAT_004e85ec,0x4c);
  _memset(local_8,0,0x4c);
  local_8[1] = 0;
  local_8[2] = FUN_00470740;
  *local_8 = FUN_00470700;
  local_8[3] = param_1;
  *(ushort *)(local_8 + 0x10) = param_3;
  if ((param_3 & 0x80) == 0) {
    local_8[4] = *(int *)(param_1 + 4) - *param_2;
    local_8[5] = *(int *)(param_1 + 8) - param_2[1];
    local_8[6] = *(int *)(param_1 + 0xc) - param_2[2];
  }
  FUN_004700c0((int)local_8,0,0);
  local_8 = (undefined4 *)0x470852;
  __chkesp();
  return;
}

