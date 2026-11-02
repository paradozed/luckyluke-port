/* FUN_00451d70 @ 00451d70 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00451d70(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [16];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != 0) {
    local_14 = *(int *)(param_1 + 0x90);
    local_10 = *(undefined4 *)(param_1 + 0x94);
    local_c = *(undefined4 *)(param_1 + 0x98);
    FUN_00482760((undefined4 *)&DAT_00508180,&local_14,&local_24);
    local_24 = local_24 + _DAT_004f2b40;
    local_20 = local_20 + _DAT_004f2b44;
    local_1c = local_1c + DAT_004f2b48;
    if (local_1c < 100) {
      local_1c = 100;
    }
    local_28 = (DAT_004bdaac << 0xc) / local_1c;
    *param_2 = local_24 * local_28 >> 0xc;
    *param_3 = local_20 * local_28 >> 0xc;
    *param_2 = *param_2 + 0x100;
    *param_3 = *param_3 + 0x80;
  }
  uStack_8 = 0x451e57;
  __chkesp();
  return;
}

