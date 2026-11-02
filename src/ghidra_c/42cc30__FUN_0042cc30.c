/* FUN_0042cc30 @ 0042cc30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042cc30(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  char *local_10;
  int local_c;
  uint local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  for (local_8 = 0; local_8 < DAT_004e85a4; local_8 = local_8 + 1) {
    if (*(int *)(DAT_004d1e74 + 0x14 + local_8 * 0x18) == param_1) {
      local_10 = (char *)(DAT_004d1e74 + local_8 * 0x18);
      break;
    }
  }
  local_8 = 0;
  do {
    if (DAT_004e85a4 <= local_8) {
LAB_0042cd15:
      local_8 = 0x42cd22;
      __chkesp();
      return;
    }
    iVar1 = _strcmp((char *)(DAT_004d1e74 + local_8 * 0x18),local_10);
    if (iVar1 == 0) {
      if (*(int *)(DAT_004d1e74 + 0x14 + local_8 * 0x18) == param_1) {
        (*DAT_004e8a2c)(10,100,"Selected object/instance: %s, %d",local_10,local_c);
        __chkesp();
        goto LAB_0042cd15;
      }
      local_c = local_c + 1;
    }
    local_8 = local_8 + 1;
  } while( true );
}

