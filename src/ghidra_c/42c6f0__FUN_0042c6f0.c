/* FUN_0042c6f0 @ 0042c6f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042c6f0(byte *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_0042c4d0((char *)param_1);
  local_8 = (DAT_004be3c8 - iVar1) + -10;
  iVar1 = FUN_0042c5c0(param_1);
  local_c = (DAT_004be3cc - iVar1) + -10;
  FUN_0042c280(local_8,local_c,param_1);
  local_8 = 0x42c75d;
  __chkesp();
  return;
}

