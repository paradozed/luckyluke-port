/* FUN_004038b0 @ 004038b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004038b0(short param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined1 local_10 [4];
  uint local_c;
  int local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((((DAT_004d1d64 != 0) && (0 < param_1)) && (param_1 <= DAT_004d1cdc)) && (DAT_004d1d68 != 0))
  {
    local_8 = DAT_004d1d68 + -6 + param_1 * 8;
    DAT_004d1cc0 = (uint)*(uint3 *)(local_8 + 2);
    DAT_004d1cd8 = (uint)*(uint3 *)(local_8 + 5);
    local_c = DAT_004d1cc0;
    mciSendCommandA(DAT_004d1d60,0x807,10,(DWORD_PTR)local_10);
    __chkesp();
  }
  local_8 = 0x4039ac;
  __chkesp();
  return;
}

