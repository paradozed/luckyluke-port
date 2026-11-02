/* FUN_00446f50 @ 00446f50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00446f50(int param_1,byte param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,
            undefined2 param_6,byte param_7,byte param_8,byte param_9,byte param_10,byte param_11,
            byte param_12,byte param_13,byte param_14,byte param_15,byte param_16,byte param_17,
            byte param_18)

{
  int iVar1;
  undefined2 extraout_var;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  uint local_20;
  undefined1 local_1c [12];
  int local_10;
  byte *local_c;
  int local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_20 = local_20 & 0xffffff00;
  if ((((*DAT_004e8310 & 2) != 0) && (local_8 = FUN_00446540(param_1,param_2), local_8 != 0)) &&
     (local_c = (byte *)FUN_004465c0(local_8,2), local_c != (byte *)0x0)) {
    *(undefined2 *)(local_c + 4) = param_3;
    *(undefined2 *)(local_c + 6) = param_4;
    *(undefined2 *)(local_c + 8) = param_5;
    *(undefined2 *)(local_c + 10) = param_6;
    local_c[0xc] = param_7;
    local_c[0xd] = param_8;
    local_c[0xe] = param_9;
    local_c[0xf] = param_10;
    local_c[0x10] = param_11;
    local_c[0x11] = param_12;
    local_c[0x12] = param_13;
    local_c[0x13] = param_14;
    local_c[0x14] = param_15;
    local_c[0x15] = param_16;
    local_c[0x16] = param_17;
    local_c[0x17] = param_18;
    local_c[2] = 0;
    local_c[3] = 0;
    do {
      local_10 = *(int *)(local_c + (local_20 & 0xff) * 4 + 0x1c);
      local_20 = CONCAT31(local_20._1_3_,(char)local_20 + '\x01');
      *(uint *)(local_10 + 0xc) = *(uint *)(local_10 + 0xc) & 0xffffff | 0x8000000;
      *(undefined1 *)(local_10 + 0x13) = 0x38;
      (*(code *)(&PTR_FUN_004bd000)[*local_c])(local_10,local_c + 4);
      __chkesp();
      (*(code *)(&PTR_FUN_004bd020)[*local_c])(local_c + 0xc,local_1c,local_8 + 0x15);
      __chkesp();
      (*(code *)(&PTR_FUN_004bd010)[*local_c])(local_10,local_1c);
      __chkesp();
      FUN_00426640();
      FUN_00426680();
      (*(code *)(&PTR_FUN_004bd030)[*local_c])
                (local_10,*(byte *)(local_8 + 0x19) & 0xfb,(int)(*(byte *)(local_8 + 0x19) & 4) >> 2
                 ,CONCAT22(extraout_var,*(undefined2 *)(local_c + 2)));
      __chkesp();
    } while ((local_20 & 0xff) < 2);
  }
  local_8 = 0x4471ab;
  __chkesp();
  return;
}

