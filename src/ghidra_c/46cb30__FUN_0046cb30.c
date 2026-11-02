/* FUN_0046cb30 @ 0046cb30 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046cb30(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004f2438 & 0x80) == 0) {
    if ((DAT_004f2438 & 0x20) == 0) {
      local_8 = CONCAT22(local_8._2_2_,1);
    }
    else {
      local_8 = (uint)local_8._2_2_ << 0x10;
    }
  }
  else {
    local_8 = CONCAT22(local_8._2_2_,2);
  }
  DAT_004f5556 = 1;
  FUN_0046c7b0(*(short *)(&DAT_004be0f0 + (short)local_8 * 4),FUN_0046ca70);
  DAT_004f5558 = *(undefined2 *)((short)local_8 * 4 + 0x4be0f2);
  local_8 = 0x46cbc0;
  __chkesp();
  return;
}

