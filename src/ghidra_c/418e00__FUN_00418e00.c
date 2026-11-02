/* FUN_00418e00 @ 00418e00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418e00(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = FUN_00407580(param_1);
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = (int)sVar1;
  local_10 = FUN_00418da0(local_8);
  local_c = FUN_00407580(param_1);
  local_8 = 0x418e5a;
  __chkesp();
  return;
}

