/* FUN_0045d460 @ 0045d460 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045d460(uint param_1,int param_2)

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
    if (local_c != 1) {
      if (local_c == 2) {
        DAT_004be2e8 = 0x1f;
      }
      else {
        FUN_00497610((byte *)"Error: File %s, Line %d");
      }
      goto LAB_0045d560;
    }
    if (((DAT_004f2744 & 0x80) != 0) && (DAT_004be2e8 != 0)) {
      DAT_004be2e8 = DAT_004be2e8 - 1;
    }
    if (((DAT_004f2744 & 0x20) != 0) && (DAT_004be2e8 < 200)) {
      DAT_004be2e8 = DAT_004be2e8 + 1;
    }
  }
  FUN_004594c0();
LAB_0045d560:
  local_8 = 0x45d56d;
  __chkesp();
  return;
}

