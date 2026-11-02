/* FUN_004451b0 @ 004451b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004451b0(void)

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
  if (DAT_004e85bc != (void *)0xdddddddd) {
    FUN_00495280(DAT_004e85bc);
  }
  if (DAT_004e85c0 != (void *)0xdddddddd) {
    FUN_00495280(DAT_004e85c0);
  }
  if (DAT_004e85c4 != (void *)0xdddddddd) {
    FUN_00495280(DAT_004e85c4);
  }
  DAT_004e85bc = (void *)0x0;
  DAT_004e85c0 = (void *)0x0;
  DAT_004e85c4 = (void *)0x0;
  if (DAT_004f555c != (int *)0x0) {
    FUN_0046e5d0(DAT_004f555c);
    DAT_004f555c = (int *)0x0;
  }
  FUN_004399f0(DAT_004e85e8);
  FUN_004399f0(DAT_004e85ec);
  DAT_004e85e8 = (undefined4 *)FUN_00439930(0x400000);
  DAT_004e85ec = (undefined4 *)FUN_00439930(0x19000);
  FUN_00439c90(DAT_004e85e8);
  for (local_8 = 0; local_8 < 0xfa; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004f1e40 + local_8 * 4) = 0;
  }
  local_8 = 0x4452df;
  __chkesp();
  return;
}

