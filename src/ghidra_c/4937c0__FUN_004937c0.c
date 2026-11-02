/* FUN_004937c0 @ 004937c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004937c0(short *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [16];
  short *local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_28 = param_1;
  if (*(char *)(DAT_004e8c44 + 4 + (param_2 & 0xff) * 0x14) != '\0') {
    local_8 = DAT_00508e2c >> 2;
    local_24 = **(int **)(DAT_004e8c44 + (param_2 & 0xff) * 0x14) +
               *(int *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14);
    local_c = *(int *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14);
    local_10 = *(int *)(*(int *)(DAT_004e8c44 + (param_2 & 0xff) * 0x14) + 4);
    local_14 = (uint)*(ushort *)(DAT_004e8c44 + 0x10 + (param_2 & 0xff) * 0x14);
    local_18 = (uint)*(ushort *)(DAT_004e8c44 + 0x12 + (param_2 & 0xff) * 0x14);
    local_1c = *(int *)(DAT_004e8c44 + 0xc + (param_2 & 0xff) * 0x14);
    local_20 = local_c + ((int)(local_8 * local_1c) >> 8) * 4;
    if (local_10 < local_20) {
      iVar1 = (local_10 - local_c) * 0x100;
      local_8 = (uint)(CONCAT44(iVar1 >> 0x1f,iVar1 >> 2) / (longlong)local_1c);
      FUN_004939a0(local_24,param_1,local_8,local_1c,local_14,local_18);
      *(undefined1 *)(DAT_004e8c44 + 4 + (param_2 & 0xff) * 0x14) = 0;
      *(undefined4 *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14) = 0;
      *(undefined4 *)(DAT_004e8c44 + (param_2 & 0xff) * 0x14) = 0;
    }
    else {
      FUN_004939a0(local_24,param_1,local_8,local_1c,local_14,local_18);
      *(int *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14) = local_20;
    }
  }
  local_8 = 0x493997;
  __chkesp();
  return;
}

