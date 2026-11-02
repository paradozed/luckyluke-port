/* FUN_004b1510 @ 004b1510 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __thiscall FUN_004b1510(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_c0;
  uint local_bc;
  undefined4 local_b8;
  uint local_b4;
  int local_a8;
  undefined4 local_78 [8];
  uint local_58;
  int local_54;
  undefined4 local_50 [8];
  uint local_30;
  undefined4 local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_c;
  undefined4 local_8;
  
  FUN_004b1045((uint)this,&local_30);
  _memset(&local_c0,0,0x6c);
  local_c0 = 0x6c;
  local_bc = 7;
  local_58 = 0x40;
  local_b8 = local_2c;
  local_b4 = local_30;
  if (local_20 != 0) {
    local_58 = 0x2000;
  }
  if (local_1c != 0) {
    local_58 = 0x1000;
  }
  if (local_c != 0) {
    local_58 = local_58 | 0x4000000;
  }
  if (local_18 == 0) {
    if (local_28 == 8) {
      _memset(local_50,0,0x20);
      local_50[0] = 0x20;
      local_50[1] = 0x60;
      local_50[3] = 8;
      local_bc = local_bc | 0x1000;
      puVar2 = local_50;
      puVar3 = local_78;
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
  }
  else {
    local_bc = 0x47;
    local_58 = 0x20000;
    local_a8 = local_28;
  }
  if (param_1 == 1) {
    local_58 = local_58 | 0x800;
  }
  local_54 = (**(code **)(*DAT_0050a2d0 + 0x18))(DAT_0050a2d0,&local_c0,&local_8,0);
  if (local_54 != 0) {
    FUN_004b0969((uint *)s_goNewScreen___IDirectDraw2_Creat_004d1b94,local_54);
  }
  return local_8;
}

