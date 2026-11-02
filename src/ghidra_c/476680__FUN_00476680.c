/* FUN_00476680 @ 00476680 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00476680(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_7c [16];
  short local_3c;
  short local_34;
  int local_20;
  int local_1c;
  int local_18;
  int local_8;
  
  puVar2 = local_7c;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    if (*(short *)(&DAT_004f13ca + local_8 * 0x2c) != 0) {
      local_20 = *(int *)(*(int *)(&DAT_004f13c0 + local_8 * 0x2c) + 0x90);
      local_1c = *(int *)(*(int *)(&DAT_004f13c0 + local_8 * 0x2c) + 0x94);
      local_18 = *(int *)(*(int *)(&DAT_004f13c0 + local_8 * 0x2c) + 0x98);
      FUN_004739f0(*(int *)(&DAT_004f13c0 + local_8 * 0x2c),
                   local_20 + *(int *)(&DAT_004f13d0 + local_8 * 0x2c),
                   local_1c + *(int *)(&DAT_004f13d4 + local_8 * 0x2c),
                   local_18 + *(int *)(&DAT_004f13d8 + local_8 * 0x2c));
      FUN_004761e0(local_8);
      if (*(short *)(&DAT_004f13c8 + local_8 * 0x2c) == 0) {
        local_34 = FUN_004768e0(*(int *)(&DAT_004f13c0 + local_8 * 0x2c));
        local_3c = FUN_00476910(*(int *)(&DAT_004f13c0 + local_8 * 0x2c));
        if ((local_34 < 0) || (DAT_004be3c8 < (uint)(int)local_34)) {
          *(undefined2 *)(&DAT_004f13ca + local_8 * 0x2c) = 0;
          local_18 = 0;
          local_1c = 0;
          local_20 = 0;
          FUN_004739f0(*(int *)(&DAT_004f13c0 + local_8 * 0x2c),0,0,0);
        }
        else if ((local_3c < 0) || (0x1e0 < local_3c)) {
          *(undefined2 *)(&DAT_004f13ca + local_8 * 0x2c) = 0;
          local_18 = 0;
          local_1c = 0;
          local_20 = 0;
          FUN_004739f0(*(int *)(&DAT_004f13c0 + local_8 * 0x2c),0,0,0);
        }
        else if ((local_18 < -3000) || (20000 < local_18)) {
          *(undefined2 *)(&DAT_004f13ca + local_8 * 0x2c) = 0;
          local_18 = 0;
          local_1c = 0;
          local_20 = 0;
          FUN_004739f0(*(int *)(&DAT_004f13c0 + local_8 * 0x2c),0,0,0);
        }
      }
      *(undefined2 *)(&DAT_004f13c8 + local_8 * 0x2c) = 0;
    }
  }
  local_8 = 0x4768cf;
  __chkesp();
  return;
}

