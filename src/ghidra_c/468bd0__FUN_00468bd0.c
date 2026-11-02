/* FUN_00468bd0 @ 00468bd0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00468bd0(void)

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
  _DAT_004e882c = 0;
  DAT_004f23f8 = FUN_00468aa0;
  FUN_00468aa0();
  uStack_8 = 0x468c0e;
  __chkesp();
  return;
}

