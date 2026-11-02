/* FUN_00449bc0 @ 00449bc0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00449bc0(uint *param_1,int param_2,int param_3,char param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_7c [16];
  int local_3c;
  void *local_38;
  char *local_34;
  uint local_30;
  PVOID local_24;
  undefined4 local_20 [3];
  int local_14;
  int local_10;
  uint local_c;
  void *local_8;
  
  puVar4 = local_7c;
  for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = (void *)0x0;
  if (DAT_004e8603 == '\0') {
    FUN_00441270(0,0,0);
    DAT_004f2e22 = DAT_004f2e22 & 0xf7;
    iVar3 = FUN_00449b60(param_1,(uint *)&DAT_004b79e4,4);
    if (iVar3 == 0) {
      FUN_00458ec0();
      local_34 = (char *)FUN_00435000("win\\graphics\\font.kxp","lucky");
      FUN_00458ec0();
      local_38 = (void *)FUN_00431fe0(local_34,param_1);
      FUN_00435d90(local_34);
      local_24 = (PVOID)FUN_0043ff20(DAT_004e8488,DAT_004e848c,0,1);
      FUN_004408d0((int)local_24,(int)local_38,'\0');
      if (local_38 != (void *)0xdddddddd) {
        FUN_00495280(local_38);
      }
    }
    else {
      local_8 = (void *)FUN_004658d0((char *)param_1);
      FUN_00449510(local_8,local_20);
      local_24 = (PVOID)FUN_0043ff20((int)*(short *)(local_14 + 4),(int)*(short *)(local_14 + 6),0,1
                                    );
      FUN_004408d0((int)local_24,local_10,'\0');
    }
    (*DAT_004e8a7c)();
    uVar2 = __chkesp();
    if ((uVar2 & 0xff) != 0) {
      (*DAT_004e8a14)();
      __chkesp();
    }
    FUN_00440f30();
    DAT_004e8601 = 1;
    local_30 = local_30 & 0xffffff00;
    while ((local_30 & 0xff) < 0x21) {
      FUN_004454d0();
      (*DAT_004e8a10)(0);
      __chkesp();
      FUN_00440730((int)local_24,0x11);
      FUN_00440fb0();
      FUN_00441080();
      (*DAT_004e8a14)();
      __chkesp();
      FUN_00449380();
      local_30 = CONCAT31(local_30._1_3_,(char)local_30 + '\x01');
    }
    if (local_8 != (void *)0x0) {
      FUN_00465890(local_8);
    }
    local_c = 0;
    while( true ) {
      if (((uint)(param_3 * 0x3c) <= local_c) ||
         ((cVar1 = FUN_0045f3e0(), cVar1 == '\0' && (uVar2 = FUN_0043fdf0(), (uVar2 & 0xff) != 0))))
      goto LAB_00449edb;
      FUN_004454d0();
      if ((param_4 != '\0') &&
         (((DAT_004f2744 & 0x4008) != 0 && ((uint)(param_2 * 0x3c) < local_c)))) break;
      (*DAT_004e8a10)(0);
      __chkesp();
      FUN_00440730((int)local_24,0x11);
      (*DAT_004e8a14)();
      __chkesp();
      if (DAT_004e85b4 != '\0') {
        (*DAT_004e8a28)();
        local_3c = __chkesp();
        if (local_3c != 0) {
          FUN_004266d0("backpic.bmp",local_3c,DAT_004be3c8,DAT_004be3cc,'\x01');
        }
        DAT_004e85b4 = '\0';
      }
      FUN_00449380();
      if (DAT_004e8603 != '\0') goto LAB_00449f6b;
      local_c = local_c + 1;
    }
    (*DAT_004e8a14)();
    __chkesp();
LAB_00449edb:
    FUN_00440f70();
    DAT_004f2e0c = 0;
    local_30 = local_30 & 0xffffff00;
    while ((local_30 & 0xff) < 0x20) {
      FUN_004454d0();
      (*DAT_004e8a10)(0);
      __chkesp();
      FUN_00440730((int)local_24,0x11);
      FUN_00440fb0();
      FUN_00441080();
      (*DAT_004e8a14)();
      __chkesp();
      FUN_00449380();
      if (DAT_004e8603 != '\0') goto LAB_00449f6b;
      local_30 = CONCAT31(local_30._1_3_,(char)local_30 + '\x01');
    }
    DAT_004e8601 = 0;
    FUN_004405d0(local_24);
  }
LAB_00449f6b:
  local_8 = (void *)0x449f78;
  __chkesp();
  return;
}

