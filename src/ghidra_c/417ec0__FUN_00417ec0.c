/* FUN_00417ec0 @ 00417ec0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00417ec0(char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  while ((local_8 < DAT_004d1ea8 &&
         (iVar1 = _strcmp(param_1,(char *)(DAT_004d1e74 + local_8 * 0x18)), iVar1 != 0))) {
    local_8 = local_8 + 1;
  }
  local_8 = 0x417f2a;
  __chkesp();
  return;
}

