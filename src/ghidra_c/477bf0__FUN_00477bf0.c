/* FUN_00477bf0 @ 00477bf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00477bf0(ushort *param_1,short param_2,int param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  short *local_c;
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 == (ushort *)0x0) {
    FUN_00497610((byte *)"Failed File: %s Line:%d\n");
  }
  else {
    local_8 = local_8 & 0xffff0000;
    while ((local_8 & 0xffff) < (uint)*param_1) {
      if (**(short **)(param_1 + (local_8 & 0xffff) * 2 + 2) == param_2) {
        **(short **)(param_1 + (local_8 & 0xffff) * 2 + 2) = param_2;
        *(int *)(*(int *)(param_1 + (local_8 & 0xffff) * 2 + 2) + 4) = param_3 << 0x10;
        *(undefined1 *)(*(int *)(param_1 + (local_8 & 0xffff) * 2 + 2) + 8) = param_4;
        *(undefined1 *)(*(int *)(param_1 + (local_8 & 0xffff) * 2 + 2) + 9) = 1;
        goto LAB_00477d69;
      }
      local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
    }
    local_c = (short *)FUN_00494c40(0xc,1);
    if (local_c == (short *)0x0) {
      FUN_00497610((byte *)"Failed File: %s Line:%d\n");
    }
    else {
      *local_c = param_2;
      *(int *)(local_c + 2) = param_3 << 0x10;
      *(undefined1 *)(local_c + 4) = param_4;
      *(undefined1 *)((int)local_c + 9) = 1;
      *(short **)(param_1 + (uint)*param_1 * 2 + 2) = local_c;
      *param_1 = *param_1 + 1;
    }
  }
LAB_00477d69:
  local_8 = 0x477d76;
  __chkesp();
  return;
}

