/* FUN_004b0969 @ 004b0969 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004b0969(uint *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint local_8c [8];
  char local_6c;
  undefined1 local_68;
  undefined4 local_67;
  
  local_68 = DAT_004c88fc;
  puVar2 = &local_67;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  local_6c = '\x01';
  if (param_2 < -0x7fffbffa) {
    if (param_2 == -0x7fffbffb) {
      FUN_00497270(local_8c,(uint *)s_GENERIC_004c8b6c);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7fffbfff) {
      FUN_00497270(local_8c,(uint *)s_UNSUPPORTED_004c8b78);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7ff8ffa8) {
    if (param_2 == -0x7ff8ffa9) {
      FUN_00497270(local_8c,(uint *)s_DDERR_INVALIDPARAMS_004c89e0);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7ff8fff2) {
      FUN_00497270(local_8c,(uint *)s_DDERR_OUTOFMEMORY_004c8a9c);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789ff9b) {
    if (param_2 == -0x7789ff9c) {
      FUN_00497270(local_8c,(uint *)s_DDERR_INVALIDCAPS_004c8a18);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789ffa1) {
      FUN_00497270(local_8c,(uint *)s_DDERR_INCOMPATIBLEPRIMARY_004c8a80);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789ff87) {
    if (param_2 == -0x7789ff88) {
      FUN_00497270(local_8c,(uint *)s_DDERR_INVALIDMODE_004c8b88);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789ff92) {
      FUN_00497270(local_8c,(uint *)s_DDERR_INVALIDCLIPLIST_004c89b0);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789ff6e) {
    if (param_2 == -0x7789ff6f) {
      FUN_00497270(local_8c,(uint *)s_DDERR_INVALIDPIXELFORMAT_004c8ae4);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789ff7e) {
      FUN_00497270(local_8c,(uint *)s_DDERR_INVALIDOBJECT_004c8ab0);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789ff5f) {
    if (param_2 == -0x7789ff60) {
      FUN_00497270(local_8c,(uint *)s_DDERR_LOCKEDSURFACES_004c8b9c);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789ff6a) {
      FUN_00497270(local_8c,(uint *)s_DDERR_INVALIDRECT_004c89c8);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789ff32) {
    if (param_2 == -0x7789ff33) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOCLIPLIST_004c8928);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789ff4c) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOALPHAHW_004c8a2c);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789ff1e) {
    if (param_2 == -0x7789ff1f) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOEXCLUSIVEMODE_004c8b14);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789ff2c) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOCOOPERATIVELEVELSET_004c89f8);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789ff05) {
    if (param_2 == -0x7789ff06) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOMIRRORHW_004c8914);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789ff1a) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOFLIPHW_004c8b00);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789fee7) {
    if (param_2 == -0x7789fee8) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NORASTEROPHW_004c8968);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789ff01) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOTFOUND_004c8b58);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789feab) {
    if (param_2 == -0x7789feac) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOZBUFFERHW_004c8a40);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789feca) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOSTRETCHHW_004c8980);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789fe83) {
    if (param_2 == -0x7789fe84) {
      FUN_00497270(local_8c,(uint *)s_DDERR_OUTOFVIDEOMEMORY_004c8ac8);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789fe98) {
      FUN_00497270(local_8c,(uint *)s_DDERR_OUTOFCAPS_004c8900);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789fe3d) {
    if (param_2 == -0x7789fe3e) {
      FUN_00497270(local_8c,(uint *)s_DDERR_SURFACELOST_004c8b44);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789fe52) {
      FUN_00497270(local_8c,(uint *)s_DDERR_SURFACEBUSY_004c8bcc);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789fdcc) {
    if (param_2 == -0x7789fdcd) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NODIRECTDRAWHW_004c8b2c);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789fde4) {
      FUN_00497270(local_8c,(uint *)s_DDERR_WASSTILLDRAWING_004c8bb4);
      goto LAB_004b0fb0;
    }
  }
  else if (param_2 < -0x7789fdc0) {
    if (param_2 == -0x7789fdc1) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOBLTHW_004c8954);
      local_6c = '\0';
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789fdcc) {
      FUN_00497270(local_8c,(uint *)s_DDERR_PRIMARYSURFACEALREADYEXIST_004c8a58);
      goto LAB_004b0fb0;
    }
  }
  else {
    if (param_2 == -0x7789fdc0) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NODDROPSHW_004c8998);
      goto LAB_004b0fb0;
    }
    if (param_2 == -0x7789fdba) {
      FUN_00497270(local_8c,(uint *)s_DDERR_NOTFLIPPABLE_004c893c);
      goto LAB_004b0fb0;
    }
    if (param_2 == 0) {
      FUN_00497270(local_8c,(uint *)s_ALL_IS_OK_004c8be0);
      goto LAB_004b0fb0;
    }
  }
  FUN_00497270(local_8c,(uint *)s_UNKNOWN_ERROR_004c8bec);
LAB_004b0fb0:
  if (local_6c != '\0') {
    FUN_00497280((uint *)&local_68,param_1);
    FUN_00497280((uint *)&local_68,local_8c);
    OutputDebugStringA(&local_68);
  }
  return;
}

