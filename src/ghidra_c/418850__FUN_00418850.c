/* FUN_00418850 @ 00418850 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00418850(void)

{
  ulonglong uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  DAT_004be2f0 = DAT_004bd69c / 100;
  uVar1 = ((ulonglong)DAT_004bd69c % 100) / 10;
  DAT_004be2f4 = (int)uVar1;
  DAT_004be2f8 = DAT_004bd69c % 10;
  _DAT_004e89fc = (short)(DAT_004bd69c / 100) * (short)uVar1 * (short)(DAT_004bd69c % 10);
  return DAT_004bd69c / 10;
}

