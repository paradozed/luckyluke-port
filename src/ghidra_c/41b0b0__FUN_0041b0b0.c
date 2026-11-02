/* FUN_0041b0b0 @ 0041b0b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041b0b0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  short *local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004074b0(param_2,2);
  local_c = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  iVar2 = *(int *)(local_c + 0xc4);
  local_10 = (short *)(iVar2 + 0x2a);
  if (*local_10 < 0xc9) {
    if (*local_10 < 0xb) {
      if (*local_10 < 1) {
        if (*local_10 == 0) {
          *(undefined4 *)(local_8 + 4) = 0;
        }
        else if (*local_10 < -9) {
          if (*local_10 < -199) {
            *(undefined4 *)(local_8 + 4) = 0xffffffb0;
          }
          else {
            *(undefined4 *)(local_8 + 4) = 0xffffffce;
          }
        }
        else {
          *(undefined4 *)(local_8 + 4) = 0xfffffff6;
        }
      }
      else {
        *(undefined4 *)(local_8 + 4) = 10;
      }
    }
    else {
      *(undefined4 *)(local_8 + 4) = 0x32;
    }
  }
  else {
    *(undefined4 *)(local_8 + 4) = 0x50;
  }
  if (*(short *)(iVar2 + 0x2c) < 0) {
    if (*(short *)(iVar2 + 0x2c) < -9) {
      if (*(short *)(iVar2 + 0x2c) < -199) {
        *(undefined4 *)(local_8 + 8) = 0xffffff9c;
      }
      else {
        *(undefined4 *)(local_8 + 8) = 0xffffffb0;
      }
    }
    else {
      *(undefined4 *)(local_8 + 8) = 0xffffffc4;
    }
  }
  else {
    *(undefined4 *)(local_8 + 8) = 0;
  }
  *(int *)(local_8 + 0xc) = (int)*(short *)(iVar2 + 0x2e);
  *(undefined2 *)(local_8 + 0x14) = 0xffff;
  local_8 = 0x41b21c;
  __chkesp();
  return;
}

