/* FUN_0045cae0 @ 0045cae0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045cae0(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  local_c = param_1 & 0xffff;
  if (local_c == 0) {
    if (DAT_004e8734 != (PVOID)0x0) {
      FUN_0045ca60();
      FUN_004713e0(DAT_004f1e24,DAT_004e8734);
      DAT_004e8734 = (PVOID)0x0;
    }
  }
  else {
    if (local_c != 1) {
      if (local_c != 2) {
        FUN_00497610((byte *)"Error: File %s, Line %d");
        goto LAB_0045cc97;
      }
      DAT_004e872c = 0;
    }
    if (DAT_004e8734 == (PVOID)0x0) {
      FUN_0045ca10();
      DAT_004e8734 = (PVOID)FUN_004714a0(DAT_004f1e24);
      *(undefined2 *)((int)DAT_004e8734 + 0xc) = 0x2f;
      *(code **)((int)DAT_004e8734 + 4) = FUN_0045cac0;
      *(undefined1 *)((int)DAT_004e8734 + 0x10) = 1;
      *(undefined1 *)((int)DAT_004e8734 + 0x11) = 0;
      *(undefined4 *)((int)DAT_004e8734 + 8) = 0;
    }
    if (((DAT_004f2750 & 0x80) != 0) && (DAT_004e8730 != 0)) {
      DAT_004e8730 = DAT_004e8730 - 1;
    }
    if (((DAT_004f2750 & 0x20) != 0) && (DAT_004e8730 < DAT_004d1e90 - 1U)) {
      DAT_004e8730 = DAT_004e8730 + 1;
    }
    if ((DAT_004f2744 & 0x8000) != 0) {
      DAT_004e872c = DAT_004e872c + -1;
    }
    if ((DAT_004f2744 & 0x2000) != 0) {
      DAT_004e872c = DAT_004e872c + 1;
    }
    FUN_004594c0();
  }
LAB_0045cc97:
  local_8 = 0x45cca4;
  __chkesp();
  return;
}

