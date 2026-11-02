/* FUN_00476fe0 @ 00476fe0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00476fe0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_a8 [16];
  int local_68;
  int local_64;
  int local_60;
  int local_58;
  int local_54;
  int local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_a8;
  for (iVar1 = 0x29; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != 0) {
    local_14 = *(int *)(param_1 + 0x90);
    local_10 = *(undefined4 *)(param_1 + 0x94);
    local_c = *(undefined4 *)(param_1 + 0x98);
    FUN_00482760((undefined4 *)&DAT_00508180,&local_14,&local_34);
    local_58 = local_34 + _DAT_004f2b40 + *(int *)(param_1 + 0xa4);
    local_54 = local_30 + _DAT_004f2b44 + *(int *)(param_1 + 0xa8);
    local_50 = local_2c + DAT_004f2b48 + *(int *)(param_1 + 0xac);
    if (local_50 == 0) {
      local_50 = 1;
    }
    iVar1 = (DAT_004bdaac << 0xc) / local_50;
    local_68 = local_34 + _DAT_004f2b40 + *(int *)(param_1 + 0xb0);
    local_64 = local_30 + _DAT_004f2b44 + *(int *)(param_1 + 0xb4);
    local_60 = local_2c + DAT_004f2b48 + *(int *)(param_1 + 0xb8);
    if (local_60 == 0) {
      local_60 = 1;
    }
    local_38 = (DAT_004bdaac << 0xc) / local_60;
    local_3c = (local_58 * iVar1 >> 0xc) + 0x100;
    local_40 = (local_54 * iVar1 >> 0xc) + 0x80;
    local_44 = (local_68 * local_38 >> 0xc) + 0x100;
    local_48 = (local_64 * local_38 >> 0xc) + 0x80;
    *param_2 = local_3c;
    param_2[1] = local_40;
    param_2[2] = local_44;
    param_2[3] = local_48;
  }
  uStack_8 = 0x47718d;
  __chkesp();
  return;
}

