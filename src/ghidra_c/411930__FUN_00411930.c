/* FUN_00411930 @ 00411930 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411930(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = (int)sVar1;
  switch(local_8) {
  case 0:
    sVar1 = FUN_004074b0(param_2,3);
    DAT_004f1786 = DAT_004f1786 + sVar1;
    DAT_004f1758 = 1;
    break;
  case 1:
    sVar1 = FUN_004074b0(param_2,3);
    if (sVar1 < 0) {
      if (DAT_004f1782 < 4) {
        sVar1 = FUN_004074b0(param_2,3);
        DAT_004f1782 = DAT_004f1782 + sVar1;
      }
    }
    else if (DAT_004f1782 < 3) {
      sVar1 = FUN_004074b0(param_2,3);
      DAT_004f1782 = DAT_004f1782 + sVar1;
    }
    if (3 < DAT_004f1782) {
      DAT_004f1782 = 3;
    }
    DAT_004f16a8 = 1;
    break;
  case 2:
    sVar1 = FUN_004074b0(param_2,3);
    DAT_004f1780 = DAT_004f1780 + sVar1;
    break;
  case 3:
    sVar1 = FUN_004074b0(param_2,3);
    DAT_004f1784 = DAT_004f1784 + sVar1;
    if (DAT_004f1784 < 0) {
      DAT_004f1784 = 0;
    }
    DAT_004f1668 = 1;
    DAT_004e89b4 = 0;
    break;
  case 4:
    sVar1 = FUN_004074b0(param_2,3);
    DAT_004f1788 = DAT_004f1788 + sVar1;
    DAT_004f1800 = 1;
  }
  local_8 = 0x411aa3;
  __chkesp();
  return;
}

