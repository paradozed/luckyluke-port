/* FUN_00468aa0 @ 00468aa0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00468aa0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_0046a6e0((int *)&DAT_004e8830,(int *)&DAT_004e882c,(int *)&DAT_004bdf60);
  DAT_004e8828 = DAT_004e8828 + _DAT_004e882c;
  FUN_00467440(*DAT_004f2458,0,(ushort)DAT_004e8828 & 0xfff,0);
  FUN_0046a6e0(DAT_004f2458 + 0x2d,DAT_004f2458 + 0x2e,(int *)&DAT_004bdf50);
  local_14 = *(undefined4 *)(*DAT_004f2458 + 0x90);
  local_c = *(undefined4 *)(*DAT_004f2458 + 0x98);
  local_10 = *(int *)(*DAT_004f2458 + 0x94) + DAT_004f2458[0x2e];
  FUN_00467730(*DAT_004f2458,local_14,local_10,local_c);
  if ((DAT_004f2458[4] & 0x20U) != 0) {
    DAT_004f2458[0x2d] = 0;
    DAT_004f23f8 = FUN_00466900;
    FUN_00466900();
  }
  uStack_8 = 0x468bc1;
  __chkesp();
  return;
}

