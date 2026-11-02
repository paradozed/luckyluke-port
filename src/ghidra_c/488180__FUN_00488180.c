/* FUN_00488180 @ 00488180 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00488180(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined4 local_64 [16];
  int local_24;
  int local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0xffff;
  local_14 = 100000.0;
  for (local_8 = 0; local_8 < DAT_004e8ae4; local_8 = local_8 + 1) {
    local_20 = param_1 - *(int *)(DAT_004e8ae0 + 4 + local_8 * 0xc);
    local_1c = (float)local_20;
    local_24 = param_2 - *(int *)(DAT_004e8ae0 + 8 + local_8 * 0xc);
    local_18 = (float)local_24;
    fVar3 = (float10)FUN_00497534(local_24);
    local_10 = (float)fVar3;
    if (fVar3 < (float10)local_14) {
      local_c = local_8;
      local_14 = local_10;
    }
  }
  local_8 = 0x48825c;
  __chkesp();
  return;
}

