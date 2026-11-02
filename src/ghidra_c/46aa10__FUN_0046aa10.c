/* FUN_0046aa10 @ 0046aa10 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046aa10(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(DAT_004f2458 + 0xa6));
  if (*(short *)(DAT_004f2458 + 0xa6) < 0x5b) {
    DAT_004f2400 = FUN_0046a8f0;
  }
  else {
    FUN_0046a6e0((int *)(DAT_004f2458 + 0xac),(int *)(DAT_004f2458 + 0xb0),(int *)&DAT_004be098);
  }
  local_8 = 0x46aa7f;
  __chkesp();
  return;
}

