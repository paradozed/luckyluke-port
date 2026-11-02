/* FUN_00426fd0 @ 00426fd0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426fd0(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_44 [16];
  
  puVar8 = local_44;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0xcccccccc;
    puVar8 = puVar8 + 1;
  }
  uVar1 = ((longlong)DAT_004be3c8 * 0x32 & 0xffffffffU) / 0x280;
  DAT_004d28bc = (int)uVar1;
  uVar2 = ((longlong)DAT_004be3cc * 0x1ae & 0xffffffffU) / 0x1e0;
  DAT_004d28b8 = (int)uVar2;
  DAT_004d291c = (int)(((longlong)DAT_004be3c8 * 0x50 & 0xffffffffU) / 0x280);
  DAT_004d2918 = (int)(((longlong)DAT_004be3cc * 0x50 & 0xffffffffU) / 0x1e0);
  sVar4 = (short)(DAT_004d291c >> 1);
  sVar3 = (short)uVar1;
  _DAT_004d28f8 = sVar3 - sVar4;
  sVar6 = (short)(DAT_004d2918 >> 1);
  sVar5 = (short)uVar2;
  _DAT_004d28fa = sVar5 - sVar6;
  _DAT_004d2900 = sVar3 + sVar4;
  _DAT_004d2902 = sVar5 - sVar6;
  _DAT_004d2908 = sVar3 - sVar4;
  _DAT_004d290a = sVar5 + sVar6;
  _DAT_004d2910 = sVar3 + sVar4;
  _DAT_004d2912 = sVar5 + sVar6;
  return;
}

