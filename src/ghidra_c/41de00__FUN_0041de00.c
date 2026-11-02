/* FUN_0041de00 @ 0041de00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041de00(undefined4 param_1,void *param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_54 [16];
  short local_14;
  short local_10;
  uint local_c;
  int local_8;
  
  puVar4 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_10 = FUN_004074b0(param_2,5);
  local_14 = FUN_004074b0(param_2,4);
  local_10 = (short)(local_10 * 0x100 + (local_10 * 0x100 >> 0x1f & 0xffU) >> 8);
  if (DAT_004e85b8 != 1) {
    local_10 = (short)((uint)(local_10 * DAT_004be3cc) >> 8);
    local_14 = (short)((uint)(local_14 * DAT_004be3c8) >> 9);
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  uVar2 = FUN_004074b0(param_2,3);
  local_c = CONCAT22(local_c._2_2_,uVar2);
  if (*(int *)(local_8 + 4 + (uint)uVar2 * 4) != 0) {
    sVar1 = FUN_004074b0(param_2,6);
    FUN_0041dbc0(*(int *)(local_8 + 4 + (local_c & 0xffff) * 4),(int)local_14,(int)local_10,
                 (int)sVar1);
  }
  local_8 = 0x41def1;
  __chkesp();
  return;
}

