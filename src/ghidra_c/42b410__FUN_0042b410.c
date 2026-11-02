/* FUN_0042b410 @ 0042b410 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042b410(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_150 [16];
  undefined1 local_110;
  char *local_10c;
  undefined4 uStack_8;
  
  puVar2 = local_150;
  for (iVar1 = 0x53; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_110 = 1;
  FUN_00458ec0();
  FUN_004984b0((uint *)&DAT_004e56d0,0x104);
  local_10c = _strrchr(&DAT_004e56d0,0x5c);
  if (local_10c[1] == '\0') {
    *local_10c = '\0';
  }
  FUN_00497280((uint *)&DAT_004e56d0,(uint *)&DAT_004b52ac);
  FUN_00429ee0();
  FUN_00458ec0();
  FUN_004289e0();
  FUN_00458ec0();
  FUN_00429040();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  local_110 = FUN_00434fa0();
  if ((DAT_004f58a8 != (int *)0x0) && (*DAT_004f58a8 == 0x57696e64)) {
    DAT_004e8590 = 1;
    FUN_0042b270();
  }
  uStack_8 = 0x42b536;
  __chkesp();
  return;
}

