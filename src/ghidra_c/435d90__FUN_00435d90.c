/* FUN_00435d90 @ 00435d90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00435d90(char *param_1)

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
  if (param_1 != (char *)0x0) {
    if (*(int *)(param_1 + 0x24) != 0) {
      FUN_00497b30(*(int **)(param_1 + 0x24));
    }
    if (*param_1 != '\0') {
      FUN_00495280(*(void **)(param_1 + 0x34));
      FUN_00495280(*(void **)(param_1 + 0x38));
    }
  }
  uStack_8 = 0x435dfe;
  __chkesp();
  return;
}

