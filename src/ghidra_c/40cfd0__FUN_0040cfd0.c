/* FUN_0040cfd0 @ 0040cfd0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_0040cfd0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004f23f8 == FUN_00466740) {
    uVar1 = 0xcccc0000;
  }
  else if (DAT_004f23f8 == FUN_00466b60) {
    uVar1 = 0xcccc0001;
  }
  else if (DAT_004f23f8 == FUN_00466d80) {
    uVar1 = 0xcccc0002;
  }
  else if (DAT_004f23f8 == FUN_00467660) {
    uVar1 = 0xcccc0003;
  }
  else if (DAT_004f23f8 == FUN_00467170) {
    uVar1 = 0xcccc0005;
  }
  else if (DAT_004f23f8 == FUN_00466fe0) {
    uVar1 = 0xcccc0006;
  }
  else if (DAT_004f23f8 == FUN_004688d0) {
    uVar1 = 0xcccc0009;
  }
  else if (DAT_004f23f8 == FUN_00469870) {
    uVar1 = 0xcccc0010;
  }
  else {
    uVar1 = 0xcccc0000;
  }
  return uVar1;
}

