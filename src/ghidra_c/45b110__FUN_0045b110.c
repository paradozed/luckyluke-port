/* FUN_0045b110 @ 0045b110 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045b110(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  byte local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  local_c = param_1 & 0xffff;
  if (local_c < 2) {
    local_10 = DAT_004e8702;
    if (DAT_004e8702 == 0) {
      FUN_004266b0();
    }
    else if (DAT_004e8702 == 1) {
      FUN_004266b0();
    }
    else if (DAT_004e8702 == 2) {
      FUN_004266b0();
    }
  }
  else if (local_c == 2) {
    DAT_004e8702 = (byte)((DAT_004e8702 + 1) % 3);
  }
  else {
    FUN_00497610((byte *)"Error: File %s, Line %d");
  }
  local_8 = 0x45b24b;
  __chkesp();
  return;
}

