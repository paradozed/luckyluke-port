/* FUN_004018c0 @ 004018c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004018c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = local_c & 0xffff0000;
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  while (iVar1 = AVIFileGetStream(*(undefined4 *)(local_8 + 0xff8),local_8 + (local_c & 0xffff) * 4,
                                  0,local_c & 0xffff), iVar1 == 0) {
    AVIStreamInfoA(*(undefined4 *)(local_8 + (local_c & 0xffff) * 4),
                   local_8 + 0x198 + (local_c & 0xffff) * 0x8c,0x8c);
    AVIStreamLength(*(undefined4 *)(local_8 + (local_c & 0xffff) * 4));
    FUN_00458ec0();
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  *(short *)(local_8 + 0xffc) = (short)local_c;
  FUN_00458ec0();
  FUN_00458ec0();
  local_8 = 0x4019fd;
  __chkesp();
  return;
}

