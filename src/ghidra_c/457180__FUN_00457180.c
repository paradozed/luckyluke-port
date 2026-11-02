/* FUN_00457180 @ 00457180 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00457180(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_88 [16];
  uint local_48;
  int local_44;
  uint *local_40;
  int local_3c;
  int *local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar3 = local_88;
  for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_38 = *(int **)(param_1 + 0x18);
  local_3c = *local_38;
  local_40 = (uint *)(local_38 + 4);
  local_44 = *(int *)(param_1 + 0x14);
  local_24 = *(int *)(local_3c + 0x90);
  local_20 = *(int *)(local_3c + 0x94);
  local_1c = *(undefined4 *)(local_3c + 0x98);
  cVar1 = FUN_004568c0(param_1,&local_24,local_38 + 0x19,&local_34);
  if (cVar1 != '\0') {
    FUN_00457ab0(local_3c,local_34,local_30,local_2c);
    local_24 = *(int *)(local_3c + 0x90);
    local_20 = *(int *)(local_3c + 0x94);
    local_1c = *(undefined4 *)(local_3c + 0x98);
  }
  local_48 = FUN_00456410(param_1,&local_24);
  local_48 = local_48 & 0xffff;
  if (local_48 == 0) {
    cVar1 = FUN_004566a0(param_1,&local_24);
    if ((cVar1 != '\0') && ((*local_40 & 8) == 0)) {
      *local_40 = *local_40 & 0xffffffdf;
    }
  }
  else if (local_48 == 2) {
    if ((**(char **)(param_1 + 0x14) == '\x01') && ((*local_40 & 0x20) == 0)) {
      FUN_004562f0(param_1,local_44);
    }
  }
  else if (local_48 == 3) {
    FUN_00457ab0(local_3c,**(undefined4 **)(*(int *)(param_1 + 0x14) + 8),
                 *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 8) + 4),
                 *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 8) + 8));
    *(short *)(param_1 + 0x58) = *(short *)(param_1 + 0x58) + 0x800;
    *(ushort *)(param_1 + 0x58) = *(ushort *)(param_1 + 0x58) & 0xfff;
    *local_40 = *local_40 | 0x20;
  }
  iVar2 = FUN_00457920(param_1,&local_24,&local_14);
  *(short *)(param_1 + 0x48) = (short)iVar2;
  if (*(short *)(param_1 + 0x48) < 0) {
    local_14 = **(int **)(*(int *)(param_1 + 0x14) + 4);
    local_10 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 4);
    local_c = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 8);
  }
  if (*(int *)(*(int *)(param_1 + 0x14) + 0xc) < (int)*(short *)(param_1 + 0x48)) {
    local_14 = **(int **)(*(int *)(param_1 + 0x14) + 8);
    local_10 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + 8) + 4);
    local_c = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 8) + 8);
  }
  if ((*(uint *)(param_1 + 0x54) & 1) == 0) {
    if (((*local_40 & 0x20) == 0) || ((*local_40 & 8) != 0)) {
      if (local_10 < local_20) {
        if ((**(char **)(param_1 + 0x14) == '\x04') && (DAT_004f29ac == '\0')) {
          *local_40 = *local_40 | 0x100;
          *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 1;
        }
        else {
          local_20 = local_10;
          if ((*local_40 & 0x40) != 0) {
            *local_40 = *local_40 | 0x20;
          }
        }
      }
      local_10 = local_20;
    }
  }
  else {
    local_10 = local_20;
  }
  *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(param_1 + 0x48);
  FUN_00457ab0(local_3c,local_14,local_10,local_c);
  uStack_8 = 0x457493;
  __chkesp();
  return;
}

