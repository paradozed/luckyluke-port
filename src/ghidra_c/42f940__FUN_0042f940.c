/* FUN_0042f940 @ 0042f940 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042f940(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_170 [17];
  uint local_12c;
  int *local_128;
  char local_124 [32];
  CHAR local_104 [252];
  undefined4 uStack_8;
  
  puVar3 = local_170;
  for (iVar2 = 0x5b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_12c = 0;
  if (DAT_004e8914 < 0x1e) {
    wsprintfA(local_104,"win\\objects\\%s.txt",
              *(undefined4 *)(&DAT_004bce50 + (uint)DAT_004e8914 * 4));
    __chkesp();
    local_128 = (int *)FUN_00497d00(local_104,"rb");
    if (local_128 != (int *)0x0) {
      while (cVar1 = FUN_0042f8d0(local_128,local_124), cVar1 != '\0') {
        for (local_12c = 0; local_12c < DAT_004e85a4; local_12c = local_12c + 1) {
          iVar2 = _strcmp(local_124,(char *)(DAT_004d1e74 + local_12c * 0x18));
          if (iVar2 == 0) {
            FUN_0047f2d0(*(byte **)(DAT_004d1e74 + 0x14 + local_12c * 0x18));
          }
        }
      }
      FUN_00497b30(local_128);
    }
  }
  uStack_8 = 0x42fa7e;
  __chkesp();
  return;
}

