/* FUN_0041dd20 @ 0041dd20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041dd20(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_58 [16];
  int local_18;
  undefined4 local_14;
  short local_10;
  uint local_c;
  int local_8;
  
  puVar4 = local_58;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  uVar2 = FUN_004074b0(param_2,3);
  local_c = CONCAT22(local_c._2_2_,uVar2);
  local_10 = FUN_004074b0(param_2,4);
  if (*(int *)(local_8 + 4 + (local_c & 0xffff) * 4) != 0) {
    local_18 = *(int *)(*(int *)(*(int *)(local_8 + 4 + (local_c & 0xffff) * 4) + 0xcc) + 0x28);
    iVar3 = *(int *)(local_8 + 4 + (local_c & 0xffff) * 4);
    local_14 = *(undefined4 *)(*(int *)(iVar3 + 0xcc) + 0x14);
    FUN_004856f0(*(byte **)(local_8 + 4 + (local_c & 0xffff) * 4),local_18,local_10,local_10,
                 CONCAT22((short)((uint)iVar3 >> 0x10),(undefined2)local_14));
  }
  local_8 = 0x41ddf1;
  __chkesp();
  return;
}

