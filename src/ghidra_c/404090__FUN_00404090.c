/* FUN_00404090 @ 00404090 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00404090(short param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [17];
  undefined1 local_14 [4];
  undefined1 local_10;
  undefined4 local_c;
  int local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (0 < DAT_004d1cdc) {
    local_c = 2;
    local_8 = (int)param_1;
    mciSendCommandA(DAT_004d1d60,0x814,0x110,(DWORD_PTR)local_14);
    iVar1 = __chkesp();
    if (iVar1 == 0) {
      *param_2 = local_10;
      *param_3 = (char)((uint)_local_10 >> 8);
      *param_4 = (char)((uint)_local_10 >> 0x10);
    }
  }
  local_8 = 0x404125;
  __chkesp();
  return;
}

