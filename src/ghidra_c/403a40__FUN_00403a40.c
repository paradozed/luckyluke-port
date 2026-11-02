/* FUN_00403a40 @ 00403a40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00403a40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  undefined1 local_10 [4];
  uint local_c;
  uint local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004d1d64 != 0) && (DAT_004d1d68 != 0)) {
    local_14 = DAT_004d1d68 + -6 + param_1 * 8;
    DAT_004d1cc0 = (uint)*(uint3 *)(local_14 + 2);
    DAT_004d1cd8 = (uint)*(uint3 *)(local_14 + 5);
    local_c = DAT_004d1cd8;
    local_8 = DAT_004d1cc0;
    mciSendCommandA(DAT_004d1d60,0x806,0xc,(DWORD_PTR)local_10);
    __chkesp();
  }
  local_8 = 0x403b24;
  __chkesp();
  return;
}

