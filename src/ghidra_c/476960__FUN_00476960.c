/* FUN_00476960 @ 00476960 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00476960(void)

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
  FUN_00458ec0();
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    FUN_0047f190(*(byte **)(&DAT_004f13c4 + local_8 * 0x2c));
    FUN_00439c30(*(PVOID *)(&DAT_004f13c4 + local_8 * 0x2c));
    *(undefined4 *)(&DAT_004f13c4 + local_8 * 0x2c) = 0;
    FUN_0047f190(*(byte **)(&DAT_004f13c0 + local_8 * 0x2c));
    FUN_00439c30(*(PVOID *)(&DAT_004f13c4 + local_8 * 0x2c));
    *(undefined4 *)(&DAT_004f13c0 + local_8 * 0x2c) = 0;
  }
  local_8 = 0x476a23;
  __chkesp();
  return;
}

