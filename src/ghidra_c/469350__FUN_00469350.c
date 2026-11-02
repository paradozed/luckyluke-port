/* FUN_00469350 @ 00469350 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00469350(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [17];
  uint local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_00456150(DAT_004f2438);
  local_8 = CONCAT22(local_8._2_2_,(short)uVar1);
  DAT_004f13a4 = FUN_00467130(*DAT_004f2458);
  if (DAT_004f13a4 < 0x800) {
    DAT_004f1670 = *(undefined2 *)(&DAT_004bdfd8 + (local_8 & 0xffff) * 2);
  }
  else {
    DAT_004f1670 = *(undefined2 *)(&DAT_004be000 + (local_8 & 0xffff) * 2);
  }
  local_8 = 0x469406;
  __chkesp();
  return;
}

