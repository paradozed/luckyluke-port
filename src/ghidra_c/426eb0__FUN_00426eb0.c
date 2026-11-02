/* FUN_00426eb0 @ 00426eb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00426eb0(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  uint local_14;
  uint local_10;
  undefined4 *local_c;
  char *local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_00497d20(&DAT_004f7ea0,0xe,1,param_1);
  if ((uVar1 == 1) && (uVar1 = FUN_00497d20(&DAT_004f7ec0,0x28,1,param_1), uVar1 == 1)) {
    local_14 = DAT_004f7ec4 * 3;
    local_8 = (char *)FUN_00494840(local_14);
    if (local_8 != (char *)0x0) {
      local_c = (undefined4 *)(param_2 + (DAT_004f7ec8 - 1) * local_14);
      for (local_10 = 0; local_10 < DAT_004f7ec8; local_10 = local_10 + 1) {
        FUN_00497690((undefined4 *)local_8,local_c,local_14);
        uVar1 = FUN_00497d20(local_8,local_14,1,param_1);
        if (uVar1 != 1) {
          FUN_00495280(local_8);
          goto LAB_00426fbc;
        }
        local_c = (undefined4 *)((int)local_c - local_14);
      }
      FUN_00495280(local_8);
    }
  }
LAB_00426fbc:
  local_8 = (char *)0x426fc9;
  __chkesp();
  return;
}

