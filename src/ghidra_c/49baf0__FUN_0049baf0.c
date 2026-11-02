/* FUN_0049baf0 @ 0049baf0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0049baf0(void)

{
  if (DAT_0050a290 != (undefined4 *)0x0) {
    VirtualFree((LPVOID)(DAT_0050a290[3] + DAT_0050a288 * 0x8000),0x8000,0x4000);
    DAT_0050a290[2] = DAT_0050a290[2] | 0x80000000U >> ((byte)DAT_0050a288 & 0x1f);
    *(undefined4 *)(DAT_0050a290[4] + 0xc4 + DAT_0050a288 * 4) = 0;
    *(char *)(DAT_0050a290[4] + 0x43) = *(char *)(DAT_0050a290[4] + 0x43) + -1;
    if (*(char *)(DAT_0050a290[4] + 0x43) == '\0') {
      DAT_0050a290[1] = DAT_0050a290[1] & 0xfffffffe;
    }
    if ((DAT_0050a290[2] == -1) && (1 < DAT_0050a294)) {
      HeapFree(DAT_0050a29c,0,(LPVOID)DAT_0050a290[4]);
      FUN_004a54a0(DAT_0050a290,DAT_0050a290 + 5,
                   (DAT_0050a298 + DAT_0050a294 * 0x14) - (int)(DAT_0050a290 + 5));
      DAT_0050a294 = DAT_0050a294 + -1;
    }
    DAT_0050a290 = (undefined4 *)0x0;
  }
  return;
}

