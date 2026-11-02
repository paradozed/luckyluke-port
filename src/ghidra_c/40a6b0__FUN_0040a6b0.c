/* FUN_0040a6b0 @ 0040a6b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040a6b0(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_88 [16];
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar3 = local_88;
  for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_38 = FUN_00407580(param_1);
  local_3c = **(int **)(local_38 + 8);
  local_40 = **(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_24 = *(int *)(local_40 + 0x90);
  local_20 = *(undefined4 *)(local_40 + 0x94);
  local_1c = *(int *)(local_40 + 0x98);
  local_14 = *(int *)(local_3c + 0x90);
  local_10 = *(int *)(local_3c + 0x94);
  local_c = *(int *)(local_3c + 0x98);
  local_28 = local_14 - local_24;
  local_2c = local_c - local_1c;
  local_48 = 0;
  do {
    if (6 < local_48) {
LAB_0040ab3d:
      uStack_8 = 0x40ab4d;
      __chkesp();
      return;
    }
    if (((0 < local_28) && (local_1c + -1000 < local_c)) && (local_c < local_1c + 1000)) {
      FUN_00408d40(**(int **)(DAT_004d1de8 + 8),local_14,local_10 + -800,local_c + -1000);
      local_44 = DAT_004d1de8;
      iVar2 = DAT_004d1de8;
      pvVar1 = (void *)FUN_00409d00(param_1);
      FUN_00421ea0(pvVar1,iVar2);
      goto LAB_0040ab3d;
    }
    if (0 < local_28) {
      local_30 = (local_14 - (local_24 + -0x5dc)) - (local_c - (local_1c + 0x5dc));
      local_34 = (local_14 - (local_24 + 0x5dc)) - (local_c - (local_1c + -0x5dc));
      if (local_30 * local_34 < 0) {
        FUN_00408d40(**(int **)(DAT_004d1dec + 8),local_14,local_10 + -800,local_c + -1000);
        local_44 = DAT_004d1dec;
        iVar2 = DAT_004d1dec;
        pvVar1 = (void *)FUN_00409d00(param_1);
        FUN_00421ea0(pvVar1,iVar2);
        goto LAB_0040ab3d;
      }
    }
    if ((local_24 + -1000 < local_14) && (local_14 < local_24 + 1000)) {
      if (local_2c < 1) {
        FUN_00408d40(**(int **)(DAT_004d1dfc + 8),local_14,local_10 + -800,local_c + -1000);
        local_44 = DAT_004d1dfc;
        iVar2 = DAT_004d1dfc;
        pvVar1 = (void *)FUN_00409d00(param_1);
        FUN_00421ea0(pvVar1,iVar2);
      }
      else {
        FUN_00408d40(**(int **)(DAT_004d1df0 + 8),local_14,local_10 + -800,local_c + -1000);
        local_44 = DAT_004d1df0;
        iVar2 = DAT_004d1df0;
        pvVar1 = (void *)FUN_00409d00(param_1);
        FUN_00421ea0(pvVar1,iVar2);
      }
      goto LAB_0040ab3d;
    }
    if (local_28 < 0) {
      local_30 = -(local_c - (local_1c + -0x5dc)) - (local_14 - (local_24 + -0x5dc));
      local_34 = -(local_c - (local_1c + 0x5dc)) - (local_14 - (local_24 + 0x5dc));
      if (local_30 * local_34 < 0) {
        FUN_00408d40(**(int **)(DAT_004d1df4 + 8),local_14,local_10 + -800,local_c + -1000);
        local_44 = DAT_004d1df4;
        iVar2 = DAT_004d1df4;
        pvVar1 = (void *)FUN_00409d00(param_1);
        FUN_00421ea0(pvVar1,iVar2);
        goto LAB_0040ab3d;
      }
    }
    if (local_28 < 0) {
      local_30 = (local_c - (local_1c + 0x5dc)) - (local_14 - (local_24 + -0x5dc));
      local_34 = (local_c - (local_1c + -0x5dc)) - (local_14 - (local_24 + 0x5dc));
      if (local_30 * local_34 < 0) {
        FUN_00408d40(**(int **)(DAT_004d1df8 + 8),local_14,local_10 + -800,local_c + -1000);
        local_44 = DAT_004d1df8;
        iVar2 = DAT_004d1df8;
        pvVar1 = (void *)FUN_00409d00(param_1);
        FUN_00421ea0(pvVar1,iVar2);
        goto LAB_0040ab3d;
      }
    }
    if (0 < local_28) {
      local_30 = -(local_c - (local_1c + -0x5dc)) - (local_14 - (local_24 + -0x5dc));
      local_34 = -(local_c - (local_1c + 0x5dc)) - (local_14 - (local_24 + 0x5dc));
      if (local_30 * local_34 < 0) {
        FUN_00408d40(**(int **)(DAT_004d1e00 + 8),local_14,local_10 + -800,local_c + -1000);
        local_44 = DAT_004d1e00;
        iVar2 = DAT_004d1e00;
        pvVar1 = (void *)FUN_00409d00(param_1);
        FUN_00421ea0(pvVar1,iVar2);
        goto LAB_0040ab3d;
      }
    }
    local_48 = local_48 + 1;
  } while( true );
}

