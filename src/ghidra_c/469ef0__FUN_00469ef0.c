/* FUN_00469ef0 @ 00469ef0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00469ef0(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((DAT_004f2458[4] & 1U) != 0) {
    DAT_004f2438 = DAT_004f2438 & 0x7fff;
    DAT_004f245c = DAT_004f245c & 0x7fff;
  }
  if ((DAT_004f2458[4] & 0x200U) != 0) {
    DAT_004f2438 = DAT_004f2438 & 0xff7f;
    DAT_004f245c = DAT_004f245c & 0xff7f;
  }
  if ((DAT_004f2458[4] & 0x400U) != 0) {
    DAT_004f2438 = DAT_004f2438 & 0xffdf;
    DAT_004f245c = DAT_004f245c & 0xffdf;
  }
  if ((DAT_004f2458[4] & 0x800U) != 0) {
    DAT_004f2438 = DAT_004f2438 & 0xffef;
    DAT_004f245c = DAT_004f245c & 0xffef;
  }
  if ((DAT_004f2458[4] & 0x1000U) != 0) {
    DAT_004f2438 = DAT_004f2438 & 0xffbf;
    DAT_004f245c = DAT_004f245c & 0xffbf;
  }
  if ((DAT_004f2458[4] & 0x2000U) != 0) {
    DAT_004f2438 = DAT_004f2438 & 0xdfff;
    DAT_004f245c = DAT_004f245c & 0xdfff;
  }
  if ((DAT_004f2458[4] & 0x4000U) != 0) {
    DAT_004f2438 = DAT_004f2438 & 0xefff;
    DAT_004f245c = DAT_004f245c & 0xefff;
  }
  if (((DAT_004f2458[4] & 0x100U) != 0) && ((DAT_004f1794 & 1) == 0)) {
    FUN_0041f5e0(0,2,-0x1c2,0x1fff,0x400,'\0');
    DAT_004f1782 = 3;
    DAT_004f1780 = DAT_004f1780 + -1;
    DAT_004f1794 = DAT_004f1794 | 1;
  }
  if ((DAT_004f2438 & 0x8000) == 0) {
    DAT_004f2458[4] = DAT_004f2458[4] | 0x40000;
  }
  if ((DAT_004f2458[4] & 0x20U) != 0) {
    cVar1 = **(char **)(*(int *)(*DAT_004f2458 + 0xe4) + 0x14);
    local_8 = CONCAT31(local_8._1_3_,cVar1);
    if (cVar1 == '\x01') {
      if (DAT_004f23b8 != (code *)0x0) {
        DAT_004f23b8 = FUN_00468d80;
      }
      DAT_004f2458[4] = DAT_004f2458[4] & 0xffffffbf;
      DAT_004f2400 = FUN_00465ab0;
      FUN_00466510(4,FUN_00465a40);
      DAT_004f23c4 = FUN_00469dd0;
      DAT_004f23f8 = (code *)0x0;
    }
    else if (cVar1 == '\x02') {
      FUN_00466510(5,FUN_00465a40);
      DAT_004f2400 = FUN_00465b00;
      DAT_004f23c4 = (code *)0x0;
      DAT_004f23f8 = FUN_00469ea0;
    }
  }
  local_8 = 0x46a1de;
  __chkesp();
  return;
}

