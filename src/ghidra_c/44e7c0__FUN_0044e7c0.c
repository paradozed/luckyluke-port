/* FUN_0044e7c0 @ 0044e7c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044e7c0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_0044ce10(2);
  local_8 = CONCAT31(local_8._1_3_,(char)uVar1);
  if ((uVar1 & 0xff) != (uint)DAT_004f2c6e) {
    if ((uVar1 & 0xff) == 1) {
      FUN_0041f5e0(2,0xf,0,0xdac,0,'\0');
    }
    if ((local_8 & 0xff) == 3) {
      FUN_0041f5e0(2,0xb,-0x96,4000,0,'\0');
    }
  }
  DAT_004f2c6e = (undefined1)local_8;
  if (DAT_004e85b8 == 0x15) {
    DAT_004f5556 = 1;
  }
  else if (*(short *)(*(int *)(**(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8) + 0xc4) + 0x32) == 3) {
    DAT_004f5556 = 1;
  }
  local_8 = 0x44e896;
  __chkesp();
  return;
}

