/* FUN_00446150 @ 00446150 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00446150(undefined4 *param_1,undefined4 param_2,char param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  uint local_c;
  undefined4 local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_3 == '\0') {
    *(byte *)((int)param_1 + 0x13) = *(byte *)((int)param_1 + 0x13) & 0xfd;
    bVar1 = *(byte *)((int)param_1 + 0x13);
  }
  else {
    *(byte *)((int)param_1 + 0x13) = *(byte *)((int)param_1 + 0x13) | 2;
    bVar1 = *(byte *)((int)param_1 + 0x13);
  }
  local_c = (uint)bVar1;
  local_8 = *param_1;
  FUN_00426640();
  *param_1 = local_8;
  local_8 = 0x4461fe;
  __chkesp();
  return;
}

