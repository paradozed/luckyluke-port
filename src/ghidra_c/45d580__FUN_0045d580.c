/* FUN_0045d580 @ 0045d580 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045d580(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_14c [16];
  uint local_10c;
  undefined1 local_108 [256];
  undefined4 local_8;
  
  puVar2 = local_14c;
  for (iVar1 = 0x52; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  local_10c = param_1 & 0xffff;
  if (local_10c == 0) {
    DAT_004e8738 = DAT_004e8914;
    FUN_00497080(local_108,0x4b8034);
    FUN_004266b0();
  }
  else if (local_10c == 1) {
    if (((DAT_004f2750 & 0x80) != 0) && (DAT_004e8738 != 0)) {
      DAT_004e8738 = DAT_004e8738 - 1;
    }
    if (((DAT_004f2750 & 0x20) != 0) &&
       ((&PTR_s__Cinema_Option_Option_004bcddc)[DAT_004e8738] != (undefined *)0x0)) {
      DAT_004e8738 = DAT_004e8738 + 1;
    }
    FUN_00497080(local_108,0x4b8034);
    FUN_004266b0();
  }
  else if (local_10c == 2) {
    DAT_004e8914 = DAT_004e8738;
    DAT_004f1e21 = 1;
    DAT_004e8706 = 0;
  }
  else {
    FUN_00497610((byte *)"Error: File %s, Line %d");
  }
  local_8 = 0x45d741;
  __chkesp();
  return;
}

