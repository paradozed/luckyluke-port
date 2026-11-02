/* FUN_00468160 @ 00468160 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00468160(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if ((DAT_004f2458[4] & 0x20U) == 0) {
    DAT_004f23f8 = FUN_00467dd0;
    FUN_00467dd0();
  }
  else {
    if (DAT_004f5556 != '\0') {
      uVar2 = FUN_0041ff20();
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 1) {
        uVar2 = FUN_0041f5e0(0,0,-200,0x1fff,0x400,'\0');
      }
      FUN_0046c610(CONCAT22((short)(uVar2 >> 0x10),DAT_004e883e));
    }
    DAT_004f5556 = '\0';
    DAT_004e883e = FUN_00469350();
    uVar1 = *(ushort *)(&DAT_004bdf90 + (uint)DAT_004e883e * 2);
    local_8 = CONCAT22(local_8._2_2_,uVar1);
    if (DAT_004e8838 != uVar1) {
      if ((uVar1 == 0xb) || (uVar1 == 0xc)) {
        FUN_004669b0(*DAT_004f2458,(undefined4 *)&DAT_004f23e0);
      }
      else {
        FUN_004669b0(*DAT_004f2458,&DAT_004f2440);
      }
      DAT_004e8838 = (ushort)local_8;
      FUN_00466510((ushort)local_8,FUN_00468130);
      DAT_004f5556 = '\x01';
    }
    if ((DAT_004f2438 & 0x2000) == 0) {
      DAT_004f23f8 = FUN_004680e0;
      FUN_004680e0();
    }
    else if ((DAT_004f245c & 0x8000) != 0) {
      DAT_004f23f8 = FUN_00467830;
      FUN_00467830();
    }
  }
  local_8 = 0x4682dd;
  __chkesp();
  return;
}

