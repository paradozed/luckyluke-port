/* FUN_00490cc0 @ 00490cc0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00490cc0(undefined2 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_cc [16];
  uint local_8c;
  int local_88;
  ushort local_84 [2];
  int iStack_80;
  undefined2 uStack_7c;
  undefined2 local_7a;
  undefined2 uStack_74;
  undefined2 local_72;
  undefined2 uStack_6c;
  undefined2 local_6a;
  undefined2 uStack_64;
  undefined2 local_62;
  undefined2 uStack_5c;
  undefined2 local_5a;
  undefined2 uStack_54;
  undefined2 local_52;
  undefined2 uStack_4c;
  undefined2 local_4a;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  
  puVar2 = local_cc;
  for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8c = CONCAT31(local_8c._1_3_,1);
  local_44 = *param_1;
  local_42 = param_1[2];
  local_40 = param_1[4];
  local_3c = *param_1;
  local_3a = param_1[8];
  local_38 = param_1[4];
  local_34 = *param_1;
  local_32 = param_1[2];
  local_30 = param_1[10];
  local_2c = param_1[6];
  local_2a = param_1[2];
  local_28 = param_1[4];
  local_24 = param_1[6];
  local_22 = param_1[8];
  local_20 = param_1[4];
  local_1c = param_1[6];
  local_1a = param_1[2];
  local_18 = param_1[10];
  local_14 = *param_1;
  local_12 = param_1[8];
  local_10 = param_1[10];
  local_c = param_1[6];
  local_a = param_1[8];
  local_8 = CONCAT22(local_8._2_2_,param_1[10]);
  FUN_004823a0((undefined4 *)&DAT_00508180);
  FUN_004824a0(0x508180);
  FUN_0047fa00((int)&local_44,(int)local_84,8);
  local_88 = 0;
  do {
    if (7 < local_88) {
LAB_00490e51:
      if ((local_8c & 0xff) != 0) {
        for (local_88 = 0; local_88 < 8; local_88 = local_88 + 1) {
          FUN_00488090(0,(uint)local_84[local_88 * 4],(uint)local_84[local_88 * 4 + 1],1);
        }
      }
      if ((local_8c & 0xff) != 0) {
        (*DAT_004e8a3c)(local_84[0],local_84[1],uStack_7c,local_7a,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(local_84[0],local_84[1],uStack_74,local_72,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(local_84[0],local_84[1],uStack_6c,local_6a,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(uStack_4c,local_4a,uStack_54,local_52,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(uStack_4c,local_4a,uStack_5c,local_5a,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(uStack_4c,local_4a,uStack_64,local_62,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(uStack_7c,local_7a,uStack_64,local_62,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(uStack_7c,local_7a,uStack_54,local_52,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(uStack_5c,local_5a,uStack_6c,local_6a,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(uStack_5c,local_5a,uStack_74,local_72,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(uStack_64,local_62,uStack_6c,local_6a,param_2,param_3,param_4);
        __chkesp();
        (*DAT_004e8a3c)(uStack_54,local_52,uStack_74,local_72,param_2,param_3,param_4);
        __chkesp();
      }
      local_8 = 0x49120b;
      __chkesp();
      return;
    }
    if ((&iStack_80)[local_88 * 2] < 0) {
      local_8c = local_8c & 0xffffff00;
      goto LAB_00490e51;
    }
    local_88 = local_88 + 1;
  } while( true );
}

