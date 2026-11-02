/* FUN_004ae2ce @ 004ae2ce */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ae2ce(void)

{
  int local_8;
  
  _DAT_0050a300 = FUN_004af110;
  _DAT_0050a304 = FUN_004af550;
  _DAT_0050a308 = FUN_004af480;
  _DAT_0050a30c = FUN_004af295;
  _DAT_0050a310 = FUN_004af2dc;
  _DAT_0050a314 = FUN_004ae2b0;
  _DAT_0050a318 = FUN_004af32c;
  _DAT_0050a31c = FUN_004af420;
  for (local_8 = 10; local_8 < 0x100; local_8 = local_8 + 1) {
    *(code **)(&DAT_0050a300 + local_8 * 4) = FUN_004ae2b0;
  }
  return;
}

