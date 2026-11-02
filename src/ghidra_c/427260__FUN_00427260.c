/* FUN_00427260 @ 00427260 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00427260(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar6 = local_44;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  uVar1 = ((longlong)DAT_004be3c8 * 0x32 & 0xffffffffU) / 0x280;
  DAT_004d28b4 = (undefined4)uVar1;
  uVar2 = ((longlong)DAT_004be3cc * 0x1ae & 0xffffffffU) / 0x1e0;
  DAT_004d28b0 = (undefined4)uVar2;
  DAT_004d28ec = (int)(((longlong)DAT_004be3c8 * 0x3c & 0xffffffffU) / 0x280);
  DAT_004d28e8 = (int)(((longlong)DAT_004be3cc * 0x3c & 0xffffffffU) / 0x1e0);
  sVar3 = (short)(DAT_004d28ec >> 1);
  _DAT_004d28e0 = (short)uVar1;
  _DAT_004d28c8 = _DAT_004d28e0 - sVar3;
  sVar4 = (short)(DAT_004d28e8 >> 1);
  _DAT_004d28e2 = (short)uVar2;
  _DAT_004d28ca = _DAT_004d28e2 - sVar4;
  _DAT_004d28d0 = _DAT_004d28e0 + sVar3;
  _DAT_004d28d2 = _DAT_004d28e2 - sVar4;
  _DAT_004d28d8 = _DAT_004d28e0 - sVar3;
  _DAT_004d28da = _DAT_004d28e2 + sVar4;
  _DAT_004d28e0 = _DAT_004d28e0 + sVar3;
  _DAT_004d28e2 = _DAT_004d28e2 + sVar4;
  FUN_00427130((short *)&DAT_004d28c8,(short *)&DAT_004d28ca);
  FUN_00427130((short *)&DAT_004d28d0,(short *)&DAT_004d28d2);
  FUN_00427130((short *)&DAT_004d28d8,(short *)&DAT_004d28da);
  FUN_00427130((short *)&DAT_004d28e0,(short *)&DAT_004d28e2);
  uStack_8 = 0x42740d;
  __chkesp();
  return;
}

