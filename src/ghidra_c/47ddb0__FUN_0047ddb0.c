/* FUN_0047ddb0 @ 0047ddb0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_0047ddb0(int param_1,int param_2,int param_3)

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
  local_8 = param_1;
  if (DAT_004be3d4 == 0x19) {
    local_8 = (param_1 + param_2 + param_3) / 3;
  }
  else {
    if (param_1 < param_2) {
      local_8 = param_2;
    }
    if (local_8 < param_3) {
      local_8 = param_3;
    }
  }
  return local_8;
}

