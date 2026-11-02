/* FUN_00464ce0 @ 00464ce0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00464ce0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_84 [16];
  int local_44;
  int *local_40;
  int *local_3c;
  undefined2 local_38;
  int local_34 [6];
  int local_1c [3];
  int local_10;
  undefined4 uStack_8;
  
  puVar4 = local_84;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_3c = *(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_40 = *(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4);
  FUN_0040da10(local_3c,0,local_1c);
  FUN_0040da10(local_40,0,local_34);
  iVar3 = FUN_004975e0(local_10 - local_34[0]);
  local_38 = (undefined2)iVar3;
  cVar1 = FUN_00461250();
  if (cVar1 == '\0') {
    if (*(ushort *)((&DAT_004f25a0)[DAT_004e8814] + 0x10) <
        *(ushort *)((&DAT_004f25a0)[DAT_004e8814] + 0xe)) {
      *(undefined2 *)((&DAT_004f25a0)[DAT_004e8814] + 0xe) = 0;
      uVar2 = FUN_0046d700();
      *(short *)((&DAT_004f25a0)[DAT_004e8814] + 0x10) = (short)((ulonglong)(uVar2 & 0xffff) % 0x14)
      ;
      DAT_004e8818 = 10;
      DAT_004e880f = 1;
    }
    else {
      DAT_004e8810 = 0;
      local_44 = DAT_004e8844 - 5;
      switch(local_44) {
      case 0:
        cVar1 = FUN_00464bf0(2);
        if (cVar1 == '\0') {
          DAT_004f2598 = FUN_0045ff60;
          FUN_0045ff60();
        }
        else {
          DAT_004f2598 = FUN_00460670;
          FUN_00460670();
        }
        break;
      case 1:
        cVar1 = FUN_00464bf0(2);
        if (cVar1 == '\0') {
          DAT_004f2598 = FUN_0045ff60;
          FUN_0045ff60();
        }
        else {
          DAT_004f2598 = FUN_00460670;
          FUN_00460670();
        }
        break;
      case 2:
        cVar1 = FUN_00464bf0(2);
        if (cVar1 == '\0') {
          DAT_004f2598 = FUN_0045ff60;
          FUN_0045ff60();
        }
        else {
          DAT_004f2598 = FUN_00460810;
          FUN_00460810();
        }
        break;
      case 3:
        cVar1 = FUN_00464bf0(2);
        if (cVar1 == '\0') {
          DAT_004f2598 = FUN_0045ff60;
          FUN_0045ff60();
        }
        else {
          DAT_004f2598 = FUN_00460810;
          FUN_00460810();
        }
        break;
      case 4:
        cVar1 = FUN_00464bf0(3);
        if (cVar1 == '\0') {
          DAT_004f2598 = FUN_0045fdc0;
          FUN_0045fdc0();
        }
        else {
          DAT_004f2598 = FUN_004604d0;
          FUN_004604d0();
        }
        break;
      case 5:
        cVar1 = FUN_00464bf0(3);
        if (cVar1 == '\0') {
          DAT_004f2598 = FUN_0045fdc0;
          FUN_0045fdc0();
        }
        else {
          DAT_004f2598 = FUN_004604d0;
          FUN_004604d0();
        }
      }
    }
  }
  uStack_8 = 0x464fa3;
  __chkesp();
  return;
}

