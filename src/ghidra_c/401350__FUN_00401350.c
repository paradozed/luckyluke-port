/* FUN_00401350 @ 00401350 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00401350(int param_1)

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
  local_8 = param_1;
  while ((local_c & 0xffff) < (uint)*(ushort *)(local_8 + 0xffc)) {
    if (*(int *)(local_8 + 0x198 + (local_c & 0xffff) * 0x8c) == 0x73647561) {
      FUN_00495280(*(void **)(local_8 + 0xca0 + (local_c & 0xffff) * 0x2c));
      FUN_00458ec0();
    }
    else if (*(int *)(local_8 + 0x198 + (local_c & 0xffff) * 0x8c) == 0x73646976) {
      AVIStreamGetFrameClose(*(undefined4 *)(local_8 + 0x148 + (local_c & 0xffff) * 4));
      FUN_00458ec0();
    }
    AVIStreamRelease(*(undefined4 *)(local_8 + (local_c & 0xffff) * 4));
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  if (DAT_004bc058 != 0) {
    FUN_00425cd0((char *)(local_8 + 0xe8));
  }
  FUN_00458ec0();
  AVIFileRelease(*(undefined4 *)(local_8 + 0xff8));
  if (*(int *)(local_8 + 0xe4) != 0) {
    FUN_00495280(*(void **)(local_8 + 0xe4));
  }
  FUN_00458ec0();
  local_c = 0x4014bb;
  __chkesp();
  return;
}

