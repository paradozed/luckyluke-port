/* FUN_00477d80 @ 00477d80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00477d80(ushort *param_1,void *param_2)

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
  while ((local_8 & 0xffff) < (uint)*param_1) {
    if (*(void **)(param_1 + (local_8 & 0xffff) * 2 + 2) == param_2) {
      if (param_2 != (void *)0xdddddddd) {
        FUN_00495280(param_2);
      }
      *param_1 = *param_1 - 1;
      *(undefined4 *)(param_1 + (local_8 & 0xffff) * 2 + 2) =
           *(undefined4 *)(param_1 + (uint)*param_1 * 2 + 2);
    }
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  local_8 = 0x477e29;
  __chkesp();
  return;
}

