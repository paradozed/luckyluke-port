/* FUN_00435e10 @ 00435e10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00435e10(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  for (local_8 = 0; local_8 < param_2; local_8 = local_8 + 1) {
    *(byte *)(param_1 + local_8) = *(byte *)(param_1 + local_8) ^ *(byte *)(param_3 + local_c);
    local_c = (uint)(byte)((ulonglong)(local_c + 1) % (ulonglong)(longlong)(int)(param_4 & 0xff));
  }
  return;
}

