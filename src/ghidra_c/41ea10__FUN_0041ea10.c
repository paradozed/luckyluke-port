/* FUN_0041ea10 @ 0041ea10 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041ea10(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004bcfd0 != 0) && (DAT_004d2884 != '\0')) {
    local_8 = *(int *)(&DAT_004d1f28 + (uint)DAT_004d1f1f * 0x1c) * 0x3c +
              *(int *)(&DAT_004d1f2c + (uint)DAT_004d1f1f * 0x1c);
    local_c = *(int *)(&DAT_004d1f34 + (uint)DAT_004d1f1f * 0x1c) * 0x3c +
              *(int *)(&DAT_004d1f38 + (uint)DAT_004d1f1f * 0x1c);
    local_10 = local_c - local_8;
    timeGetTime();
    iVar1 = __chkesp();
    local_14 = (uint)(iVar1 - *(int *)(&DAT_004d1f40 + (uint)DAT_004d1f1f * 0x1c)) / 1000;
    if (local_10 <= local_14) {
      FUN_0041e930();
    }
    (*DAT_004e8a2c)(10,0x1ae,"Volumes: %d, %d",_DAT_004f58a0,DAT_004d238c);
    __chkesp();
    (*DAT_004e8a2c)(10,0x1b8,"Position: %d",local_14);
    __chkesp();
    (*DAT_004e8a2c)(10,0x1c2,"Length: %d",local_10);
    __chkesp();
    (*DAT_004e8a2c)(10,0x1cc,"Track beginning: %d, %d",
                    *(undefined4 *)(&DAT_004d1f28 + (uint)DAT_004d1f1f * 0x1c),
                    *(undefined4 *)(&DAT_004d1f2c + (uint)DAT_004d1f1f * 0x1c));
    __chkesp();
    (*DAT_004e8a2c)(10,0x1d6,"Track end: %d, %d",
                    *(undefined4 *)(&DAT_004d1f34 + (uint)DAT_004d1f1f * 0x1c),
                    *(undefined4 *)(&DAT_004d1f38 + (uint)DAT_004d1f1f * 0x1c));
    __chkesp();
  }
  local_8 = 0x41ebd5;
  __chkesp();
  return;
}

