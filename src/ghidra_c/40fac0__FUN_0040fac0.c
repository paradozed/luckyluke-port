/* FUN_0040fac0 @ 0040fac0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040fac0(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 local_58 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_00407580(param_1);
  sVar1 = FUN_004074b0(param_2,2);
  local_c = (int)sVar1;
  *(undefined4 *)(&DAT_004d1e14 + local_c * 0x10) = **(undefined4 **)(local_8 + 8);
  uVar4 = FUN_00497360();
  local_10 = (int)uVar4;
  *(float *)(&DAT_004d1e08 + local_c * 0x10) = (float)local_10 / _DAT_004b40d4;
  sVar1 = FUN_004074b0(param_2,3);
  local_14 = (int)sVar1;
  *(float *)(&DAT_004d1e0c + local_c * 0x10) = (float)local_14;
  sVar1 = FUN_004074b0(param_2,4);
  local_18 = sVar1 * 100;
  *(float *)(&DAT_004d1e10 + local_c * 0x10) = (float)local_18;
  local_8 = 0x40fb76;
  __chkesp();
  return;
}

