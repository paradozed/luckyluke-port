/* FUN_0042fa90 @ 0042fa90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042fa90(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_15c [16];
  byte *local_11c;
  uint local_114;
  int local_110;
  int local_10c;
  int *local_108;
  CHAR local_104 [252];
  undefined4 uStack_8;
  
  puVar2 = local_15c;
  for (iVar1 = 0x56; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (((DAT_004e8914 < 0x1e) && (DAT_004e89f0 != 0)) && (DAT_004e8914 != 0)) {
    if (DAT_004e8914 == 0x18) {
      (*DAT_005089e8)();
      iVar1 = __chkesp();
      if (iVar1 == 0) {
        local_11c = (byte *)FUN_0042cb20((uint *)"GRLUM01",0);
        if (local_11c != (byte *)0x0) {
          FUN_0047f140(local_11c);
        }
        local_11c = (byte *)FUN_0042cb20((uint *)"GRLUM02",0);
        if (local_11c != (byte *)0x0) {
          FUN_0047f140(local_11c);
        }
        local_11c = (byte *)FUN_0042cb20((uint *)"GRLUM03",0);
        if (local_11c != (byte *)0x0) {
          FUN_0047f140(local_11c);
        }
      }
    }
    wsprintfA(local_104,"win\\objects\\%s.txt",
              *(undefined4 *)(&DAT_004bce50 + (uint)DAT_004e8914 * 4));
    __chkesp();
    local_108 = (int *)FUN_00497d00(local_104,"w");
    if (local_108 != (int *)0x0) {
      for (local_10c = 0; local_10c < (int)(uint)DAT_004e89fa; local_10c = local_10c + 1) {
        for (local_110 = 0; local_110 < (int)(uint)*(ushort *)(DAT_004e89f0 + local_10c * 0x20);
            local_110 = local_110 + 1) {
          if ((**(byte **)(*(int *)(DAT_004e89f0 + 0x14 + local_10c * 0x20) + local_110 * 4) & 2) !=
              0) {
            for (local_114 = 0; local_114 < DAT_004e85a4; local_114 = local_114 + 1) {
              if (*(int *)(DAT_004d1e74 + 0x14 + local_114 * 0x18) ==
                  *(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10c * 0x20) + local_110 * 4)) {
                FUN_00498130(local_108,&DAT_004b4d04);
              }
            }
          }
        }
      }
      FUN_00497b30(local_108);
    }
  }
  uStack_8 = 0x42fd28;
  __chkesp();
  return;
}

