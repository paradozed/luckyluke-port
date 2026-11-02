/* FUN_0043d1b0 @ 0043d1b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043d1b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0x14;
  local_8 = (int *)FUN_00494c40(0x3c,1);
  if (local_8 != (int *)0x0) {
    iVar1 = FUN_0043ca10(local_c,40.0,40.0,40.0);
    *local_8 = iVar1;
    if (*local_8 != 0) {
      iVar1 = FUN_0043c650(local_c,40.0,80.0,40.0);
      local_8[1] = iVar1;
      if (local_8[1] != 0) {
        FUN_0043a360((float *)(local_8[1] + 0x18),0.0,-120.0,0.0);
        iVar1 = FUN_0043cce0(*local_8,local_8[1]);
        if (iVar1 != 0) {
          local_8[4] = -0x3c1f0000;
          local_8[5] = 0x437a0000;
          local_8[6] = 0x43fa0000;
          local_8[7] = 0;
          local_8[8] = -0x4036f025;
          local_8[9] = 0x3fc90fdb;
          local_8[2] = 0;
          local_8[3] = 0x41f00000;
          local_8[0xe] = local_c;
          FUN_0043d0f0(local_8);
        }
      }
    }
  }
  local_8 = (int *)0x43d2fe;
  __chkesp();
  return;
}

