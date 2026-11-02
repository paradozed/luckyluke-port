/* FUN_004689f0 @ 004689f0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004689f0(void)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  _DAT_004e882c = 0;
  DAT_004f2400 = FUN_00466290;
  DAT_004f2458[4] = DAT_004f2458[4] | 0x40;
  sVar1 = FUN_00467130(*DAT_004f2458);
  DAT_004e8828 = (int)sVar1;
  FUN_00466510(0x18,FUN_004688b0);
  DAT_004f23f8 = FUN_004688d0;
  FUN_004688d0();
  uStack_8 = 0x468a74;
  __chkesp();
  return;
}

