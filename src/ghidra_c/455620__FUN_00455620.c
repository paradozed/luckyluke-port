/* FUN_00455620 @ 00455620 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00455620(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004bdaac = DAT_004bdaac + (int)DAT_004e8648;
  if (DAT_004bdaac + (int)DAT_004e8648 < 0x118) {
    DAT_004e8648 = 8;
  }
  if (400 < DAT_004bdaac + (int)DAT_004e8648) {
    DAT_004e8642 = 0;
  }
  local_8 = DAT_004bdaac & 0xffffff;
  DAT_004bdab0 = (undefined4)(0x100000 / (ulonglong)local_8);
  FUN_004830a0(local_8);
  local_8 = 0x4556c5;
  __chkesp();
  return;
}

