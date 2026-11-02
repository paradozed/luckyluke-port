/* FUN_0049a500 @ 0049a500 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0049a500(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = DAT_0050a298;
  for (local_8 = 0; local_8 < DAT_0050a294; local_8 = local_8 + 1) {
    VirtualFree(*(LPVOID *)((int)local_c + 0xc),0x100000,0x4000);
    VirtualFree(*(LPVOID *)((int)local_c + 0xc),0,0x8000);
    HeapFree(DAT_0050a29c,0,*(LPVOID *)((int)local_c + 0x10));
    local_c = (LPVOID)((int)local_c + 0x14);
  }
  HeapFree(DAT_0050a29c,0,DAT_0050a298);
  HeapDestroy(DAT_0050a29c);
  return;
}

