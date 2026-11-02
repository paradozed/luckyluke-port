/* FUN_00436ff0 @ 00436ff0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00436ff0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_74 [16];
  undefined1 local_34;
  undefined4 local_30 [2];
  short local_28;
  short local_26;
  short local_20;
  short local_1e;
  short local_18;
  short local_16;
  short local_10;
  short local_e;
  uint local_8;
  
  puVar3 = local_74;
  for (iVar2 = 0x1c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 != 0) {
    for (local_8 = 0; local_8 < *(uint *)(param_1 + 8); local_8 = local_8 + 1) {
      FUN_00497690(local_30,(undefined4 *)(param_1 + 0x20 + local_8 * 0x28),0x28);
      local_28 = local_28 + *(short *)(param_1 + 0x10);
      local_26 = local_26 + *(short *)(param_1 + 0x14);
      local_20 = local_20 + *(short *)(param_1 + 0x10);
      local_1e = local_1e + *(short *)(param_1 + 0x14);
      local_18 = local_18 + *(short *)(param_1 + 0x10);
      local_16 = local_16 + *(short *)(param_1 + 0x14);
      local_10 = local_10 + *(short *)(param_1 + 0x10);
      local_e = local_e + *(short *)(param_1 + 0x14);
      FUN_004362b0(param_1,local_30,local_8);
    }
    FUN_00436560(param_1);
    (*DAT_004e8a6c)(0);
    uVar1 = __chkesp();
    local_34 = (undefined1)uVar1;
    for (local_8 = 0; local_8 < *(uint *)(param_1 + 0xc); local_8 = local_8 + 1) {
      (*DAT_004e8a6c)(CONCAT31((int3)(local_8 >> 8),
                               *(undefined1 *)(param_1 + 0x5e2 + local_8 * 0x28)));
      __chkesp();
      FUN_00436ee0(param_1 + 0x5c4 + local_8 * 0x28);
      (*DAT_004e8a30)();
      __chkesp();
      (*DAT_004e8a54)(param_1 + 0x5c4 + local_8 * 0x28,9,9,9,9);
      __chkesp();
    }
    (*DAT_004e8a6c)(local_34);
    __chkesp();
  }
  local_8 = 0x4371bf;
  __chkesp();
  return;
}

