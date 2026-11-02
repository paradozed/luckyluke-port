/* FUN_00493ce0 @ 00493ce0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00493ce0(short *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  short *local_1c;
  short *local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_1c = param_1;
  if (*(char *)(DAT_004e8c44 + 4 + (param_2 & 0xff) * 0x14) != '\0') {
    local_8 = DAT_00508e2c >> 1;
    local_18 = (short *)(**(int **)(DAT_004e8c44 + (param_2 & 0xff) * 0x14) +
                        *(int *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14));
    local_c = *(int *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14);
    local_10 = *(int *)(*(int *)(DAT_004e8c44 + (param_2 & 0xff) * 0x14) + 4);
    local_14 = (uint)*(ushort *)(DAT_004e8c44 + 0x10 + (param_2 & 0xff) * 0x14);
    if ((int)DAT_00508e2c < local_10 - local_c) {
      FUN_00493e80(local_18,param_1,local_8,local_14);
      *(uint *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14) =
           *(int *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14) + DAT_00508e2c;
    }
    else {
      FUN_00493e80(local_18,param_1,local_10 - local_c >> 1,local_14);
      *(undefined1 *)(DAT_004e8c44 + 4 + (param_2 & 0xff) * 0x14) = 0;
      *(undefined4 *)(DAT_004e8c44 + 8 + (param_2 & 0xff) * 0x14) = 0;
      *(undefined4 *)(DAT_004e8c44 + (param_2 & 0xff) * 0x14) = 0;
    }
  }
  local_8 = 0x493e6f;
  __chkesp();
  return;
}

