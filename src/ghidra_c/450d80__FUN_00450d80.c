/* FUN_00450d80 @ 00450d80 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00450d80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_88 [16];
  short local_48 [4];
  int local_40;
  short local_3c [4];
  int local_34 [2];
  undefined2 local_2c;
  undefined4 local_24 [5];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = local_88;
  for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_3c[0] = 0;
  local_3c[1] = 0;
  local_3c[2] = 32000;
  local_3c[3] = 0;
  FUN_004835d0(&DAT_00508180,(undefined2 *)local_24);
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  FUN_00482820(local_24,local_3c,local_34);
  local_3c[0] = (short)local_34[0];
  local_3c[1] = 0;
  local_3c[2] = local_2c;
  FUN_004823a0((undefined4 *)&DAT_00508180);
  FUN_004824a0(0x4c63f8);
  FUN_0047c4e0(0x100,0x80,(short)DAT_004bdaac);
  FUN_00482e60(local_3c,local_48,&local_40);
  FUN_0047c4e0((short)(DAT_004be3c8 >> 1),(short)(DAT_004be3cc >> 1),(short)DAT_004bdaac);
  _DAT_004e867c = (int)local_48[0];
  DAT_004e8680 = (int)SUB42(local_48._0_4_,2);
  local_8 = 0x450e9b;
  __chkesp();
  return;
}

