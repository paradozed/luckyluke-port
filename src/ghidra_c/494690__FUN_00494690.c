/* FUN_00494690 @ 00494690 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00494690(undefined *param_1)

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
  if (param_1 != (undefined *)0x0) {
    for (local_8 = 0; local_8 < DAT_00508a10; local_8 = local_8 + 1) {
      if (*(char *)(DAT_004e8c44 + 4 + local_8 * 0x14) != '\0') {
        (*(code *)param_1)(DAT_004e8c44 + local_8 * 0x14,
                           *(int *)(DAT_004e8c44 + local_8 * 0x14) + 0x14);
        __chkesp();
      }
    }
  }
  local_8 = 0x49471d;
  __chkesp();
  return;
}

