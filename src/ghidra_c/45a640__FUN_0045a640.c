/* FUN_0045a640 @ 0045a640 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045a640(uint param_1,int param_2)

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
  if (1 < local_c) {
    if (local_c == 2) {
      DAT_004bdb10 = DAT_004bdb10 ^ 1;
    }
    else {
      FUN_00497610((byte *)"Error: File %s, Line %d");
    }
  }
  FUN_00459540();
  FUN_00459540();
  FUN_00459540();
  local_8 = 0x45a718;
  __chkesp();
  return;
}

