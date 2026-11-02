/* FUN_0042b340 @ 0042b340 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042b340(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  while( true ) {
    if ((int)(uint)DAT_004e8300 <= local_8) {
      DAT_004f58a8 = (undefined *)0x0;
      return;
    }
    if (*(int *)(&DAT_004e2b70 + local_8 * 0x228) == 0x536f6674) break;
    local_8 = local_8 + 1;
  }
  DAT_004f58a8 = &DAT_004e2b70 + local_8 * 0x228;
  return;
}

