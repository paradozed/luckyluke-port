/* FUN_0043db50 @ 0043db50 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043db50(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined4 local_9c [16];
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
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
  float local_20;
  float local_1c;
  void *local_18;
  void *local_14;
  PVOID local_10;
  PVOID local_c;
  char *local_8;
  
  puVar4 = local_9c;
  for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  FUN_004435d0((uint *)"Fade control",0,0x440fb0,0,2);
  FUN_004435d0((uint *)"Fade draw",0,0x441080,0,2);
  local_1c = 6.0;
  local_10 = (PVOID)FUN_0043ff20(0x200,0x100,0,1);
  local_c = (PVOID)FUN_0043ff20(0x280,0x1e0,7,1);
  (*DAT_004e8a70)();
  __chkesp();
  local_8 = (char *)FUN_00435000("win\\graphics\\frame1.kxp","lucky");
  local_18 = (void *)FUN_00431fe0(local_8,(uint *)"f_back.pcx");
  local_14 = (void *)FUN_00431fe0(local_8,(uint *)(&PTR_s_f_t_e_pcx_004bcdb0)[DAT_004f17ea]);
  FUN_004408d0((int)local_10,(int)local_18,'\0');
  FUN_004408d0((int)local_c,(int)local_14,'\0');
  if (local_18 != (void *)0xdddddddd) {
    FUN_00495280(local_18);
  }
  if (local_14 != (void *)0xdddddddd) {
    FUN_00495280(local_14);
  }
  FUN_00435d90(local_8);
  uVar5 = FUN_00497360();
  local_28 = (int)uVar5;
  local_20 = (float)local_28 / _DAT_004b40d4;
  FUN_00440f30();
  local_24 = 0;
  do {
    FUN_0045f3e0();
    FUN_004454d0();
    uVar2 = FUN_0043fd80();
    if (((uVar2 & 0xff) != 0) && (bVar1 = FUN_004411c0(), !bVar1)) break;
    uVar5 = FUN_00497360();
    local_2c = (int)uVar5;
    if ((local_1c < (float)local_2c / _DAT_004b40d4 - local_20) && (local_24 == 0)) {
      FUN_00440f70();
      local_24 = 1;
    }
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_10,0x19);
    FUN_00440730((int)local_c,0x11);
    FUN_004437e0(2);
    (*DAT_004e8a14)();
    __chkesp();
    (*DAT_004e8a0c)();
    __chkesp();
    bVar1 = FUN_004411c0();
  } while ((bVar1) || (local_24 == 0));
  local_8 = (char *)FUN_00435000("win\\graphics\\frame2.kxp","lucky");
  local_18 = (void *)FUN_00431fe0(local_8,(uint *)"f_back.pcx");
  local_14 = (void *)FUN_00431fe0(local_8,(uint *)(&PTR_s_f_t_e_pcx_004bcdb0)[DAT_004f17ea]);
  FUN_004408d0((int)local_10,(int)local_18,'\0');
  FUN_004408d0((int)local_c,(int)local_14,'\0');
  if (local_18 != (void *)0xdddddddd) {
    FUN_00495280(local_18);
  }
  if (local_14 != (void *)0xdddddddd) {
    FUN_00495280(local_14);
  }
  FUN_00435d90(local_8);
  uVar5 = FUN_00497360();
  local_30 = (int)uVar5;
  local_20 = (float)local_30 / _DAT_004b40d4;
  FUN_00440f30();
  local_24 = 0;
  do {
    FUN_0045f3e0();
    FUN_004454d0();
    uVar2 = FUN_0043fd80();
    if (((uVar2 & 0xff) != 0) && (bVar1 = FUN_004411c0(), !bVar1)) break;
    uVar5 = FUN_00497360();
    local_34 = (int)uVar5;
    if ((local_1c < (float)local_34 / _DAT_004b40d4 - local_20) && (local_24 == 0)) {
      FUN_00440f70();
      local_24 = 1;
    }
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_10,0x19);
    FUN_00440730((int)local_c,0x11);
    FUN_004437e0(2);
    (*DAT_004e8a14)();
    __chkesp();
    (*DAT_004e8a0c)();
    __chkesp();
    bVar1 = FUN_004411c0();
  } while ((bVar1) || (local_24 == 0));
  local_8 = (char *)FUN_00435000("win\\graphics\\frame3.kxp","lucky");
  local_18 = (void *)FUN_00431fe0(local_8,(uint *)"f_back.pcx");
  local_14 = (void *)FUN_00431fe0(local_8,(uint *)(&PTR_s_f_t_e_pcx_004bcdb0)[DAT_004f17ea]);
  FUN_004408d0((int)local_10,(int)local_18,'\0');
  FUN_004408d0((int)local_c,(int)local_14,'\0');
  if (local_18 != (void *)0xdddddddd) {
    FUN_00495280(local_18);
  }
  if (local_14 != (void *)0xdddddddd) {
    FUN_00495280(local_14);
  }
  FUN_00435d90(local_8);
  uVar5 = FUN_00497360();
  local_38 = (int)uVar5;
  local_20 = (float)local_38 / _DAT_004b40d4;
  FUN_00440f30();
  local_24 = 0;
  do {
    FUN_0045f3e0();
    FUN_004454d0();
    uVar2 = FUN_0043fd80();
    if (((uVar2 & 0xff) != 0) && (bVar1 = FUN_004411c0(), !bVar1)) break;
    uVar5 = FUN_00497360();
    local_3c = (int)uVar5;
    if ((local_1c < (float)local_3c / _DAT_004b40d4 - local_20) && (local_24 == 0)) {
      FUN_00440f70();
      local_24 = 1;
    }
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_10,0x19);
    FUN_00440730((int)local_c,0x11);
    FUN_004437e0(2);
    (*DAT_004e8a14)();
    __chkesp();
    (*DAT_004e8a0c)();
    __chkesp();
    bVar1 = FUN_004411c0();
  } while ((bVar1) || (local_24 == 0));
  local_8 = (char *)FUN_00435000("win\\graphics\\frame4.kxp","lucky");
  local_18 = (void *)FUN_00431fe0(local_8,(uint *)"f_back.pcx");
  local_14 = (void *)FUN_00431fe0(local_8,(uint *)(&PTR_s_f_t_e_pcx_004bcdb0)[DAT_004f17ea]);
  FUN_004408d0((int)local_10,(int)local_18,'\0');
  FUN_004408d0((int)local_c,(int)local_14,'\0');
  if (local_18 != (void *)0xdddddddd) {
    FUN_00495280(local_18);
  }
  if (local_14 != (void *)0xdddddddd) {
    FUN_00495280(local_14);
  }
  FUN_00435d90(local_8);
  uVar5 = FUN_00497360();
  local_40 = (int)uVar5;
  local_20 = (float)local_40 / _DAT_004b40d4;
  FUN_00440f30();
  local_24 = 0;
  do {
    FUN_0045f3e0();
    FUN_004454d0();
    uVar2 = FUN_0043fd80();
    if (((uVar2 & 0xff) != 0) && (bVar1 = FUN_004411c0(), !bVar1)) break;
    uVar5 = FUN_00497360();
    local_44 = (int)uVar5;
    if ((local_1c < (float)local_44 / _DAT_004b40d4 - local_20) && (local_24 == 0)) {
      FUN_00440f70();
      local_24 = 1;
    }
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_10,0x19);
    FUN_00440730((int)local_c,0x11);
    FUN_004437e0(2);
    (*DAT_004e8a14)();
    __chkesp();
    (*DAT_004e8a0c)();
    __chkesp();
    bVar1 = FUN_004411c0();
  } while ((bVar1) || (local_24 == 0));
  local_8 = (char *)FUN_00435000("win\\graphics\\frame5.kxp","lucky");
  local_18 = (void *)FUN_00431fe0(local_8,(uint *)"f_back.pcx");
  local_14 = (void *)FUN_00431fe0(local_8,(uint *)(&PTR_s_f_t_e_pcx_004bcdb0)[DAT_004f17ea]);
  FUN_004408d0((int)local_10,(int)local_18,'\0');
  FUN_004408d0((int)local_c,(int)local_14,'\0');
  if (local_18 != (void *)0xdddddddd) {
    FUN_00495280(local_18);
  }
  if (local_14 != (void *)0xdddddddd) {
    FUN_00495280(local_14);
  }
  FUN_00435d90(local_8);
  uVar5 = FUN_00497360();
  local_48 = (int)uVar5;
  local_20 = (float)local_48 / _DAT_004b40d4;
  FUN_00440f30();
  local_24 = 0;
  do {
    FUN_0045f3e0();
    FUN_004454d0();
    uVar2 = FUN_0043fd80();
    if (((uVar2 & 0xff) != 0) && (bVar1 = FUN_004411c0(), !bVar1)) break;
    uVar5 = FUN_00497360();
    local_4c = (int)uVar5;
    if ((local_1c < (float)local_4c / _DAT_004b40d4 - local_20) && (local_24 == 0)) {
      FUN_00440f70();
      local_24 = 1;
    }
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_10,0x19);
    FUN_00440730((int)local_c,0x11);
    FUN_004437e0(2);
    (*DAT_004e8a14)();
    __chkesp();
    (*DAT_004e8a0c)();
    __chkesp();
    bVar1 = FUN_004411c0();
  } while ((bVar1) || (local_24 == 0));
  local_8 = (char *)FUN_00435000("win\\graphics\\frame6.kxp","lucky");
  local_18 = (void *)FUN_00431fe0(local_8,(uint *)"f_back.pcx");
  local_14 = (void *)FUN_00431fe0(local_8,(uint *)(&PTR_s_f_t_e_pcx_004bcdb0)[DAT_004f17ea]);
  FUN_004408d0((int)local_10,(int)local_18,'\0');
  FUN_004408d0((int)local_c,(int)local_14,'\0');
  if (local_18 != (void *)0xdddddddd) {
    FUN_00495280(local_18);
  }
  if (local_14 != (void *)0xdddddddd) {
    FUN_00495280(local_14);
  }
  FUN_00435d90(local_8);
  uVar5 = FUN_00497360();
  local_50 = (int)uVar5;
  local_20 = (float)local_50 / _DAT_004b40d4;
  FUN_00440f30();
  local_24 = 0;
  do {
    FUN_0045f3e0();
    FUN_004454d0();
    uVar2 = FUN_0043fd80();
    if (((uVar2 & 0xff) != 0) && (bVar1 = FUN_004411c0(), !bVar1)) break;
    uVar5 = FUN_00497360();
    local_54 = (int)uVar5;
    if ((local_1c < (float)local_54 / _DAT_004b40d4 - local_20) && (local_24 == 0)) {
      FUN_00440f70();
      local_24 = 1;
    }
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_10,0x19);
    FUN_00440730((int)local_c,0x11);
    FUN_004437e0(2);
    (*DAT_004e8a14)();
    __chkesp();
    (*DAT_004e8a0c)();
    __chkesp();
    bVar1 = FUN_004411c0();
  } while ((bVar1) || (local_24 == 0));
  local_8 = (char *)FUN_00435000("win\\graphics\\frame7.kxp","lucky");
  local_18 = (void *)FUN_00431fe0(local_8,(uint *)"f_back.pcx");
  local_14 = (void *)FUN_00431fe0(local_8,(uint *)(&PTR_s_f_t_e_pcx_004bcdb0)[DAT_004f17ea]);
  FUN_004408d0((int)local_10,(int)local_18,'\0');
  FUN_004408d0((int)local_c,(int)local_14,'\0');
  if (local_18 != (void *)0xdddddddd) {
    FUN_00495280(local_18);
  }
  if (local_14 != (void *)0xdddddddd) {
    FUN_00495280(local_14);
  }
  FUN_00435d90(local_8);
  uVar5 = FUN_00497360();
  local_58 = (int)uVar5;
  local_20 = (float)local_58 / _DAT_004b40d4;
  FUN_00440f30();
  local_24 = 0;
  do {
    FUN_0045f3e0();
    FUN_004454d0();
    uVar2 = FUN_0043fd80();
    if (((uVar2 & 0xff) != 0) && (bVar1 = FUN_004411c0(), !bVar1)) break;
    uVar5 = FUN_00497360();
    local_5c = (int)uVar5;
    if ((local_1c < (float)local_5c / _DAT_004b40d4 - local_20) && (local_24 == 0)) {
      FUN_00440f70();
      local_24 = 1;
    }
    (*DAT_004e8a10)(0);
    __chkesp();
    FUN_00440730((int)local_10,0x19);
    FUN_00440730((int)local_c,0x11);
    FUN_004437e0(2);
    (*DAT_004e8a14)();
    __chkesp();
    (*DAT_004e8a0c)();
    __chkesp();
    bVar1 = FUN_004411c0();
  } while ((bVar1) || (local_24 == 0));
  FUN_004405d0(local_10);
  FUN_004405d0(local_c);
  FUN_00443890();
  local_8 = (char *)0x43e763;
  __chkesp();
  return;
}

