/* FUN_0042cf30 @ 0042cf30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042cf30(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (undefined4 *)FUN_00439a90(DAT_004e85ec,(*(int *)(param_1 + 0x10) + param_2) * 8);
  FUN_00497690(local_8,*(undefined4 **)(*(int *)(param_1 + 0x20) + 4),*(int *)(param_1 + 0x10) << 3)
  ;
  *(undefined4 **)(*(int *)(param_1 + 0x20) + 4) = local_8;
  local_8 = (undefined4 *)0x42cfa0;
  __chkesp();
  return;
}

