/* FUN_0040fb80 @ 0040fb80 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040fb80(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 local_64 [16];
  int local_24;
  int local_20;
  float local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar3 = local_64;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_18 = (int)sVar1;
  local_14 = *(undefined4 *)(*(int *)(&DAT_004d1e14 + local_18 * 0x10) + 0x90);
  local_10 = *(undefined4 *)(*(int *)(&DAT_004d1e14 + local_18 * 0x10) + 0x94);
  local_c = *(undefined4 *)(*(int *)(&DAT_004d1e14 + local_18 * 0x10) + 0x98);
  uVar4 = FUN_00497360();
  local_20 = (int)uVar4;
  local_1c = (float)local_20 / _DAT_004b40d4 - *(float *)(&DAT_004d1e08 + local_18 * 0x10);
  *(float *)(&DAT_004d1e0c + local_18 * 0x10) =
       local_1c * (float)_DAT_004b40d8 + *(float *)(&DAT_004d1e0c + local_18 * 0x10);
  lVar5 = __ftol();
  local_10 = (int)lVar5;
  FUN_00410090(*(int *)(&DAT_004d1e14 + local_18 * 0x10),local_14,local_10,local_c);
  uVar4 = FUN_00497360();
  local_24 = (int)uVar4;
  *(float *)(&DAT_004d1e08 + local_18 * 0x10) = (float)local_24 / _DAT_004b40d4;
  if (*(float *)(&DAT_004d1e10 + local_18 * 0x10) <= (float)local_10) {
    lVar5 = __ftol();
    local_10 = (int)lVar5;
  }
  uStack_8 = 0x40fcbf;
  __chkesp();
  return;
}

