/* FUN_00482a90 @ 00482a90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00482a90(short *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [16];
  short local_9c;
  undefined2 local_98;
  short local_94;
  undefined2 local_90;
  short local_8c;
  undefined2 local_88;
  undefined4 local_84 [8];
  undefined2 local_64;
  short local_62;
  undefined2 local_60;
  short local_5e;
  undefined2 local_5c;
  undefined2 local_5a;
  undefined2 local_58;
  undefined2 local_56;
  undefined2 local_54;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  short local_3a;
  undefined2 local_38;
  short local_36;
  undefined2 local_34;
  undefined2 local_24;
  undefined2 local_22;
  short local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  short local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined4 uStack_8;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_88 = FUN_00482c60(*param_1);
  local_8c = FUN_00482cb0(*param_1);
  local_90 = FUN_00482c60(param_1[1]);
  local_94 = FUN_00482cb0(param_1[1]);
  local_98 = FUN_00482c60(param_1[2]);
  local_9c = FUN_00482cb0(param_1[2]);
  local_44 = 0x1000;
  local_42 = 0;
  local_40 = 0;
  local_3e = 0;
  local_3c = local_88;
  local_3a = -local_8c;
  local_38 = 0;
  local_36 = local_8c;
  local_34 = local_88;
  local_24 = local_90;
  local_22 = 0;
  local_20 = local_94;
  local_1e = 0;
  local_1c = 0x1000;
  local_1a = 0;
  local_18 = -local_94;
  local_16 = 0;
  local_14 = local_90;
  local_64 = local_98;
  local_62 = -local_9c;
  local_60 = 0;
  local_5c = local_98;
  local_5a = 0;
  local_58 = 0;
  local_56 = 0;
  local_54 = 0x1000;
  local_5e = local_9c;
  FUN_004824e0((undefined4 *)&local_44,(int)&local_24,local_84);
  FUN_004824e0(local_84,(int)&local_64,param_2);
  uStack_8 = 0x482c55;
  __chkesp();
  return;
}

