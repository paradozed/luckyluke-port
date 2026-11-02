/* FUN_00475ab0 @ 00475ab0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00475ab0(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)((&DAT_004f16e0)[param_1 & 0xff] + 0x10) = 1;
  if ((int)(param_2 & 0xff) <=
      (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16 + (param_1 & 0xff) * 0x20)) {
    DAT_004e8978 = DAT_004e8abc >> 5;
    *(undefined1 *)((&DAT_004f16e0)[param_1 & 0xff] + 0x10) = 1;
    if (DAT_004e899c == 0) {
      DAT_004e899c = DAT_004e8abc >> 5;
    }
    if (DAT_004e8978 - DAT_004e899c < 0x3d) {
      if ((DAT_004e8978 & 8) == 0) {
        *(undefined1 *)((&DAT_004f16e0)[param_1 & 0xff] + 0x10) = 0;
      }
    }
    else {
      DAT_004e899c = 0;
    }
  }
  return;
}

