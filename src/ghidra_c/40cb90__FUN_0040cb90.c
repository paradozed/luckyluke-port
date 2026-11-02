/* FUN_0040cb90 @ 0040cb90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040cb90(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  undefined4 local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  iVar2 = FUN_00407580(param_1);
  local_8 = *(int *)(iVar2 + 8);
  sVar1 = FUN_004074b0(param_2,2);
  local_c = *(int *)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_10 = (uint)local_10._2_2_ << 0x10;
  while (((local_10 & 0xffff) < 3 &&
         (*(int *)(local_8 + 0x44 + (local_10 & 0xffff) * 0xc) != local_c))) {
    local_10 = CONCAT22(local_10._2_2_,(short)local_10 + 1);
  }
  local_8 = 0x40cc39;
  __chkesp();
  return;
}

