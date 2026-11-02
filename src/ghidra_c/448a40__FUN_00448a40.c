/* FUN_00448a40 @ 00448a40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00448a40(short *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_84 [16];
  undefined4 *local_44;
  int local_40;
  undefined4 *local_3c;
  int local_38;
  undefined4 *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined1 local_1c [12];
  short local_10;
  short local_e;
  undefined2 local_c;
  undefined2 local_a;
  byte *local_8;
  
  puVar2 = local_84;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  if ((param_1 != (short *)0x0) && (*(char *)((int)param_1 + 0x19) == '\0')) {
    for (local_8 = *(byte **)(param_1 + 0x1a); local_8 != (byte *)0x0;
        local_8 = *(byte **)(local_8 + 0x18)) {
      if ((char)param_1[0x14] != '\0') {
        (*(code *)(&PTR_FUN_004bd020)[*local_8])(local_8 + 0xc,local_1c,(int)param_1 + 0x15);
        __chkesp();
        (*(code *)(&PTR_FUN_004bd010)[*local_8])
                  (*(undefined4 *)(local_8 + (uint)DAT_004e89d8 * 4 + 0x1c),local_1c);
        __chkesp();
        (*(code *)(&PTR_FUN_004bd030)[*local_8])
                  (*(undefined4 *)(local_8 + (uint)DAT_004e89d8 * 4 + 0x1c),
                   *(byte *)((int)param_1 + 0x19) & 0xfb,
                   (int)(*(byte *)((int)param_1 + 0x19) & 4) >> 2,*(undefined2 *)(local_8 + 2));
        __chkesp();
      }
      local_10 = param_1[4] + *(short *)(local_8 + 4);
      local_e = param_1[5] + *(short *)(local_8 + 6);
      if ((int)*param_1 + (int)param_1[2] < (int)local_10) {
        local_10 = local_10 - param_1[2];
      }
      else if (local_10 < *param_1) {
        local_10 = local_10 + param_1[2];
      }
      if ((int)param_1[1] + (int)param_1[3] < (int)local_e) {
        local_e = local_e - param_1[3];
      }
      else if (local_e < param_1[1]) {
        local_e = local_e + param_1[3];
      }
      local_c = *(undefined2 *)(local_8 + 8);
      local_a = *(undefined2 *)(local_8 + 10);
      (*(code *)(&PTR_FUN_004bd000)[*local_8])
                (*(undefined4 *)(local_8 + (uint)DAT_004e89d8 * 4 + 0x1c),&local_10);
      __chkesp();
      FUN_00447810((int)param_1,&local_20);
      if (*local_8 == 2) {
        local_34 = (undefined4 *)(*(int *)(local_8 + (uint)DAT_004e89d8 * 4 + 0x1c) + 0xc);
        FUN_004478b0((int)local_34);
        local_30 = FUN_00445380(local_34);
        FUN_004479e0((int)local_34,local_30);
        FUN_0047d910(local_30,local_20,local_24,local_2c,local_28,5);
      }
      if (*local_8 == 1) {
        local_3c = (undefined4 *)(*(int *)(local_8 + (uint)DAT_004e89d8 * 4 + 0x1c) + 0xc);
        FUN_00448620((int)local_3c);
        local_38 = FUN_004453f0(local_3c);
        FUN_00448510((int)local_3c,local_38);
        FUN_0047d910(local_38,local_20,local_24,local_2c,local_28,1);
      }
      if (DAT_004bcfcc != 0) {
        if (*local_8 == 0) {
          local_44 = *(undefined4 **)(local_8 + (uint)DAT_004e89d8 * 4 + 0x1c);
          FUN_00448750((int)local_44);
          local_40 = FUN_00445460(local_44);
          FUN_00448170((int)local_44,local_40);
          FUN_0047d910(local_40,local_20,local_24,local_2c,local_28,3);
        }
        if (*local_8 == 3) {
          FUN_0047d910(*(int *)(local_8 + (uint)DAT_004e89d8 * 4 + 0x1c) + 0xc,local_20,local_24,
                       local_28,local_2c,*(ushort *)(local_8 + 2) + 8);
        }
      }
    }
    if ((char)param_1[0x14] != '\0') {
      *(char *)(param_1 + 0x14) = (char)param_1[0x14] + -1;
    }
  }
  local_8 = (byte *)0x448e27;
  __chkesp();
  return;
}

