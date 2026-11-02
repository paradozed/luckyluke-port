/* FUN_0041da00 @ 0041da00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041da00(undefined4 param_1,void *param_2)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined2 extraout_var;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_64 [16];
  int local_24;
  short local_20;
  short local_1c;
  undefined4 local_18;
  short local_14;
  short local_10;
  uint local_c;
  int local_8;
  
  puVar5 = local_64;
  for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_1c = FUN_004074b0(param_2,7);
  local_20 = FUN_004074b0(param_2,6);
  local_1c = (short)(local_1c * 0x100 + (local_1c * 0x100 >> 0x1f & 0xffU) >> 8);
  if (DAT_004e85b8 != 1) {
    local_1c = (short)((uint)(local_1c * DAT_004be3cc) >> 8);
    local_20 = (short)((uint)(local_20 * DAT_004be3c8) >> 9);
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  uVar2 = FUN_004074b0(param_2,3);
  local_c = CONCAT22(local_c._2_2_,uVar2);
  if (*(int *)(local_8 + 4 + (uint)uVar2 * 4) == 0) {
    local_14 = FUN_004074b0(param_2,4);
    local_24 = FUN_0046e8d0((int)local_14);
    local_18 = *(undefined4 *)(*(int *)(local_24 + 8) + 4);
    local_10 = FUN_004074b0(param_2,5);
    uVar3 = FUN_004867c0((ushort)local_18,local_10);
    *(undefined4 *)(local_8 + 4 + (local_c & 0xffff) * 4) = uVar3;
    FUN_0047f0f0(*(byte **)(local_8 + 4 + (local_c & 0xffff) * 4));
    FUN_00485a70(*(byte **)(local_8 + 4 + (local_c & 0xffff) * 4),local_24,(ushort)local_18,0,0,1,0,
                 (int)local_10);
    sVar1 = FUN_004074b0(param_2,8);
    FUN_0041dbc0(*(int *)(local_8 + 4 + (local_c & 0xffff) * 4),(int)local_20,(int)local_1c,
                 (int)sVar1);
    FUN_004856f0(*(byte **)(local_8 + 4 + (local_c & 0xffff) * 4),local_24,0,0,
                 CONCAT22(extraout_var,local_10));
  }
  local_8 = 0x41dbbb;
  __chkesp();
  return;
}

