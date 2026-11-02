/* FUN_00433fa0 @ 00433fa0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00433fa0(LPBYTE param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  DWORD local_10 [3];
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10[1] = 0x100;
  local_10[0] = 1;
  RegOpenKeyExA((HKEY)0x80000002,"Software",0,0x20019,&DAT_004e8494);
  local_10[2] = __chkesp();
  if (local_10[2] == 0) {
    RegOpenKeyExA(DAT_004e8494,"Microsoft",0,0x20019,&DAT_004e8498);
    local_10[2] = __chkesp();
    if (local_10[2] == 0) {
      RegOpenKeyExA(DAT_004e8498,"Windows",0,0x20019,&DAT_004e849c);
      local_10[2] = __chkesp();
      if (local_10[2] == 0) {
        RegOpenKeyExA(DAT_004e849c,"CurrentVersion",0,0x20019,&DAT_004e84a0);
        local_10[2] = __chkesp();
        if (local_10[2] == 0) {
          RegOpenKeyExA(DAT_004e84a0,"Uninstall",0,0x20019,&DAT_004e84a4);
          local_10[2] = __chkesp();
          if (local_10[2] == 0) {
            RegOpenKeyExA(DAT_004e84a4,"Lucky Luke On The Daltons Trail",0,0x20019,&DAT_004e84a8);
            local_10[2] = __chkesp();
            if (local_10[2] == 0) {
              RegQueryValueExA(DAT_004e84a8,"UninstallString",(LPDWORD)0x0,local_10,param_1,
                               local_10 + 1);
              local_10[2] = __chkesp();
              if (local_10[2] == 0) {
                RegCloseKey(DAT_004e84a8);
                __chkesp();
                RegCloseKey(DAT_004e84a4);
                __chkesp();
                RegCloseKey(DAT_004e84a0);
                __chkesp();
                RegCloseKey(DAT_004e849c);
                __chkesp();
                RegCloseKey(DAT_004e8498);
                __chkesp();
                RegCloseKey(DAT_004e8494);
                __chkesp();
              }
            }
          }
        }
      }
    }
  }
  local_10[2] = 0x4341de;
  __chkesp();
  return;
}

