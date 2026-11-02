/* FUN_0046b9c0 @ 0046b9c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046b9c0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_0046a6e0(DAT_004f2458 + 0x2d,DAT_004f2458 + 0x2e,(int *)&DAT_004be0a8);
  if ((uVar1 & 0xff) == 0) {
    local_14 = *(undefined4 *)(*DAT_004f2458 + 0x90);
    local_c = *(undefined4 *)(*DAT_004f2458 + 0x98);
    local_10 = *(int *)(*DAT_004f2458 + 0x94) - DAT_004f2458[0x2e];
    FUN_00467730(*DAT_004f2458,local_14,local_10,local_c);
  }
  else {
    DAT_004f23f8 = FUN_0046bcf0;
    FUN_0046bcf0();
  }
  uStack_8 = 0x46ba86;
  __chkesp();
  return;
}

