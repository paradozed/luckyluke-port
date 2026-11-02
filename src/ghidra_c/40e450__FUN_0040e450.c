/* FUN_0040e450 @ 0040e450 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040e450(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = local_8 & 0xffff0000;
  sVar1 = FUN_004074b0(param_2,2);
  local_c = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  local_10 = **(undefined4 **)(local_c + 8);
  local_8 = 0x40e4b2;
  __chkesp();
  return;
}

