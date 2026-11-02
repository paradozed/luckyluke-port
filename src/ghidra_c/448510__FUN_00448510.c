/* FUN_00448510 @ 00448510 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_00448510(int param_1,int param_2)

{
  undefined3 uVar2;
  undefined4 uVar1;
  int3 iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_44 [16];
  
  puVar5 = local_44;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  uVar2 = (undefined3)((uint)param_1 >> 8);
  if ((uint)(int)*(short *)(param_1 + 8) < DAT_004be3c8) {
    iVar3 = (int3)(char)((ushort)*(short *)(param_1 + 0xc) >> 8);
    if (*(short *)(param_1 + 0xc) < 0) {
      uVar1 = CONCAT31(iVar3,1);
    }
    else if ((uint)(int)*(short *)(param_1 + 10) < DAT_004be3cc) {
      if (*(short *)(param_1 + 0x12) < 0) {
        uVar1 = CONCAT31(uVar2,1);
      }
      else {
        if (*(short *)(param_1 + 8) < 0) {
          *(undefined2 *)(param_2 + 8) = 0;
          *(undefined2 *)(param_2 + 0x10) = 0;
        }
        if (DAT_004be3c8 <= (uint)(int)*(short *)(param_1 + 0xc)) {
          *(short *)(param_2 + 0xc) = (short)DAT_004be3c8 + -1;
          *(short *)(param_2 + 0x14) = (short)DAT_004be3c8 + -1;
        }
        iVar4 = param_1;
        if (*(short *)(param_1 + 10) < 0) {
          *(undefined2 *)(param_2 + 10) = 0;
          *(undefined2 *)(param_2 + 0xe) = 0;
          iVar4 = param_2;
        }
        if (DAT_004be3cc <= (uint)(int)*(short *)(param_1 + 0x12)) {
          *(short *)(param_2 + 0x12) = (short)DAT_004be3cc + -1;
          *(short *)(param_2 + 0x16) = (short)DAT_004be3cc + -1;
          iVar4 = param_2;
        }
        uVar1 = CONCAT31((int3)((uint)iVar4 >> 8),1);
      }
    }
    else {
      uVar1 = CONCAT31(iVar3,1);
    }
  }
  else {
    uVar1 = CONCAT31(uVar2,1);
  }
  return uVar1;
}

