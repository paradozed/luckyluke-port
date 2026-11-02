/* FUN_0045ccb0 @ 0045ccb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045ccb0(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  local_c = param_1 & 0xffff;
  if (local_c != 0) {
    if ((local_c == 0) || (2 < local_c)) {
      FUN_00497610((byte *)"Error: File %s, Line %d");
      goto LAB_0045cdb4;
    }
    if (((DAT_004f2744 & 0x80) != 0) && (10 < DAT_004bdaac)) {
      DAT_004bdaac = DAT_004bdaac - 10;
    }
    if (((DAT_004f2744 & 0x20) != 0) && (DAT_004bdaac < 0x1000)) {
      DAT_004bdaac = DAT_004bdaac + 10;
    }
    FUN_004830a0(DAT_004bdaac);
    DAT_004bdab0 = (undefined4)(0x100000 / (ulonglong)DAT_004bdaac);
  }
  FUN_004594c0();
LAB_0045cdb4:
  local_8 = 0x45cdc1;
  __chkesp();
  return;
}

