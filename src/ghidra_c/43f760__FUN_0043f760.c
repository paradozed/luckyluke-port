/* FUN_0043f760 @ 0043f760 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043f760(void)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 local_4c [14];
  undefined4 uStack_14;
  int local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while( true ) {
    (**(code **)(*DAT_004e8514 + 0x24))(DAT_004e8514,0x10,&DAT_004f5b10);
    local_8 = __chkesp();
    if (local_8 == 0) break;
    if (local_8 != -0x7ff8ffe2) goto LAB_0043f8b9;
    (**(code **)(*DAT_004e8514 + 0x1c))(DAT_004e8514);
    __chkesp();
  }
  lVar3 = __ftol();
  DAT_004bcdcc = DAT_004bcdcc + (int)lVar3;
  lVar3 = __ftol();
  DAT_004bcdd0 = DAT_004bcdd0 + (int)lVar3;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if ((((&DAT_004f5b1c)[local_c] & 0x80) == 0) && (*(int *)(&DAT_004e8518 + local_c * 4) != 0)) {
      *(undefined4 *)(&DAT_004e8528 + local_c * 4) = 1;
    }
    else {
      *(undefined4 *)(&DAT_004e8528 + local_c * 4) = 0;
    }
  }
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if (((&DAT_004f5b1c)[local_c] & 0x80) == 0) {
      *(undefined4 *)(&DAT_004e8518 + local_c * 4) = 0;
    }
    else {
      *(undefined4 *)(&DAT_004e8518 + local_c * 4) = 1;
    }
  }
LAB_0043f8b9:
  uStack_14 = 0x43f8c9;
  __chkesp();
  return;
}

