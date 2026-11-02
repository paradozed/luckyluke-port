/* FUN_00429ee0 @ 00429ee0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00429ee0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  int *local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (int *)FUN_00497d00("win\\backinfo.dat","rb");
  if (local_8 == (int *)0x0) {
    FUN_00429e30();
  }
  else {
    for (local_c = 0; local_c < 0x1f; local_c = local_c + 1) {
      uVar1 = FUN_00498340(local_8);
      *(uint *)(&DAT_004f79e0 + local_c * 0x1c) = uVar1;
      uVar1 = FUN_00498340(local_8);
      *(uint *)(&DAT_004f79f0 + local_c * 0x1c) = uVar1;
      uVar1 = FUN_00498340(local_8);
      *(uint *)(&DAT_004f79f4 + local_c * 0x1c) = uVar1;
      uVar1 = FUN_00498340(local_8);
      *(uint *)(&DAT_004f79f8 + local_c * 0x1c) = uVar1;
      uVar1 = FUN_00498340(local_8);
      *(uint *)(&DAT_004f79e4 + local_c * 0x1c) = uVar1;
      uVar1 = FUN_00498340(local_8);
      *(uint *)(&DAT_004f79e8 + local_c * 0x1c) = uVar1;
      uVar1 = FUN_00498340(local_8);
      *(uint *)(&DAT_004f79ec + local_c * 0x1c) = uVar1;
      if (local_c == 2) {
        uRam004f7a18 = uRam004f7a18 ^ 1;
      }
      if (local_c == 7) {
        uRam004f7aa4 = 4;
      }
      if (local_c == 0xb) {
        uRam004f7b14 = 5;
        uRam004f7b24 = 0xfa;
        uRam004f7b28 = 0xee;
        uRam004f7b2c = 0x10;
        uRam004f7b18 = 0xff;
        uRam004f7b1c = 0x80;
        uRam004f7b20 = 0x40;
      }
      if (local_c == 0xc) {
        uRam004f7b30 = uRam004f7b30 ^ 1;
      }
    }
    FUN_00497b30(local_8);
  }
  local_8 = (int *)0x42a0cd;
  __chkesp();
  return;
}

