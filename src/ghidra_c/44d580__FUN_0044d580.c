/* FUN_0044d580 @ 0044d580 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d580(void)

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
  uVar1 = FUN_0044ce10(3);
  local_8 = CONCAT31(local_8._1_3_,(char)uVar1);
  if ((uVar1 & 0xff) != (uint)DAT_004f2c79) {
    if ((uVar1 & 0xff) == 1) {
      FUN_0041f5e0(3,7,-0x46,0x9c4,0,'\0');
    }
    if ((local_8 & 0xff) == 6) {
      FUN_0041f5e0(3,10,-0x46,4000,0,'\0');
    }
  }
  DAT_004f2c79 = (undefined1)local_8;
  if (*(short *)(*(int *)(**(int **)(&DAT_004f2c64 + (uint)DAT_004e8612 * 4) + 0xc4) + 0x32) == 5) {
    DAT_004e861f = 1;
  }
  else {
    FUN_0044d930();
  }
  local_8 = 0x44d649;
  __chkesp();
  return;
}

