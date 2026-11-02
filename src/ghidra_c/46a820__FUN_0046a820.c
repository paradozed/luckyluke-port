/* FUN_0046a820 @ 0046a820 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046a820(void)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = *(short *)(DAT_004f2458 + 0xa6);
  local_8 = CONCAT22(local_8._2_2_,sVar1);
  if (sVar1 < 0x5c) {
    if (sVar1 < -0x5b) {
      DAT_004f2400 = FUN_0046a9c0;
    }
    else if ((DAT_004f2438 & 0x4000) == 0) {
      FUN_0046a6e0((int *)(DAT_004f2458 + 0xac),(int *)(DAT_004f2458 + 0xb0),(int *)&DAT_004be088);
    }
    else {
      FUN_0046a6e0((int *)(DAT_004f2458 + 0xac),(int *)(DAT_004f2458 + 0xb0),(int *)&DAT_004be090);
    }
  }
  else {
    DAT_004f2400 = FUN_0046aa90;
  }
  local_8 = 0x46a8e0;
  __chkesp();
  return;
}

