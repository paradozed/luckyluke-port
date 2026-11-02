/* FUN_004803f0 @ 004803f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004803f0(byte *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = 0;
  if ((*param_1 & 2) == 0) {
    if (((DAT_004be3d4 == 0x11) && (*(int *)(param_1 + 0x10) == 0x3d)) &&
       (*(int *)(param_1 + 0x2c) == 0x20)) {
      (*DAT_005089f4)(1);
      __chkesp();
      FUN_0047be40(1);
      local_8 = 1;
    }
    DAT_005081a8 = 0x7fffffff;
    DAT_005081a4 = 0x80000000;
    (**(code **)(*(int *)(param_1 + 0xd0) + 8))(param_1);
    __chkesp();
    DAT_005081a8 = DAT_005081a8 + -1;
    *(int *)(param_1 + 0x9c) = DAT_005081a8;
    *(undefined4 *)(param_1 + 0xa0) = DAT_005081a4;
    if ((param_1[1] == 7) || (param_1[1] == 5)) {
      uVar1 = FUN_00480290((int)param_1);
      if ((char)uVar1 == '\0') goto LAB_00480a21;
      FUN_0047d8e0(1);
    }
    (**(code **)(*(int *)(param_1 + 0xd0) + 0xc))(param_1);
    __chkesp();
    if ((DAT_004be3d4 == 0x11) && (*DAT_004f58a8 == 0x536f6674)) {
      if ((*(int *)(param_1 + 0x10) == 0x2a) && (*(int *)(param_1 + 0x2c) == 0x3e)) {
        FUN_0047e3f0((int)param_1,0x35,0xfffffe0c,0,0,0);
        FUN_0047e3f0((int)param_1,0x34,0xfffffe0c,0,0,0);
        FUN_0047e3f0((int)param_1,0x33,0xfffffe0c,0,0,0);
      }
      if ((*(int *)(param_1 + 0x10) == 0x5a) && (*(int *)(param_1 + 0x2c) == 0x78)) {
        FUN_0047e3f0((int)param_1,0x6c,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x6b,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x37,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x36,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x35,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x34,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x2e,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x2d,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x2c,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x2b,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x2a,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x29,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,3,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,1,0xffffff6a,0,0,0);
      }
      if ((*(int *)(param_1 + 0x10) == 0x33) && (*(int *)(param_1 + 0x2c) == 0x4e)) {
        FUN_0047e3f0((int)param_1,0x45,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x17,0xffffff6a,0,0,0);
      }
      if ((*(int *)(param_1 + 0x10) == 0x69) && (*(int *)(param_1 + 0x2c) == 0x7f)) {
        FUN_0047e3f0((int)param_1,0x72,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x1b,0xffffff6a,0,0,0);
      }
      if ((*(int *)(param_1 + 0x10) == 0x6a) && (*(int *)(param_1 + 0x2c) == 0x80)) {
        FUN_0047e3f0((int)param_1,0x6f,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x6d,0xffffff6a,0,0,0);
        FUN_0047e3f0((int)param_1,0x20,0xffffff6a,0,0,0);
      }
    }
    if ((((DAT_004be3d4 == 2) && (*DAT_004f58a8 == 0x536f6674)) &&
        (*(int *)(param_1 + 0x10) == 0xd4)) && (*(int *)(param_1 + 0x2c) == 0xac)) {
      FUN_0047e3f0((int)param_1,0x31,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x30,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x2f,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x2e,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x2a,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x29,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x27,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x26,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x25,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x24,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x1b,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x1a,0xffffff6a,0,0,0);
    }
    if (((DAT_004be3d4 == 0x17) && (*DAT_004f58a8 == 0x536f6674)) &&
       ((*(int *)(param_1 + 0x10) == 0x96 && (*(int *)(param_1 + 0x2c) == 0x90)))) {
      FUN_0047e3f0((int)param_1,0x5d,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x4f,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x4c,0xffffff6a,0,0,0);
      FUN_0047e3f0((int)param_1,0x5b,0xffffff6a,0,0,0);
    }
    FUN_0047d8e0(0);
    if (local_8 != 0) {
      FUN_0047be40(0);
      (*DAT_005089f4)(0);
      __chkesp();
    }
  }
LAB_00480a21:
  local_8 = 0x480a2e;
  __chkesp();
  return;
}

