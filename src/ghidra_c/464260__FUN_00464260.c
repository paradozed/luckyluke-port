/* FUN_00464260 @ 00464260 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00464260(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 *puVar5;
  undefined4 local_58 [16];
  undefined2 local_18;
  ushort local_14;
  undefined1 local_10;
  undefined3 uStack_f;
  ushort local_c [2];
  uint local_8;
  
  puVar5 = local_58;
  for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  FUN_00465630((undefined2 *)&local_8,local_c);
  uVar2 = FUN_0044ce10(CONCAT22(extraout_var,(undefined2)local_8));
  _local_10 = CONCAT31(uStack_f,(char)uVar2);
  if (((uVar2 & 0xff) != (uint)DAT_004f2c6e) && ((uVar2 & 0xff) == 1)) {
    uVar3 = FUN_0041f260((uint)local_c[0],local_8 & 0xffff);
    local_14 = (ushort)uVar3;
    uVar3 = FUN_0041f460(CONCAT22((short)((uint)uVar3 >> 0x10),local_c[0]),
                         CONCAT22(extraout_var_00,(undefined2)local_8));
    local_18 = (undefined2)uVar3;
    FUN_0041f5e0(CONCAT22((short)((uint)uVar3 >> 0x10),(undefined2)local_8),4,300,local_14,local_18,
                 '\0');
  }
  DAT_004f2c6e = local_10;
  cVar1 = FUN_00461250();
  if ((((cVar1 == '\0') && (1 < *(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32))) &&
      (*(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32) < 5)) && (DAT_004e880d == '\0')) {
    DAT_004e880d = '\x01';
    DAT_004e8810 = 0;
    *(short *)(DAT_004f25ac + 0xe) = *(short *)(DAT_004f25ac + 0xe) + 1;
    if (DAT_004e880e == '\0') {
      cVar1 = FUN_00464bf0(2);
      if (cVar1 == '\0') {
        DAT_004f2598 = FUN_0045ff60;
        FUN_0045ff60();
      }
      else if (*(ushort *)(DAT_004f25ac + 0x10) < *(ushort *)(DAT_004f25ac + 0xe)) {
        *(undefined2 *)(DAT_004f25ac + 0xe) = 0;
        uVar2 = FUN_0046d700();
        *(short *)(DAT_004f25ac + 0x10) = (short)((ulonglong)(uVar2 & 0xffff) % 5);
        DAT_004f2598 = FUN_00460fd0;
        FUN_00460fd0();
      }
      else {
        DAT_004f2598 = FUN_00460670;
        FUN_00460670();
      }
    }
  }
  local_8 = 0x464444;
  __chkesp();
  return;
}

