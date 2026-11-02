/* FUN_004039b0 @ 004039b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004039b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  undefined4 local_14;
  undefined4 local_10 [2];
  undefined4 local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004d1d64 != 0) && (DAT_004d1d68 != 0)) {
    local_8 = DAT_004d1cd8;
    local_10[0] = DAT_004d1d6c;
    mciSendCommandA(DAT_004d1d60,0x806,0,(DWORD_PTR)local_10);
    local_14 = __chkesp();
  }
  local_8 = 0x403a32;
  __chkesp();
  return;
}

