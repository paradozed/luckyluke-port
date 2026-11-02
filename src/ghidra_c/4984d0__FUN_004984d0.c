/* FUN_004984d0 @ 004984d0 */
/* decompiled from Lucky.exe (Game.run) */


uint * __cdecl FUN_004984d0(uint param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  uint local_11c;
  uint local_118 [65];
  DWORD local_14;
  char local_10 [4];
  LPSTR local_c;
  uint *local_8;
  
  if (param_1 == 0) {
    local_14 = GetCurrentDirectoryA(0x104,(LPSTR)local_118);
  }
  else {
    iVar1 = __validdrive(param_1);
    if (iVar1 == 0) {
      DAT_004e8c64 = 0xd;
      DAT_004e8c68 = 0xf;
      return (uint *)0x0;
    }
    local_10[0] = (char)param_1 + '@';
    local_10[1] = 0x3a;
    local_10[2] = 0x2e;
    local_10[3] = 0;
    local_14 = GetFullPathNameA(local_10,0x104,(LPSTR)local_118,&local_c);
  }
  if ((local_14 == 0) || (local_14 = local_14 + 1, 0x104 < local_14)) {
    puVar2 = (uint *)0x0;
  }
  else {
    local_8 = param_2;
    if (param_2 == (uint *)0x0) {
      local_11c = local_14;
      if ((int)local_14 <= (int)param_3) {
        local_11c = param_3;
      }
      local_8 = (uint *)FUN_00494840(local_11c);
      if (local_8 == (uint *)0x0) {
        DAT_004e8c64 = 0xc;
        return (uint *)0x0;
      }
    }
    else if ((int)param_3 < (int)local_14) {
      DAT_004e8c64 = 0x22;
      return (uint *)0x0;
    }
    puVar2 = FUN_00497270(local_8,local_118);
  }
  return puVar2;
}

