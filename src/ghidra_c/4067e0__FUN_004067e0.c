/* FUN_004067e0 @ 004067e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004067e0(void)

{
  char cVar1;
  short sVar2;
  HWND pHVar3;
  uint dwNewLong;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  bool bVar8;
  LPCSTR lpString;
  LONG dwNewLong_00;
  undefined4 local_260 [16];
  int local_220;
  uint local_21c;
  CHAR local_218 [256];
  int local_118;
  int local_114;
  uint local_110;
  int local_10c;
  undefined4 uStack_8;
  
  puVar7 = local_260;
  for (iVar6 = 0x97; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  local_10c = 0;
  FUN_004066f0();
  FUN_00497410((uint *)"FX_GLIDE_NO_SPLASH=1");
  FUN_00427960();
  FUN_00458ec0();
  FUN_00404b10();
  AVIFileInit();
  cVar1 = FUN_0042b410();
  if (cVar1 != '\0') {
    if (DAT_004e8590 != 0) {
      DAT_004bcfd4 = 0;
    }
    iVar6 = FUN_00406690();
    if ((iVar6 == 0) && (DAT_004e8590 != 0)) {
      MessageBoxA((HWND)0x0,DAT_004f5dd8,DAT_004f5dd4,0);
      __chkesp();
    }
    else {
      FUN_00458ec0();
      FUN_00444e80();
      FUN_00458ec0();
      FUN_00458ec0();
      cVar1 = FUN_00404f60();
      if (cVar1 == '\0') {
        FUN_004450f0();
      }
      else {
        if (DAT_004e8590 == 0) {
          iVar6 = -0x10;
          pHVar3 = (HWND)FUN_00445810();
          GetWindowLongA(pHVar3,iVar6);
          local_110 = __chkesp();
          dwNewLong = local_110 & 0xfff7ffff;
          iVar6 = -0x10;
          pHVar3 = (HWND)FUN_00445810();
          SetWindowLongA(pHVar3,iVar6,dwNewLong);
          __chkesp();
        }
        lpString = DAT_004f5dfc;
        pHVar3 = (HWND)FUN_00445810();
        SetWindowTextA(pHVar3,lpString);
        __chkesp();
        DAT_004f17e8 = 0;
        DAT_004f2e22 = 0;
        DAT_004d1d8c = 0;
        FUN_0041e500();
        if (DAT_004e8590 == 0) {
          local_10c = 0;
          while( true ) {
            ShowCursor(0);
            iVar6 = __chkesp();
            if (iVar6 < 0) break;
            local_10c = local_10c + 1;
          }
          dwNewLong_00 = 0;
          iVar6 = -0xe;
          pHVar3 = (HWND)FUN_00445810();
          SetClassLongA(pHVar3,iVar6,dwNewLong_00);
          __chkesp();
        }
        if (DAT_004e8588 != 0) {
          (*DAT_004e8a78)(0);
          __chkesp();
          FUN_00404be0();
          FUN_0043fe80();
          (*DAT_004e8a78)(0);
          __chkesp();
          FUN_00497270((uint *)&DAT_004f57a0,(uint *)"aplogo.pcx");
          FUN_00449bc0((uint *)&DAT_004f57a0,5,10,'\x01');
          FUN_0043fe80();
          (*DAT_004e8a78)(0);
          __chkesp();
          local_21c = (uint)DAT_004f17ea;
          switch(local_21c) {
          case 0:
            FUN_00497270((uint *)&DAT_004f57a0,(uint *)"li_en.pcx");
            break;
          case 1:
            FUN_00497270((uint *)&DAT_004f57a0,(uint *)"li_fr.pcx");
            break;
          case 2:
            FUN_00497270((uint *)&DAT_004f57a0,(uint *)"li_ge.pcx");
            break;
          case 3:
            FUN_00497270((uint *)&DAT_004f57a0,(uint *)"li_sp.pcx");
            break;
          case 4:
            FUN_00497270((uint *)&DAT_004f57a0,(uint *)"li_it.pcx");
            break;
          case 5:
            FUN_00497270((uint *)&DAT_004f57a0,(uint *)"li_du.pcx");
            break;
          case 6:
            FUN_00497270((uint *)&DAT_004f57a0,(uint *)"li_br.pcx");
          }
          FUN_00449bc0((uint *)&DAT_004f57a0,5,10,'\x01');
        }
        FUN_0043fe80();
        (*DAT_004e8a78)(0);
        __chkesp();
        do {
          if (DAT_004e8603 != '\0') break;
          FUN_0046d7b0(0x9a4ec86);
          DAT_004d1d88 = FUN_004056d0();
          FUN_00458ec0();
          local_114 = FUN_0046d9a0(FUN_0044bcf0);
          FUN_0046daa0(local_114);
          DAT_004d1d70 = '\0';
          DAT_004e8581 = 1;
          FUN_00471940();
          FUN_00443a60();
          (*DAT_004e8a78)(0);
          __chkesp();
          while (DAT_004f1e21 == '\0') {
            FUN_004719e0();
            FUN_00406560();
            if (((DAT_004e8584 != 0) && (DAT_004e8974 == '\x01')) && ((DAT_004f59ef & 0x80) != 0)) {
              FUN_00472b60((uint *)(&PTR_s_abilene_004be118)[DAT_004e8976]);
            }
            if ((DAT_004e8984 != '\0') && (DAT_004e8974 == '\0')) {
              DAT_004e8914 = 1;
              DAT_004f1e21 = '\x01';
              DAT_004e8984 = '\0';
              DAT_004f160c = 0;
              DAT_004f29ac = 0;
              FUN_00473af0();
            }
            sVar2 = FUN_00406210();
            if (sVar2 == 0) {
              FUN_0040f510();
              FUN_00422780(&DAT_004d1da8,DAT_004d1d88);
              FUN_00471520();
            }
            if (DAT_004f1e21 == '\0') {
              FUN_00471620();
              if (DAT_004e8582 == '\0') {
                FUN_0047de90();
              }
              FUN_00471750();
              if (DAT_004e8984 != '\0') {
                FUN_0042c770((byte *)"DEMO LUCKY LUKE");
              }
              FUN_004437e0(0);
              if ((DAT_004e85b4 != '\0') || (DAT_004e8594 != 0)) {
                (*DAT_004e8a28)();
                local_118 = __chkesp();
                if (local_118 != 0) {
                  local_220 = DAT_004d1de4;
                  DAT_004d1de4 = DAT_004d1de4 + 1;
                  FUN_00497080(local_218,0x4b3f3c);
                  FUN_004266d0(local_218,local_118,DAT_004be3c8,DAT_004be3cc,'\x01');
                }
                DAT_004e85b4 = '\0';
              }
              uVar4 = FUN_00471e70();
              (*DAT_004e8a2c)(10,0x14,"FPS: %d",uVar4);
              __chkesp();
              (*DAT_004e8a2c)(10,0x1e,"gb_dead_lucky = %d",DAT_004e866c);
              __chkesp();
              (*DAT_004e8a2c)(10,0x5a,"CurrentLevel = %d",DAT_004e85b8);
              __chkesp();
              if (DAT_004e8988 != 0) {
                FUN_00477950();
              }
            }
            (*DAT_004e8a2c)(10,100,"ProgramLoadCount = %d",DAT_004d1de0);
            __chkesp();
            (*DAT_004e8a14)();
            __chkesp();
            FUN_00478450();
            if (DAT_004bcfe8 != '\0') {
              (*DAT_004e8a0c)();
              __chkesp();
            }
            FUN_0047d870();
            DAT_004e85b0 = DAT_004e85b0 + 1;
            if ((DAT_004d1d70 == '\0') && (DAT_004f2e0c != '\0')) {
              DAT_004d1d70 = '\x01';
              FUN_0041f830('\0');
            }
            DAT_004e8720 = 0;
            FUN_00471aa0();
          }
          FUN_0042fa90();
          DAT_004e8581 = 0;
          if ((DAT_004e8584 != 0) && (DAT_004e8974 == '\x01')) {
            puVar5 = (uint *)FUN_00474f00(DAT_004e8914);
            FUN_00472b60(puVar5);
          }
          while (DAT_004bd044 == '\0') {
            FUN_0046dc30();
          }
          FUN_0046db60(local_114);
          FUN_004784d0();
          FUN_004060d0(DAT_004d1d88);
        } while (DAT_004f1e20 == '\0');
        FUN_00405240();
        FUN_004450f0();
        FUN_004289a0();
        if (DAT_004e8590 == 0) {
          while (iVar6 = local_10c + -1, bVar8 = local_10c != 0, local_10c = iVar6, bVar8) {
            ShowCursor(1);
            __chkesp();
          }
        }
        AVIFileExit();
        FUN_00420910(&DAT_004d2890);
        FUN_00427980();
        ReleaseMutex(DAT_004d1ddc);
        __chkesp();
      }
    }
  }
  uStack_8 = 0x406f53;
  __chkesp();
  return;
}

