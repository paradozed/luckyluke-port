/* FUN_0044e210 @ 0044e210 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044e210(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_0044ce10(2);
  local_8 = CONCAT31(local_8._1_3_,(char)uVar1);
  if (((uVar1 & 0xff) != (uint)DAT_004f2c6e) && ((uVar1 & 0xff) == 4)) {
    FUN_0041f5e0(2,10,200,3000,0,'\0');
  }
  DAT_004f2c6e = (undefined1)local_8;
  FUN_0044cbb0();
  local_8 = 0x44e28b;
  __chkesp();
  return;
}

