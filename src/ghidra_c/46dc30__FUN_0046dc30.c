/* FUN_0046dc30 @ 0046dc30 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046dc30(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [18];
  uint local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = DAT_004f228c;
  if (DAT_004f228c == 0) {
    local_8 = *DAT_004f2288;
  }
  while (local_8 != 0) {
    if (*(int *)(local_8 + 0x10) == 1) {
      local_c = *(uint *)(local_8 + 0xc);
      _DAT_004e885c = local_c & 7;
      _DAT_004e8900 = 0;
      DAT_004e8904 = DAT_004e8904 + 1;
      FUN_0046dbe0(local_c);
    }
    DAT_004f228c = *(int *)(local_8 + 4);
    local_8 = DAT_004f228c;
  }
  local_8 = 0x46dcca;
  __chkesp();
  return;
}

