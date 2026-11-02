/* FUN_0047b0f0 @ 0047b0f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047b0f0(uint *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_148 [16];
  uint local_108 [64];
  undefined4 uStack_8;
  
  puVar2 = local_148;
  for (iVar1 = 0x51; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8a04 == (HMODULE)0x0) {
    FUN_00497270(local_108,(uint *)&DAT_00508880);
    FUN_00497280(local_108,(uint *)"\\drivers\\");
    FUN_00497280(local_108,param_1);
    LoadLibraryA((LPCSTR)local_108);
    DAT_004e8a04 = (HMODULE)__chkesp();
    if (DAT_004e8a04 != (HMODULE)0x0) {
      GetProcAddress(DAT_004e8a04,"wxGetDriverInfo");
      DAT_004e8a08 = __chkesp();
      if (DAT_004e8a08 != 0) {
        GetProcAddress(DAT_004e8a04,"InitWin3DX");
        DAT_004e8a18 = __chkesp();
        if (DAT_004e8a18 != 0) {
          GetProcAddress(DAT_004e8a04,"RegisterWin3DXErrorFunc");
          DAT_004e8a1c = __chkesp();
          if (DAT_004e8a1c != 0) {
            GetProcAddress(DAT_004e8a04,"CloseWin3DX");
            DAT_004e8a20 = __chkesp();
            if (DAT_004e8a20 != 0) {
              GetProcAddress(DAT_004e8a04,"wxFlipScreen");
              DAT_004e8a0c = __chkesp();
              if (DAT_004e8a0c != 0) {
                GetProcAddress(DAT_004e8a04,"wxBeginFrame");
                DAT_004e8a10 = __chkesp();
                if (DAT_004e8a10 != 0) {
                  GetProcAddress(DAT_004e8a04,"wxEndFrame");
                  DAT_004e8a14 = __chkesp();
                  if (DAT_004e8a14 != 0) {
                    GetProcAddress(DAT_004e8a04,"wxUploadTexturePage");
                    DAT_004e8a24 = __chkesp();
                    if (DAT_004e8a24 != 0) {
                      GetProcAddress(DAT_004e8a04,"wxGetLFBImage");
                      DAT_004e8a28 = __chkesp();
                      if (DAT_004e8a28 != 0) {
                        GetProcAddress(DAT_004e8a04,"wxDrawString");
                        DAT_004e8a2c = __chkesp();
                        if (DAT_004e8a2c != 0) {
                          GetProcAddress(DAT_004e8a04,"wxIgnoreZClip");
                          DAT_004e8a30 = __chkesp();
                          if (DAT_004e8a30 != 0) {
                            GetProcAddress(DAT_004e8a04,"wxFlipWireFrame");
                            DAT_004e8a34 = __chkesp();
                            if (DAT_004e8a34 != 0) {
                              GetProcAddress(DAT_004e8a04,"wxDrawLine");
                              DAT_004e8a3c = __chkesp();
                              if (DAT_004e8a3c != 0) {
                                GetProcAddress(DAT_004e8a04,"wxDrawPrim_PF3");
                                DAT_004e8a40 = __chkesp();
                                if (DAT_004e8a40 != 0) {
                                  GetProcAddress(DAT_004e8a04,"wxDrawPrim_PF4");
                                  DAT_004e8a44 = __chkesp();
                                  if (DAT_004e8a44 != 0) {
                                    GetProcAddress(DAT_004e8a04,"wxDrawPrim_PG3");
                                    DAT_004e8a48 = __chkesp();
                                    if (DAT_004e8a48 != 0) {
                                      GetProcAddress(DAT_004e8a04,"wxDrawPrim_PG4");
                                      DAT_004e8a4c = __chkesp();
                                      if (DAT_004e8a4c != 0) {
                                        GetProcAddress(DAT_004e8a04,"wxDrawPrim_PFT3");
                                        DAT_004e8a50 = __chkesp();
                                        if (DAT_004e8a50 != 0) {
                                          GetProcAddress(DAT_004e8a04,"wxDrawPrim_PFT4");
                                          DAT_004e8a54 = __chkesp();
                                          if (DAT_004e8a54 != 0) {
                                            GetProcAddress(DAT_004e8a04,"wxDrawPrim_PGT3");
                                            DAT_004e8a58 = __chkesp();
                                            if (DAT_004e8a58 != 0) {
                                              GetProcAddress(DAT_004e8a04,"wxDrawPrim_PGT4");
                                              DAT_004e8a5c = __chkesp();
                                              if (DAT_004e8a5c != 0) {
                                                GetProcAddress(DAT_004e8a04,"wxDrawPrim_SPRT");
                                                DAT_004e8a60 = __chkesp();
                                                if (DAT_004e8a60 != 0) {
                                                  GetProcAddress(DAT_004e8a04,"wxDrawAlphaBox");
                                                  DAT_005089f8 = __chkesp();
                                                  if (DAT_005089f8 != 0) {
                                                    GetProcAddress(DAT_004e8a04,"wxDrawGradientBack"
                                                                  );
                                                    DAT_00508a00 = __chkesp();
                                                    if (DAT_00508a00 != 0) {
                                                      GetProcAddress(DAT_004e8a04,"wxDrawFade");
                                                      DAT_0050898c = __chkesp();
                                                      if (DAT_0050898c != 0) {
                                                        GetProcAddress(DAT_004e8a04,"wxSizeMoveMsg")
                                                        ;
                                                        DAT_004e8a64 = __chkesp();
                                                        if (DAT_004e8a64 != 0) {
                                                          GetProcAddress(DAT_004e8a04,"wxResize");
                                                          DAT_004e8a68 = __chkesp();
                                                          if (DAT_004e8a68 != 0) {
                                                            GetProcAddress(DAT_004e8a04,
                                                                           "wxSetTransValue");
                                                            DAT_004e8a6c = __chkesp();
                                                            if (DAT_004e8a6c != 0) {
                                                              GetProcAddress(DAT_004e8a04,
                                                                             "wxColourKeyOn");
                                                              DAT_004e8a70 = __chkesp();
                                                              if (DAT_004e8a70 != 0) {
                                                                GetProcAddress(DAT_004e8a04,
                                                                               "wxColourKeyOff");
                                                                DAT_004e8a74 = __chkesp();
                                                                if (DAT_004e8a74 != 0) {
                                                                  GetProcAddress(DAT_004e8a04,
                                                                                 "wxSetLFBImage");
                                                                  DAT_004e8a78 = __chkesp();
                                                                  if (DAT_004e8a78 != 0) {
                                                                    GetProcAddress(DAT_004e8a04,
                                                                                   "wxInFrame");
                                                                    DAT_004e8a7c = __chkesp();
                                                                    if (DAT_004e8a7c != 0) {
                                                                      GetProcAddress(DAT_004e8a04,
                                                                                                                                                                          
                                                  "wxApplyPalette");
                                                  DAT_004e8a80 = __chkesp();
                                                  if (DAT_004e8a80 != 0) {
                                                    GetProcAddress(DAT_004e8a04,"wxGetDesktopDepth")
                                                    ;
                                                    DAT_004e8a84 = __chkesp();
                                                    if (DAT_004e8a84 != 0) {
                                                      GetProcAddress(DAT_004e8a04,"wxSetPalReg");
                                                      DAT_005089ec = __chkesp();
                                                      if (DAT_005089ec != 0) {
                                                        GetProcAddress(DAT_004e8a04,
                                                                       "wxSetPalEntries");
                                                        DAT_005089e4 = __chkesp();
                                                        if (DAT_005089e4 != 0) {
                                                          GetProcAddress(DAT_004e8a04,
                                                                         "wxInterlaceOn");
                                                          DAT_005089fc = __chkesp();
                                                          if (DAT_005089fc != 0) {
                                                            GetProcAddress(DAT_004e8a04,"wxDrawLine"
                                                                          );
                                                            DAT_004e8a3c = __chkesp();
                                                            if (DAT_004e8a3c != 0) {
                                                              GetProcAddress(DAT_004e8a04,
                                                                             "wxSetBlitParameters");
                                                              DAT_00508a04 = __chkesp();
                                                              if (DAT_00508a04 != 0) {
                                                                GetProcAddress(DAT_004e8a04,
                                                                               "wxZBufferState");
                                                                DAT_00508864 = __chkesp();
                                                                if (DAT_00508864 != 0) {
                                                                  GetProcAddress(DAT_004e8a04,
                                                                                 "wxGetInstanceName"
                                                                                );
                                                                  DAT_004f778c = __chkesp();
                                                                  if (DAT_004f778c != 0) {
                                                                    GetProcAddress(DAT_004e8a04,
                                                                                   "wxSizeMsg");
                                                                    DAT_00508988 = __chkesp();
                                                                    if (DAT_00508988 != 0) {
                                                                      GetProcAddress(DAT_004e8a04,
                                                                                     "wxSizeOut");
                                                                      DAT_005089f0 = __chkesp();
                                                                      if (DAT_005089f0 != 0) {
                                                                        GetProcAddress(DAT_004e8a04,
                                                                                                                                                                              
                                                  "wxNCActivate");
                                                  DAT_005089e0 = __chkesp();
                                                  if (DAT_005089e0 != 0) {
                                                    GetProcAddress(DAT_004e8a04,"wxGetLastError");
                                                    DAT_00508984 = __chkesp();
                                                    if (DAT_00508984 != 0) {
                                                      GetProcAddress(DAT_004e8a04,"wxCullMode");
                                                      DAT_005089f4 = __chkesp();
                                                      if (DAT_005089f4 != 0) {
                                                        GetProcAddress(DAT_004e8a04,
                                                                       "wxSupportsTexModulation");
                                                        DAT_005089e8 = __chkesp();
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uStack_8 = 0x47ba4d;
  __chkesp();
  return;
}

