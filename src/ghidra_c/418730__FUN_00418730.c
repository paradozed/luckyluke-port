/* FUN_00418730 @ 00418730 */
/* decompiled from Lucky.exe (Game.run) */


uint FUN_00418730(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_58 [16];
  uint local_18;
  int local_14;
  int local_10;
  
  puVar4 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (DAT_004bc4e8 < 0) {
    local_10 = -(int)DAT_004bc4e8;
  }
  else {
    local_10 = (int)DAT_004bc4e8;
  }
  uVar3 = DAT_004bd69c % 100;
  if (DAT_004bc4ea < 0) {
    local_14 = -(int)DAT_004bc4ea;
  }
  else {
    local_14 = (int)DAT_004bc4ea;
  }
  DAT_005081a1 = 0xffff < (uVar3 / 10 + 1) * local_14 ||
                 0xffff < (DAT_004bd69c / 100 + 1) * local_10;
  uVar1 = uVar3 / 10;
  if (DAT_004bc4ec < 0) {
    local_18 = -(int)DAT_004bc4ec;
  }
  else {
    uVar1 = (uint)DAT_004bc4ec;
    local_18 = uVar1;
  }
  if (0xffff < (uVar3 % 10 + 1) * local_18) {
    DAT_005081a1 = true;
  }
  return uVar1;
}

