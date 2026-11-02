/* FUN_0042c770 @ 0042c770 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042c770(byte *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar3 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar2 = DAT_004be3c8 >> 1;
  iVar1 = FUN_0042c4d0((char *)param_1);
  local_8 = uVar2 - iVar1 / 2;
  iVar1 = FUN_0042c5c0(param_1);
  local_c = (DAT_004be3cc - iVar1) + -10;
  FUN_0042c280(local_8,local_c,param_1);
  local_8 = 0x42c7e1;
  __chkesp();
  return;
}

