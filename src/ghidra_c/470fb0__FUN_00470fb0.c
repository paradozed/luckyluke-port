/* FUN_00470fb0 @ 00470fb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470fb0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  int local_18;
  ushort *local_14;
  short local_10;
  uint local_c;
  uint local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  local_c = CONCAT31(local_c._1_3_,1);
  local_10 = 0;
  if ((DAT_004bdb14 == '\0') && (*(int *)(param_1 + 0x1c) == 1)) {
    local_8 = (uint)local_8._1_3_ << 8;
  }
  if ((DAT_004bdb15 == '\0') && (2 < *(uint *)(param_1 + 0x1c))) {
    local_8 = local_8 & 0xffffff00;
  }
  if ((DAT_004e8720 == param_1) && ((DAT_004e8abc >> 5) % 0x3c < 0x1a)) {
    local_c = (uint)local_c._1_3_ << 8;
  }
  if (((local_8 & 0xff) != 0) && ((local_c & 0xff) != 0)) {
    local_14 = *(ushort **)(param_1 + 0x30);
    local_18 = *(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4);
    do {
      (**(code **)(&DAT_00507f88 + (uint)*local_14 * 0x34))
                (local_14 + 10,local_14[1],local_18,DAT_00508158);
      __chkesp();
      local_18 = local_18 + *(int *)(local_14 + 6);
      local_14 = *(ushort **)(local_14 + 8);
      local_10 = local_10 + 1;
    } while (local_14 != (ushort *)0x0);
  }
  if (((local_c & 0xff) != 0) &&
     (((DAT_004e8719 != '\0' && (*(int *)(param_1 + 0x1c) == 1)) ||
      ((DAT_004e871a != '\0' &&
       ((2 < *(uint *)(param_1 + 0x1c) || (*(char *)(param_1 + 1) == '\x05')))))))) {
    FUN_00480040(param_1,0xff,0xff,0xff);
  }
  local_8 = 0x47112a;
  __chkesp();
  return;
}

