/* FUN_0041a1b0 @ 0041a1b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041a1b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  PVOID local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(PVOID *)(param_1 + 8);
  FUN_00458ec0();
  if (DAT_004e85b8 == 0x12) {
    DAT_004be3bc = 0;
    FUN_00449670();
  }
  if (DAT_004e89f0 != (void *)0x0) {
    local_c = local_c & 0xffff0000;
    while ((local_c & 0xffff) < DAT_004e89fa + 1) {
      if ((DAT_004e85b8 != 0x12) &&
         ((*(char *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 2) == '\x01' ||
          (*(char *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 3) == '\x01')))) {
        FUN_004798a0(local_c & 0xffff);
      }
      *(undefined2 *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20) = 0;
      *(undefined4 *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 0x14) = 0;
      *(undefined1 *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 2) = 0;
      *(undefined1 *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 3) = 0;
      *(undefined1 *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 4) = 0;
      *(undefined1 *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 5) = 0;
      *(undefined1 *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 6) = 0;
      *(undefined4 *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 0x18) = 0;
      if (*(int *)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 0x1c) != -0x22222223) {
        FUN_00495280(*(void **)((int)DAT_004e89f0 + (local_c & 0xffff) * 0x20 + 0x1c));
      }
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
    if (DAT_004d1eac != (void *)0x0) {
      if (DAT_004d1eac != (void *)0xdddddddd) {
        FUN_00495280(DAT_004d1eac);
      }
      DAT_004d1eac = (void *)0x0;
    }
    if (DAT_004e89f0 != (void *)0xdddddddd) {
      FUN_00495280(DAT_004e89f0);
    }
    DAT_004e89f0 = (void *)0x0;
  }
  if (local_8 != (PVOID)0x0) {
    FUN_00439c30(local_8);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  local_8 = (PVOID)0x41a3f9;
  __chkesp();
  return;
}

