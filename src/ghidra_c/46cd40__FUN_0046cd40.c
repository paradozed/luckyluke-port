/* FUN_0046cd40 @ 0046cd40 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046cd40(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_70 [16];
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar3 = local_70;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (((DAT_004f2b6c != -0x1edc) || (DAT_004f2b70 != -1000)) || (DAT_004f2b74 != -0x26ac)) {
    local_14 = *(int *)(*DAT_004f2458 + 0x90);
    local_10 = *(int *)(*DAT_004f2458 + 0x94);
    local_c = *(int *)(*DAT_004f2458 + 0x98);
    FUN_0046cbd0(&DAT_004f229c,(int)DAT_004f22aa,5);
    local_30 = (int)DAT_004f22a8;
    if (local_30 == -1) {
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_18 = -0x80000000;
      local_1c = 0x7fffffff;
      uVar1 = FUN_0040e850(0);
      if ((uVar1 & 0xff) != 0) {
        DAT_004f22a8 = 2;
      }
    }
    else if (local_30 == 1) {
      local_20 = 0x40;
      local_24 = 0x10;
      local_28 = 0x80;
      local_2c = 0x20;
      local_18 = DAT_004bd6a0 + 0x157c;
      local_1c = DAT_004bd6a0 + 9000;
      FUN_0041c3e0(DAT_004bd6a0 + DAT_004f229c,-0x1068,0x708,0x10e,-0x2d8);
      if (120000 < DAT_004bd6a0) {
        FUN_0041d430(local_14,-0x898,-0x708,0x50,0,0xb4);
        DAT_004f22a8 = -1;
      }
    }
    else {
      local_20 = 0x80;
      local_24 = 0x20;
      local_28 = 0x10;
      local_2c = 0x40;
      local_18 = DAT_004bd6a0 + -0x1194 + (10000 - local_c) / 3;
      local_1c = (DAT_004bd6a0 + 4000) - (10000 - local_c) / 3;
      FUN_0041c3e0(DAT_004bd6a0 + DAT_004f229c,-0x898,0xfffff8f8,0x50,0);
    }
    FUN_0046d370(0x4f23a0,0x32);
    if (((DAT_004f2438 & 0x100) != 0) && ((DAT_004f2438 & 0x400) != 0)) {
      if ((DAT_004f245c & 0x80) == 0) {
        if ((DAT_004f245c & 0x20) != 0) {
          local_14 = local_14 + 10000;
        }
      }
      else {
        local_14 = local_14 + -10000;
      }
    }
    if (((DAT_004f2438 & local_20) != 0) && (DAT_004f229c + -0x96 < _DAT_004f23a0)) {
      _DAT_004f23a0 = _DAT_004f23a0 + -0x19;
    }
    if (((DAT_004f2438 & local_24) != 0) && (_DAT_004f23a0 < DAT_004f229c + 0x96)) {
      _DAT_004f23a0 = _DAT_004f23a0 + 0x19;
    }
    if (((4000 < local_c) && ((DAT_004f2438 & local_2c) != 0)) && (-0x96 < DAT_004f23a8)) {
      DAT_004f23a8 = DAT_004f23a8 + -0x32;
    }
    if (((local_c < 0x1db0) && ((DAT_004f2438 & local_28) != 0)) && (DAT_004f23a8 < 0x96)) {
      DAT_004f23a8 = DAT_004f23a8 + 0x32;
    }
    FUN_0046cbd0(&DAT_004f23a8,0,0xf);
    FUN_0046cbd0((int *)&DAT_004f23a0,DAT_004f229c,9);
    FUN_0046cc50(&local_14,(int *)&DAT_004f23a0);
    FUN_0046d160(*DAT_004f2458,0,(short)DAT_004f23a8 + 0x400,0);
    if (-1 < local_10) {
      local_10 = 0;
      _DAT_004f23a4 = 0;
    }
    if (DAT_004f22a8 == -1) {
      _DAT_004f23a0 = 0;
    }
    if (local_14 < local_18) {
      local_14 = local_18;
      _DAT_004f23a0 = DAT_004f229c;
    }
    if (local_1c < local_14) {
      local_14 = local_1c;
      _DAT_004f23a0 = DAT_004f229c;
    }
    FUN_0046d270(*DAT_004f2458,&local_14);
  }
  uStack_8 = 0x46d154;
  __chkesp();
  return;
}

