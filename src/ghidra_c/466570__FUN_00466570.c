/* FUN_00466570 @ 00466570 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00466570(void)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_4c [16];
  uint local_c;
  undefined4 local_8;
  
  puVar5 = local_4c;
  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  if (599 < (uint)(DAT_004e89e0 - _DAT_004e8848)) {
    _DAT_004e8848 = DAT_004e89e0;
    DAT_004e884c = DAT_004e884c + 1;
    local_c = DAT_004e884c & 3;
    switch(local_c) {
    case 0:
      uVar2 = FUN_0041ff20();
      if ((uVar2 & 0xff) == 1) {
        uVar3 = FUN_0041ffb0();
        sVar1 = (short)uVar3 + 0x32;
        local_8 = CONCAT22(local_8._2_2_,sVar1);
        FUN_0041f5e0(0,7,sVar1,5000,0x400,'\0');
      }
      FUN_00466510(1,FUN_00466570);
      break;
    case 1:
      uVar2 = FUN_0041ff20();
      if ((uVar2 & 0xff) == 1) {
        uVar2 = FUN_0041ffb0();
        sVar1 = (short)((uVar2 & 0xffff) - 100);
        local_8 = CONCAT22(local_8._2_2_,sVar1);
        FUN_0041f5e0(0,4,sVar1,5000,0x400,'\0');
      }
      FUN_00466510(2,FUN_00466570);
      break;
    case 2:
      uVar2 = FUN_0041ff20();
      if ((uVar2 & 0xff) == 1) {
        uVar3 = FUN_0041ffb0();
        sVar1 = (short)uVar3 + -100;
        local_8 = CONCAT22(local_8._2_2_,sVar1);
        FUN_0041f5e0(0,5,sVar1,5000,0x400,'\0');
      }
      FUN_00466510(3,FUN_00466570);
      break;
    case 3:
      uVar2 = FUN_0041ff20();
      if ((uVar2 & 0xff) == 1) {
        uVar3 = FUN_0041ffb0();
        sVar1 = (short)uVar3 + -100;
        local_8 = CONCAT22(local_8._2_2_,sVar1);
        FUN_0041f5e0(0,6,sVar1,5000,0x400,'\0');
      }
      FUN_00466510(2,FUN_00466570);
    }
  }
  local_8 = 0x466728;
  __chkesp();
  return;
}

