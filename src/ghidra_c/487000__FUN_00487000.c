/* FUN_00487000 @ 00487000 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00487000(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00486ee0(param_1);
  if (*(int *)(param_1 + 0xdc) == 0) {
    *(undefined1 *)(param_1 + 1) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 1) = 4;
  }
  *(undefined ***)(param_1 + 0xd0) = &PTR_FUN_004c6480 + (uint)*(byte *)(param_1 + 1) * 5;
  uStack_8 = 0x487067;
  __chkesp();
  return;
}

