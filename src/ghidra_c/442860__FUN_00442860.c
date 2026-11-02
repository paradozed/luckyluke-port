/* FUN_00442860 @ 00442860 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442860(LPCSTR param_1,LPBYTE param_2)

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
  local_10[1] = 4;
  local_10[0] = 4;
  RegQueryValueExA(DAT_004e855c,param_1,(LPDWORD)0x0,local_10,param_2,local_10 + 1);
  __chkesp();
  local_10[2] = 0x4428cd;
  __chkesp();
  return;
}

