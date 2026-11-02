/* FUN_00403e70 @ 00403e70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00403e70(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  int local_1c;
  undefined2 *local_18;
  undefined1 local_14 [4];
  undefined1 local_10;
  undefined4 local_c;
  int local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  if (0 < DAT_004d1cdc) {
    GlobalAlloc(0x40,DAT_004d1cdc * 8 + 2);
    iVar1 = __chkesp();
    *param_1 = iVar1;
    if (*param_1 != 0) {
      *(short *)*param_1 = DAT_004d1cdc;
      local_18 = (undefined2 *)(*param_1 + 2);
      for (local_1c = 1; local_1c <= DAT_004d1cdc; local_1c = local_1c + 1) {
        local_c = 2;
        local_8 = local_1c;
        mciSendCommandA(DAT_004d1d60,0x814,0x110,(DWORD_PTR)local_14);
        iVar1 = __chkesp();
        if (iVar1 != 0) break;
        *local_18 = (undefined2)local_1c;
        *(undefined1 *)(local_18 + 1) = local_10;
        *(char *)((int)local_18 + 3) = (char)((uint)_local_10 >> 8);
        *(char *)(local_18 + 2) = (char)((uint)_local_10 >> 0x10);
        local_c = 1;
        mciSendCommandA(DAT_004d1d60,0x814,0x110,(DWORD_PTR)local_14);
        iVar1 = __chkesp();
        if (iVar1 != 0) break;
        *(undefined1 *)((int)local_18 + 5) = local_10;
        *(char *)(local_18 + 3) = (char)((uint)_local_10 >> 8);
        *(char *)((int)local_18 + 7) = (char)((uint)_local_10 >> 0x10);
        *(char *)((int)local_18 + 7) = *(char *)((int)local_18 + 7) + *(char *)(local_18 + 2);
        if (0x4b < *(byte *)((int)local_18 + 7)) {
          *(char *)(local_18 + 3) = *(char *)(local_18 + 3) + '\x01';
          *(char *)((int)local_18 + 7) = *(char *)((int)local_18 + 7) + -0x3c;
        }
        *(char *)(local_18 + 3) = *(char *)(local_18 + 3) + *(char *)((int)local_18 + 3);
        if (0x3b < *(byte *)(local_18 + 3)) {
          *(char *)((int)local_18 + 5) = *(char *)((int)local_18 + 5) + '\x01';
          *(char *)(local_18 + 3) = *(char *)(local_18 + 3) + -0x3c;
        }
        *(char *)((int)local_18 + 5) = *(char *)((int)local_18 + 5) + *(char *)(local_18 + 1);
        local_18 = local_18 + 4;
      }
    }
  }
  local_8 = 0x404084;
  __chkesp();
  return;
}

