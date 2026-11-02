/* FUN_00437e30 @ 00437e30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00437e30(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  int *local_10;
  int *local_c;
  int *local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = (int *)0x0;
  if (DAT_004e84c8 != '\0') {
    piVar1 = (int *)*DAT_004e84d4;
    do {
      local_8 = piVar1;
      if (local_8 == (int *)0x0) goto LAB_00437f45;
      local_c = (int *)local_8[1];
      piVar1 = local_c;
    } while ((void *)local_8[3] != param_1);
    if ((DAT_004bcc84 & 2) != 0) {
      FUN_00438330();
    }
    if (local_8 == (int *)*DAT_004e84d4) {
      *DAT_004e84d4 = local_8[1];
    }
    if (local_8 == (int *)DAT_004e84d4[1]) {
      DAT_004e84d4[1] = *local_8;
    }
    if (*local_8 != 0) {
      *(int *)(*local_8 + 4) = local_8[1];
    }
    if (local_8[1] != 0) {
      *(int *)local_8[1] = *local_8;
    }
    DAT_004e84c0 = DAT_004e84c0 - local_8[2];
    local_10 = local_8;
    FUN_00495280(local_8);
LAB_00437f45:
    if ((local_10 == (int *)0x0) && ((DAT_004bcc84 & 0x80) != 0)) {
      FUN_004384d0();
    }
  }
  if (param_1 != (void *)0xdddddddd) {
    FUN_00495280(param_1);
  }
  local_8 = (int *)0x437f93;
  __chkesp();
  return;
}

