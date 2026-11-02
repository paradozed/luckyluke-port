/* FUN_004268b0 @ 004268b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004268b0(int *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_50 [16];
  uint local_10;
  undefined4 *local_c;
  char *local_8;
  
  puVar4 = local_50;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = FUN_00497d20(&DAT_004f7ea0,0xe,1,param_1);
  if ((((uVar2 == 1) && (uVar2 = FUN_00497d20(&DAT_004f7ec0,0x28,1,param_1), uVar2 == 1)) &&
      (cVar1 = FUN_004269f0(param_1), cVar1 != '\0')) &&
     (local_8 = (char *)FUN_00494840(DAT_004f7ec4), local_8 != (char *)0x0)) {
    local_c = (undefined4 *)(param_2 + (DAT_004f7ec8 - 1) * DAT_004f7ec4);
    for (local_10 = 0; local_10 < DAT_004f7ec8; local_10 = local_10 + 1) {
      FUN_00497690((undefined4 *)local_8,local_c,DAT_004f7ec4);
      uVar2 = FUN_00497d20(local_8,DAT_004f7ec4,1,param_1);
      if (uVar2 != 1) {
        FUN_00495280(local_8);
        goto LAB_004269d9;
      }
      local_c = (undefined4 *)((int)local_c - DAT_004f7ec4);
    }
    FUN_00495280(local_8);
  }
LAB_004269d9:
  local_8 = (char *)0x4269e6;
  __chkesp();
  return;
}

