/* FUN_0049d1c0 @ 0049d1c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0049d1c0(char *param_1)

{
  char cVar1;
  uint uVar2;
  uint local_10;
  char local_c;
  
  uVar2 = FUN_004a5fa0((int)*param_1);
  if (uVar2 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_004c71e8 < 2) {
        local_10 = *(ushort *)(PTR_DAT_004c6fdc + *param_1 * 2) & 4;
      }
      else {
        local_10 = FUN_0049c240((int)*param_1,4);
      }
    } while (local_10 != 0);
  }
  local_c = *param_1;
  *param_1 = DAT_004c71ec;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = local_c;
    local_c = cVar1;
  } while (*param_1 != '\0');
  return;
}

