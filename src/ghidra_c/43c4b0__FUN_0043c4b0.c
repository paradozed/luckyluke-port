/* FUN_0043c4b0 @ 0043c4b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043c4b0(float param_1,float param_2,float param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined4 *local_10;
  int local_c;
  int *local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (int *)FUN_0043c330();
  if (local_8 != (int *)0x0) {
    iVar1 = FUN_0043c390(local_8,8);
    if (iVar1 == 0) {
      FUN_0043c230(local_8);
    }
    else {
      iVar1 = FUN_0043c440((int)local_8,6);
      if (iVar1 == 0) {
        FUN_0043c230(local_8);
      }
      else {
        for (local_c = 0; local_c < 8; local_c = local_c + 1) {
          iVar1 = local_c * 0xc;
          puVar2 = (undefined4 *)(local_8[4] + local_c * 0xc);
          *puVar2 = *(undefined4 *)(&DAT_004bccf0 + iVar1);
          puVar2[1] = *(undefined4 *)(&DAT_004bccf4 + iVar1);
          puVar2[2] = *(undefined4 *)(&DAT_004bccf8 + iVar1);
        }
        for (local_c = 0; local_c < 6; local_c = local_c + 1) {
          local_10 = (undefined4 *)(local_8[5] + local_c * 0x54);
          local_10[7] = *(undefined4 *)(&DAT_004bcd50 + local_c * 0x10);
          local_10[8] = *(undefined4 *)(&DAT_004bcd54 + local_c * 0x10);
          local_10[9] = *(undefined4 *)(&DAT_004bcd58 + local_c * 0x10);
          local_10[10] = *(undefined4 *)(&DAT_004bcd5c + local_c * 0x10);
          local_10[0xb] = 0xff;
          local_10[0xc] = 0xff;
          local_10[0xd] = 0xff;
          *local_10 = 1;
        }
        FUN_0043a7d0(local_8,param_1,param_2,param_3);
        FUN_00439d40(local_8 + 6);
      }
    }
  }
  local_8 = (int *)0x43c643;
  __chkesp();
  return;
}

