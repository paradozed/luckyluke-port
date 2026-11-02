/* FUN_00451080 @ 00451080 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00451080(short *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (int)*param_1;
  local_c = (int)param_1[1];
  if ((1 < DAT_004be2f0) && (DAT_004e89f8 == 1)) {
    FUN_00450f20(-1,0,0);
    FUN_00450f20(1,0,0);
    if (DAT_004e89f6 == 1) {
      FUN_00450f20(-2,0,0);
      FUN_00450f20(2,0,0);
      if (200 < local_c) {
        FUN_00450f20(-3,0,0);
      }
      if (local_c < -200) {
        FUN_00450f20(3,0,0);
      }
      if (local_c < -700) {
        FUN_00450f20(4,0,0);
      }
    }
  }
  if (1 < DAT_004be2f4) {
    FUN_00450f20(-1,-1,0);
    FUN_00450f20(0,-1,0);
    FUN_00450f20(1,-1,0);
    if (100 < local_8) {
      FUN_00450f20(-1,-2,0);
      FUN_00450f20(0,-2,0);
      FUN_00450f20(1,-2,0);
    }
    FUN_00450f20(-1,1,0);
    FUN_00450f20(0,1,0);
    FUN_00450f20(1,1,0);
    if (local_8 < -100) {
      FUN_00450f20(-1,2,0);
      FUN_00450f20(0,2,0);
      FUN_00450f20(1,2,0);
    }
  }
  if (1 < DAT_004be2f8) {
    FUN_00450f20(0,0,1);
    if (local_c < 0) {
      local_10 = -local_c;
    }
    else {
      local_10 = local_c;
    }
    if (local_10 < 0x2ee) {
      FUN_00450f20(0,0,2);
    }
    if (local_c < 0) {
      local_14 = -local_c;
    }
    else {
      local_14 = local_c;
    }
    if (local_14 < 0x226) {
      FUN_00450f20(0,0,3);
    }
    if (local_c < 0xfa) {
      FUN_00450f20(1,0,0);
      FUN_00450f20(1,0,1);
      FUN_00450f20(1,0,2);
      FUN_00450f20(1,0,3);
    }
    if (local_c < -0xfa) {
      FUN_00450f20(2,0,0);
    }
    if (local_c < -0x32) {
      FUN_00450f20(2,0,1);
    }
    if (local_c < 0x32) {
      FUN_00450f20(2,0,2);
    }
    if (local_c < 100) {
      FUN_00450f20(2,0,3);
    }
    if (local_c < -500) {
      FUN_00450f20(3,0,0);
    }
    if (local_c < -0xfa) {
      FUN_00450f20(3,0,1);
    }
    if (local_c < -0x96) {
      FUN_00450f20(3,0,2);
    }
    if (local_c < -0x32) {
      FUN_00450f20(3,0,3);
    }
    if (-0xfa < local_c) {
      FUN_00450f20(-1,0,0);
      FUN_00450f20(-1,0,1);
      FUN_00450f20(-1,0,2);
      FUN_00450f20(-1,0,3);
    }
    if (0xfa < local_c) {
      FUN_00450f20(-2,0,0);
    }
    if (0x32 < local_c) {
      FUN_00450f20(-2,0,1);
    }
    if (-0x32 < local_c) {
      FUN_00450f20(-2,0,2);
    }
    if (-100 < local_c) {
      FUN_00450f20(-2,0,3);
    }
    if (500 < local_c) {
      FUN_00450f20(-3,0,0);
    }
    if (0xfa < local_c) {
      FUN_00450f20(-3,0,1);
    }
    if (0x96 < local_c) {
      FUN_00450f20(-3,0,2);
    }
    if (0x32 < local_c) {
      FUN_00450f20(-3,0,3);
    }
    if (local_c < 0) {
      local_18 = -local_c;
    }
    else {
      local_18 = local_c;
    }
    if (800 < local_18) {
      FUN_00450f20(0,0,-1);
      if (local_c < -800) {
        FUN_00450f20(1,0,-1);
        FUN_00450f20(2,0,-1);
        FUN_00450f20(3,0,-1);
      }
      else {
        FUN_00450f20(-2,0,-1);
        FUN_00450f20(-1,0,-1);
      }
    }
  }
  local_8 = 0x4514f0;
  __chkesp();
  return;
}

