/* FUN_00443ab0 @ 00443ab0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00443ab0(void)

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
  for (local_8 = DAT_004e8578; local_8 != 0; local_8 = *(int *)(local_8 + 0x10)) {
    *(undefined4 *)(local_8 + 8) = 0;
    *(undefined4 *)(local_8 + 0xc) = 0;
  }
  return;
}

