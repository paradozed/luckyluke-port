/* FUN_00486160 @ 00486160 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00486160(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0xc) = *(undefined1 *)param_2;
    *(undefined1 *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0xd) =
         *(undefined1 *)(param_2 + 1);
    *(char *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0x14) =
         (char)*param_2 + (char)param_2[2];
    *(undefined1 *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0x15) =
         *(undefined1 *)(param_2 + 1);
    *(undefined1 *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0x1c) = *(undefined1 *)param_2;
    *(char *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0x1d) =
         (char)param_2[1] + (char)param_2[3];
    *(char *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0x24) =
         (char)*param_2 + (char)param_2[2];
    *(char *)(*(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4) + 0x25) =
         (char)param_2[1] + (char)param_2[3];
  }
  return;
}

