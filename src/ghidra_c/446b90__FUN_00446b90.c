/* FUN_00446b90 @ 00446b90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00446b90(int param_1,byte param_2,uint param_3,short param_4,short param_5,short param_6,
            short param_7,undefined4 param_8,undefined4 param_9,short param_10,short param_11)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_74 [16];
  short local_34;
  short local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  char local_1c;
  uint local_18;
  short local_14;
  short local_12;
  short local_10;
  short local_e;
  ushort local_c;
  short local_a;
  undefined4 local_8;
  
  puVar2 = local_74;
  for (iVar1 = 0x1c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = local_18 & 0xffffff00;
  if ((*DAT_004e8310 & 1) != 0) {
    local_2c = *(int *)(DAT_004e8820 + 4 + (param_3 & 0xff) * 4);
    local_20 = FUN_00446540(param_1,param_2);
    if (local_20 != 0) {
      if (0xff8 < *(ushort *)(local_20 + 0x24)) {
        param_5 = (short)(param_5 * 0x100 + (param_5 * 0x100 >> 0x1f & 0xffU) >> 8);
      }
      if ((param_6 != param_10) || (param_7 != param_11)) {
        local_18 = CONCAT31(local_18._1_3_,1);
      }
      local_30 = *(short *)(DAT_004d1e78 + local_2c * 4);
      local_34 = *(short *)(DAT_004d1e78 + 2 + local_2c * 4);
      local_24 = DAT_004d1e7c + local_30 * 0x14;
      local_28 = DAT_004d1e80 + local_34 * 0x10;
      local_1c = '\x02' - ((byte)*(undefined2 *)(local_24 + 0xc) & 3);
      local_c = (ushort)*(byte *)(local_24 + 0x10);
      local_a = *(byte *)(local_24 + 0x11) + 1;
      local_8 = CONCAT22(param_11 + -2,param_10);
      local_12 = param_5;
      local_14 = param_4;
      local_e = param_7;
      local_10 = param_6;
      if ((local_18 & 0xff) == 0) {
        FUN_00446960(local_20,(undefined1 *)&local_c,&local_14,local_24,local_28);
      }
      else {
        FUN_00446690(local_20,(char *)&local_c,&local_14,local_24,local_28);
      }
    }
  }
  local_8 = 0x446d34;
  __chkesp();
  return;
}

