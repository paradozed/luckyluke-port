/* FUN_00468c20 @ 00468c20 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_00468c20(ushort param_1,short param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [17];
  
  uVar1 = DAT_004f2458;
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = 0xcccccccc;
  if ((DAT_004f23b8 == (code *)0x0) &&
     (uVar2 = DAT_004f2458, (*(uint *)(DAT_004f2458 + 0x10) & 0x100) == 0)) {
    if (DAT_004f29ac == '\0') {
      DAT_004f1782 = DAT_004f1782 - param_2;
      uVar2 = CONCAT22((short)(DAT_004f2458 >> 0x10),DAT_004f1782);
      DAT_004f16a8 = 1;
    }
    if (DAT_004f1782 < 0) {
      DAT_004f1782 = 3;
      DAT_004f1780 = DAT_004f1780 + -1;
      DAT_004f1794 = DAT_004f1794 | 1;
      *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) | 0x100;
      uVar2 = uVar1;
    }
    if (((*(uint *)(DAT_004f2458 + 0x10) & 0x20) == 0) && (uVar2 = (uint)param_1, param_1 != 0)) {
      param_1 = 1;
    }
    switch(param_1) {
    case 0:
      DAT_004f23b8 = FUN_00468e30;
      break;
    case 1:
      DAT_004f23b8 = FUN_00469020;
      break;
    case 2:
      DAT_004f23b8 = FUN_00465a40;
      DAT_004f23f8 = FUN_0046b0c0;
      break;
    case 3:
      DAT_004f23b8 = FUN_00465a40;
      DAT_004f23f8 = FUN_00468f90;
      break;
    case 4:
      DAT_004f23b8 = FUN_00465a40;
      DAT_004f23f8 = FUN_00468f00;
    }
    uVar2 = CONCAT31((int3)(uVar2 >> 8),1);
  }
  else {
    uVar2 = uVar2 & 0xffffff00;
  }
  return uVar2;
}

