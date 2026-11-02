/* FUN_00493a60 @ 00493a60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00493a60(short *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [16];
  short *local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
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
    local_10 = *(uint *)(*(int *)(DAT_004e8c44 + (param_2 & 0xff) * 0x14) + 4);
    local_14 = (uint)*(ushort *)(DAT_004e8c44 + 0x10 + (param_2 & 0xff) * 0x14);
    local_18 = (uint)*(ushort *)(DAT_004e8c44 + 0x12 + (param_2 & 0xff) * 0x14);
    local_1c = *(uint *)(*(int *)(DAT_004e8c44 + (param_2 & 0xff) * 0x14) + 0x10);
    local_20 = local_c + (local_8 * local_1c >> 8) * 2;
    if (local_10 < local_20) {
      local_8 = ((local_10 - local_c & 0xffffff) << 7) / local_1c;
      FUN_00493c40(local_24,param_1,local_8,local_1c,local_14,local_18);
      *(undefined1 *)(DAT_004e8c44 + 4 + (param_2 & 0xff) * 0x14) = 0;
      *(undefined4 *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14) = 0;
      *(undefined4 *)(DAT_004e8c44 + (param_2 & 0xff) * 0x14) = 0;
    }
    else {
      FUN_00493c40(local_24,param_1,local_8,local_1c,local_14,local_18);
      *(uint *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14) = local_20;
    }
  }
  local_8 = 0x493c38;
  __chkesp();
  return;
}

