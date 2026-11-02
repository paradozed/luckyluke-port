/* FUN_00426d60 @ 00426d60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00426d60(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  uint local_1c;
  uint local_18;
  uint local_14;
  char local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00497d20(&DAT_004f7ea0,0xe,1,param_1);
  FUN_00497d20(&DAT_004f7ec0,0x28,1,param_1);
  local_18 = DAT_004f7ec4 << 1;
  local_8 = (undefined4 *)FUN_00494840(local_18);
  if (local_8 != (undefined4 *)0x0) {
    local_c = (undefined4 *)(param_2 + (DAT_004f7ec8 - 1) * local_18);
    for (local_14 = 0; local_14 < DAT_004f7ec8; local_14 = local_14 + 1) {
      FUN_00497690(local_8,local_c,local_18);
      for (local_1c = 0; local_1c < local_18; local_1c = local_1c + 2) {
        if ((*(byte *)((int)local_8 + local_1c + 1) & 0x80) == 0) {
          local_e = 0;
          local_f = 0;
          local_10 = '\0';
        }
        else {
          local_e = 0xff;
          local_f = 0xff;
          local_10 = -1;
        }
        FUN_00497d20(&local_10,3,1,param_1);
      }
      local_c = (undefined4 *)((int)local_c - local_18);
    }
    FUN_00495280(local_8);
  }
  local_8 = (undefined4 *)0x426ea3;
  __chkesp();
  return;
}

