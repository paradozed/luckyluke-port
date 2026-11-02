/* FUN_0049b200 @ 0049b200 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 * FUN_0049b200(void)

{
  LPVOID pvVar1;
  undefined4 *puVar2;
  
  if (DAT_0050a294 == DAT_0050a284) {
    pvVar1 = HeapReAlloc(DAT_0050a29c,0,DAT_0050a298,(DAT_0050a284 + 0x10) * 0x14);
    if (pvVar1 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_0050a284 = DAT_0050a284 + 0x10;
    DAT_0050a298 = pvVar1;
  }
  puVar2 = (undefined4 *)((int)DAT_0050a298 + DAT_0050a294 * 0x14);
  pvVar1 = HeapAlloc(DAT_0050a29c,8,0x41c4);
  puVar2[4] = pvVar1;
  if (puVar2[4] == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    pvVar1 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar2[3] = pvVar1;
    if (puVar2[3] == 0) {
      HeapFree(DAT_0050a29c,0,(LPVOID)puVar2[4]);
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0xffffffff;
      DAT_0050a294 = DAT_0050a294 + 1;
      *(undefined4 *)puVar2[4] = 0xffffffff;
    }
  }
  return puVar2;
}

