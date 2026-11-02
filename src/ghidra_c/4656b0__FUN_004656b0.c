/* FUN_004656b0 @ 004656b0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004656b0(byte *param_1,int param_2)

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
  local_8 = 0xffffffff;
  while (param_2 != 0) {
    local_8 = *(uint *)(&DAT_004b81fc + ((local_8 ^ *param_1) & 0xff) * 4) ^ local_8 >> 8;
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  }
  return local_8;
}

