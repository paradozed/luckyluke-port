/* FUN_00455bd0 @ 00455bd0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00455bd0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8644 = DAT_004f2bc2;
  DAT_004e864a = 1;
  DAT_004e864c = 11000;
  _DAT_004f2c3c = 1000;
  DAT_004e8650 = 0;
  DAT_004e8652 = 0;
  DAT_004e8658 = 0;
  DAT_004e8641 = 0;
  DAT_004e8640 = 1;
  DAT_004e8654 = 0;
  DAT_004e8646 = 0;
  DAT_004e8688 = 0x3c;
  DAT_004e868a = 100;
  DAT_004e868c = 0;
  DAT_004bd6a0 = 0;
  DAT_004bd6a4 = 0xfffff830;
  DAT_004bd6a8 = 6000;
  DAT_004bdaac = 400;
  DAT_004bdab0 = 0xa3d;
  FUN_004830a0(400);
  DAT_004bdaac = 400;
  PTR_FUN_004bd5d8 = FUN_004556d0;
  uStack_8 = 0x455ce4;
  __chkesp();
  return;
}

