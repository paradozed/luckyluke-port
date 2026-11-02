/* FUN_0044d890 @ 0044d890 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d890(void)

{
  short sVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar5 = local_48;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  cVar2 = FUN_0041fbb0(DAT_004f2c6d);
  if (cVar2 == '\0') {
    FUN_0041fc80(DAT_004f2c6d);
    uVar3 = FUN_0046d700();
    sVar1 = (short)((uVar3 & 0xffff) % 3) * -100;
    local_8 = CONCAT22(local_8._2_2_,sVar1);
    DAT_004f2c6d = FUN_0041f5e0(3,0xc,sVar1,3000,0,'\0');
    FUN_0041fc30(DAT_004f2c6d);
  }
  local_8 = 0x44d926;
  __chkesp();
  return;
}

