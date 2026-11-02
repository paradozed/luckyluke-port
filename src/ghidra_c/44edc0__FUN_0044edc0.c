/* FUN_0044edc0 @ 0044edc0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044edc0(void)

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
  uVar1 = FUN_0044ce10(3);
  local_8 = CONCAT31(local_8._1_3_,(char)uVar1);
  if (((uVar1 & 0xff) != (uint)DAT_004f2c79) && ((uVar1 & 0xff) == 2)) {
    FUN_0041f5e0(3,9,-100,0x9c4,0x800,'\0');
  }
  DAT_004f2c79 = (undefined1)local_8;
  local_8 = 0x44ee36;
  __chkesp();
  return;
}

