/* FUN_00477ed0 @ 00477ed0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00477ed0(short param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = local_8 & 0xffff0000;
  do {
    if ((uint)*DAT_004f13a0 <= (local_8 & 0xffff)) {
LAB_00477f81:
      local_8 = 0x477f8e;
      __chkesp();
      return;
    }
    if (**(short **)(DAT_004f13a0 + (local_8 & 0xffff) * 2 + 2) == param_1) {
      if (*(int *)(*(int *)(DAT_004f13a0 + (local_8 & 0xffff) * 2 + 2) + 4) < 1) {
        FUN_00477d80(DAT_004f13a0,*(void **)(DAT_004f13a0 + (local_8 & 0xffff) * 2 + 2));
      }
      goto LAB_00477f81;
    }
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  } while( true );
}

