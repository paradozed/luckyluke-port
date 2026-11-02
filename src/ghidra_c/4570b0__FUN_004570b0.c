/* FUN_004570b0 @ 004570b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004570b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [17];
  undefined4 *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (undefined4 *)FUN_00439a90(DAT_004e85ec,0x60);
  _memset(local_8,0,0x60);
  local_8[2] = FUN_00456130;
  *local_8 = FUN_00457140;
  local_8[1] = FUN_00456130;
  local_8[4] = param_1;
  local_8[5] = *(undefined4 *)(param_1 + 4);
  local_8 = (undefined4 *)0x45712d;
  __chkesp();
  return;
}

