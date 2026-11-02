/* FUN_00483920 @ 00483920 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00483920(short param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 local_48 [17];
  
  puVar4 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  for (; param_1 != 0; param_1 = param_1 + -1) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    param_3[7] = 0;
    param_3[8] = 0;
    param_3[9] = 0;
    uVar1 = *param_2;
    puVar3 = param_2 + 1;
    if (((int)(short)uVar1 & 0x8000U) != 0) {
      *param_3 = *param_3 | 1;
      if ((uVar1 & 1) != 0) {
        param_3[1] = *puVar3;
        puVar3 = param_2 + 2;
      }
      param_2 = puVar3;
      if ((uVar1 & 2) != 0) {
        param_3[2] = *param_2;
        param_2 = param_2 + 1;
      }
      puVar3 = param_2;
      if ((uVar1 & 4) != 0) {
        param_3[3] = *param_2;
        puVar3 = param_2 + 1;
      }
    }
    param_2 = puVar3;
    if ((uVar1 & 0x4000) != 0) {
      *param_3 = *param_3 | 2;
      if ((uVar1 & 8) != 0) {
        param_3[4] = *param_2;
        param_2 = param_2 + 1;
      }
      if ((uVar1 & 0x10) != 0) {
        param_3[5] = *param_2;
        param_2 = param_2 + 1;
      }
      if ((uVar1 & 0x20) != 0) {
        param_3[6] = *param_2;
        param_2 = param_2 + 1;
      }
    }
    if ((uVar1 & 0x2000) != 0) {
      *param_3 = *param_3 | 4;
      if ((uVar1 & 0x40) != 0) {
        param_3[7] = *param_2;
        param_2 = param_2 + 1;
      }
      if ((uVar1 & 0x80) != 0) {
        param_3[8] = *param_2;
        param_2 = param_2 + 1;
      }
      if ((uVar1 & 0x100) != 0) {
        param_3[9] = *param_2;
        param_2 = param_2 + 1;
      }
    }
    param_3 = param_3 + 10;
  }
  return;
}

