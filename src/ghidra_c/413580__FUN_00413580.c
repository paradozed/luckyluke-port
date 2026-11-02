/* FUN_00413580 @ 00413580 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00413580(undefined4 param_1,void *param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_54 [16];
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar4 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  DAT_004e8580 = 0;
  DAT_004f1794 = DAT_004f1794 & 0xfffa;
  if (DAT_004f2458 != (int *)0x0) {
    DAT_004f2458[4] = DAT_004f2458[4] & 0xfffffeff;
  }
  sVar2 = FUN_004074b0(param_2,2);
  if (sVar2 == 0) {
    DAT_004f17e8 = 0;
    cVar1 = FUN_004749b0();
    if (cVar1 == '\0') {
      if (DAT_004f2e1c != '\0') {
        if (DAT_004e8914 == 5) {
          FUN_00411c90(*DAT_004f2458,DAT_004f2e10,DAT_004f2e14,DAT_004f2e18);
        }
        else {
          local_14 = DAT_004f2e10;
          local_10 = DAT_004f2e14;
          local_c = DAT_004f2e18;
          FUN_00457740(*DAT_004f2458,*(int *)(*DAT_004f2458 + 0xe4),&local_14);
          FUN_00452f50();
        }
        DAT_004f1794 = DAT_004f1794 & 0xfffe;
        DAT_004f2458[4] = DAT_004f2458[4] & 0xfffffeff;
        if (*(int *)(*DAT_004f2458 + 0xe4) != 0) {
          *(undefined2 *)(DAT_004f2458 + 0x29) =
               *(undefined2 *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58);
        }
      }
      *(undefined1 *)(DAT_004f16e0 + 0x14) = 1;
      *(undefined1 *)(DAT_004f16ec + 0x14) = 1;
      *(undefined1 *)(DAT_004f16f0 + 0x14) = 1;
      *(undefined1 *)(DAT_004f16e4 + 0x14) = 1;
    }
    else {
      DAT_004f1e21 = 1;
    }
  }
  else {
    DAT_004f17e8 = 1;
    DAT_004f1e21 = 1;
  }
  uStack_8 = 0x413737;
  __chkesp();
  return;
}

