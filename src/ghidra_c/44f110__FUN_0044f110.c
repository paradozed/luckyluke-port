/* FUN_0044f110 @ 0044f110 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044f110(void)

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
    if ((uVar1 & 0xff) == 0) {
      FUN_0041f5e0(3,7,-0x46,0x9c4,0x800,'\0');
    }
    if ((local_8 & 0xff) == 1) {
      FUN_0041f5e0(3,0xb,-0x32,0xdac,0x800,'\0');
    }
    if ((local_8 & 0xff) == 10) {
      FUN_0041f5e0(3,8,0,0x1fff,0x800,'\0');
    }
  }
  DAT_004f2c79 = (undefined1)local_8;
  FUN_0044d930();
  DAT_004e8580 = 1;
  local_8 = 0x44f1e1;
  __chkesp();
  return;
}

