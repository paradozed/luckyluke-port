/* FUN_0041e800 @ 0041e800 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0041e800(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar4 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (DAT_004bcfd0 != 0) {
    FUN_00458ec0();
    uVar1 = FUN_00445810();
    DAT_004d2884 = FUN_00403060(uVar1);
    FUN_00458ec0();
    local_8 = CONCAT22(local_8._2_2_,1);
    while( true ) {
      uVar3 = local_8 & 0xffff;
      uVar1 = FUN_004037c0();
      if ((short)uVar1 + 1 <= (int)uVar3) break;
      FUN_00403800((short)local_8,&DAT_004d1f28 + (local_8 & 0xffff) * 0x1c,
                   &DAT_004d1f2c + (local_8 & 0xffff) * 0x1c,
                   &DAT_004d1f30 + (local_8 & 0xffff) * 0x1c,
                   &DAT_004d1f34 + (local_8 & 0xffff) * 0x1c,
                   &DAT_004d1f38 + (local_8 & 0xffff) * 0x1c,
                   &DAT_004d1f3c + (local_8 & 0xffff) * 0x1c);
      local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
    }
    FUN_00420240(DAT_004f58a0);
  }
  local_8 = 0x41e91d;
  __chkesp();
  return;
}

