/* FUN_0047d110 @ 0047d110 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047d110(int param_1,int param_2)

{
  char cVar1;
  HWND pHVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  LPCSTR pCVar8;
  uint uVar9;
  LPCSTR pCVar10;
  UINT UVar11;
  undefined4 local_27c [16];
  char *local_23c;
  uint local_238 [64];
  char local_138 [292];
  short local_14 [8];
  
  puVar6 = local_27c;
  for (iVar5 = 0x9e; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  local_14[4] = 0;
  local_14[5] = 0;
  local_14[6] = 0;
  local_14[7] = 0;
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  local_14[3] = 0;
  if (param_1 != 0) {
    FUN_004984b0(local_238,0x100);
    FUN_00458ec0();
    local_23c = _strrchr((char *)local_238,0x5c);
    if (local_23c[1] == '\0') {
      *local_23c = '\0';
    }
    FUN_00458ec0();
    FUN_00497280(local_238,(uint *)&DAT_004b52ac);
    FUN_00458ec0();
    FUN_0047b0b0(local_238);
    FUN_00458ec0();
    cVar1 = FUN_0047b0f0((uint *)(param_1 + 4));
    if (cVar1 == '\0') {
      UVar11 = 0;
      pCVar8 = DAT_004f5df4;
      pCVar10 = DAT_004f5dd4;
      pHVar2 = (HWND)FUN_00445810();
      MessageBoxA(pHVar2,pCVar8,pCVar10,UVar11);
      __chkesp();
      FUN_0047ba60();
    }
    else {
      FUN_00458ec0();
      (*DAT_004e8a08)(local_138);
      __chkesp();
      FUN_00458ec0();
      FUN_00458ec0();
      FUN_00458ec0();
      iVar5 = _strcmp(local_138,"Win3DX Software");
      if ((iVar5 == 0) && (param_2 != 0)) {
        DAT_004be3c8 = 0x140;
        DAT_004be3cc = 200;
      }
      iVar5 = _strcmp(local_138,"Win3DX Software");
      if (((iVar5 == 0) && (param_2 == 0)) && (*(short *)(param_1 + 0x24) == 0)) {
        DAT_004be3c8 = 0x280;
        DAT_004be3cc = 0xf0;
        (*DAT_005089fc)();
        __chkesp();
      }
      (*DAT_004e8a1c)(FUN_00458ec0);
      __chkesp();
      uVar7 = DAT_004be3c8;
      uVar9 = DAT_004be3cc;
      uVar3 = FUN_00445840();
      uVar4 = FUN_00445810();
      (*DAT_004e8a18)(uVar4,uVar3,uVar7,uVar9,param_1);
      uVar3 = __chkesp();
      if ((char)uVar3 == '\0') {
        (*DAT_00508984)();
        DAT_004e8a88 = __chkesp();
        if (DAT_004e8a88 == 0) {
          UVar11 = 0;
          pCVar8 = DAT_004f5df0;
          pCVar10 = DAT_004f5dd4;
          pHVar2 = (HWND)FUN_00445810();
          MessageBoxA(pHVar2,pCVar8,pCVar10,UVar11);
          __chkesp();
        }
        (*DAT_004e8a20)();
        __chkesp();
        FUN_0047ba60();
      }
      else {
        FUN_00458ec0();
        FUN_00458ec0();
        FUN_00487fc0();
        FUN_0047bfd0();
        FUN_0047ce30();
        FUN_0047c4e0((short)(DAT_004be3c8 >> 1),(short)(DAT_004be3cc >> 1),0x200);
        FUN_0047c9c0(local_14 + 4,local_14,6000);
        DAT_004e8ad8 = 0;
      }
    }
  }
  local_14[6] = -0x2b7d;
  local_14[7] = 0x47;
  __chkesp();
  return;
}

