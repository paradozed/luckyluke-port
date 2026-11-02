/* FUN_004630b0 @ 004630b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004630b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_004634d0();
  FUN_00466510((ushort)local_8,FUN_00465a40);
  DAT_004f2c6e = 0xff;
  if (local_8 == 2) {
    DAT_004f23f8 = FUN_004631a0;
    FUN_004631a0();
  }
  else {
    DAT_004f23f8 = FUN_00463310;
    FUN_00463310();
  }
  local_8 = 0x46311c;
  __chkesp();
  return;
}

