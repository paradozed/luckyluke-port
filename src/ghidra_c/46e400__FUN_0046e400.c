/* FUN_0046e400 @ 0046e400 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e400(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  undefined4 *local_14;
  undefined4 local_10;
  void *local_c;
  int *local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (int *)FUN_00439a90(DAT_004e85ec,8);
  _memset(local_8,0,8);
  iVar2 = FUN_00439a90(DAT_004e85ec,(param_1 & 0xffff) << 2);
  *local_8 = iVar2;
  _memset((void *)*local_8,0,(param_1 & 0xffff) << 2);
  local_10 = (uint)local_10._2_2_ << 0x10;
  while ((local_10 & 0xffff) < (param_1 & 0xffff)) {
    local_c = (void *)FUN_00439a90(DAT_004e85ec,8);
    *(void **)(*local_8 + (local_10 & 0xffff) * 4) = local_c;
    _memset(local_c,0,8);
    uVar1 = FUN_00439a90(DAT_004e85ec,0x80);
    *(undefined4 *)((int)local_c + 4) = uVar1;
    local_10 = CONCAT22(local_10._2_2_,(short)local_10 + 1);
  }
  *(undefined2 *)((int)local_8 + 6) = (undefined2)param_1;
  local_14 = (undefined4 *)FUN_00439a90(DAT_004e85ec,0xc);
  *local_14 = local_8;
  local_14[1] = 0;
  if (DAT_004e8908 == (undefined4 *)0x0) {
    DAT_004e8908 = local_14;
    DAT_004e890c = local_14;
    local_14[2] = 0;
  }
  else {
    local_14[2] = DAT_004e890c;
    *(undefined4 **)((int)DAT_004e890c + 4) = local_14;
    DAT_004e890c = local_14;
  }
  local_8 = (int *)0x46e579;
  __chkesp();
  return;
}

