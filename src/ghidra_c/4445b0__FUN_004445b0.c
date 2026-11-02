/* FUN_004445b0 @ 004445b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004445b0(LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_7c [16];
  char *local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint *local_20;
  uint local_1c [3];
  ushort local_10;
  undefined2 uStack_e;
  undefined1 local_c;
  byte bStack_b;
  int *local_8;
  
  puVar2 = local_7c;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (int *)FUN_00494c40(0x10,1);
  if (local_8 != (int *)0x0) {
    local_20 = (uint *)FUN_00497d00(param_1,"rb");
    if (local_20 == (uint *)0x0) {
      if (local_8 != (int *)0xdddddddd) {
        FUN_00495280(local_8);
      }
    }
    else {
      FUN_004989e0((char *)local_1c,1,0x12,(int *)local_20);
      FUN_004988b0(local_20,local_1c[0] & 0xff,1);
      local_24 = (uint)local_10;
      local_28 = CONCAT12(local_c,uStack_e) & 0xffff;
      local_38 = (int)((CONCAT11(bStack_b,local_c) & 0xff) + 7) >> 3;
      local_34 = local_24 * local_38;
      local_2c = local_34;
      iVar1 = FUN_00494c40(local_24 * local_28 * local_38,1);
      *local_8 = iVar1;
      if (*local_8 == 0) {
        if (local_8 != (int *)0xdddddddd) {
          FUN_00495280(local_8);
        }
        FUN_00497b30((int *)local_20);
      }
      else {
        local_3c = (char *)*local_8;
        if ((bStack_b & 0x20) == 0) {
          local_34 = -local_34;
          local_3c = local_3c + (local_28 - 1) * local_2c;
        }
        for (local_30 = 0; local_30 < (int)local_28; local_30 = local_30 + 1) {
          FUN_004989e0(local_3c,1,local_2c,(int *)local_20);
          local_3c = local_3c + local_34;
        }
        FUN_00497b30((int *)local_20);
        local_8[2] = local_24;
        local_8[3] = local_28;
        if (local_38 == 2) {
          *(undefined1 *)(local_8 + 1) = 3;
        }
        if (local_38 == 3) {
          *(undefined1 *)(local_8 + 1) = 4;
        }
        if (local_38 == 4) {
          *(undefined1 *)(local_8 + 1) = 2;
        }
      }
    }
  }
  local_8 = (int *)0x44478c;
  __chkesp();
  return;
}

