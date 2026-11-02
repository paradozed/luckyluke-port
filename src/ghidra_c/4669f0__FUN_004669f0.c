/* FUN_004669f0 @ 004669f0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004669f0(void)

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
  FUN_00466510(0,FUN_00465a40);
  FUN_0047fbe0(*DAT_004f2458,&DAT_004f2440);
  _DAT_004f23e0 = DAT_004f2440;
  _DAT_004f23e4 = DAT_004f2444 + 800;
  _DAT_004f23e8 = DAT_004f2448;
  _DAT_004f23ec = DAT_004f244c;
  _DAT_004f23f0 = DAT_004f2450;
  _DAT_004f23f4 = DAT_004f2454;
  _DAT_004f2420 = DAT_004f2440;
  _DAT_004f2424 = DAT_004f2444 + 300;
  _DAT_004f2428 = DAT_004f2448;
  _DAT_004f242c = DAT_004f244c;
  _DAT_004f2430 = DAT_004f2450 + -400;
  _DAT_004f2434 = DAT_004f2454;
  DAT_004f23f8 = FUN_00466900;
  FUN_00466900();
  DAT_004e8580 = 0;
  uStack_8 = 0x466ae6;
  __chkesp();
  return;
}

