/* FUN_0040f220 @ 0040f220 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040f220(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_6c [16];
  undefined1 local_2c [32];
  int local_c;
  int local_8;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,3);
  local_c = (int)sVar1;
  FUN_004074b0(param_2,4);
  FUN_00497080(local_2c,0x4b4060);
  (*DAT_004e8a2c)(local_8,local_c,local_2c);
  __chkesp();
  local_8 = 0x40f2a2;
  __chkesp();
  return;
}

