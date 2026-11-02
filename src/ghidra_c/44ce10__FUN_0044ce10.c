/* FUN_0044ce10 @ 0044ce10 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_0044ce10(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [18];
  undefined2 local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = 0;
  uVar1 = param_1 & 0xffff;
  if (*(int *)(&DAT_004f1e40 + uVar1 * 4) != 0) {
    uVar1 = *(uint *)(**(int **)(*(int *)(&DAT_004f1e40 + uVar1 * 4) + 8) + 0xc4);
    local_8 = *(undefined2 *)(uVar1 + 0x32);
  }
  return CONCAT22((short)(uVar1 >> 0x10),local_8);
}

