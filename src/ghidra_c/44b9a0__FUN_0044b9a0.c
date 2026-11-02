/* FUN_0044b9a0 @ 0044b9a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044b9a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8601 = 0;
  local_8 = local_8 & 0xffff0000;
  while ((int)(local_8 & 0xffff) < (int)(DAT_004d1e90 + (uint)DAT_004d1e94 + (uint)DAT_004d1e96)) {
    if (*(int *)((int)DAT_004d1e70 + (local_8 & 0xffff) * 0x20 + 0x10) != 0) {
      *(undefined4 *)((int)DAT_004d1e70 + (local_8 & 0xffff) * 0x20 + 0x10) = 0;
    }
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  if (DAT_004d1e70 != (void *)0x0) {
    if (DAT_004d1e70 != (void *)0xdddddddd) {
      FUN_00495280(DAT_004d1e70);
    }
    DAT_004d1e70 = (void *)0x0;
  }
  if (DAT_004d1e78 != (void *)0x0) {
    if (DAT_004d1e78 != (void *)0xdddddddd) {
      FUN_00495280(DAT_004d1e78);
    }
    DAT_004d1e78 = (void *)0x0;
  }
  local_8 = 0x44ba97;
  __chkesp();
  return;
}

