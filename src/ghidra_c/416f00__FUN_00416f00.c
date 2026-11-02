/* FUN_00416f00 @ 00416f00 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00416f00(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  _DAT_004be028 = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,3);
  _DAT_004be038 = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,4);
  _DAT_004be048 = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,5);
  _DAT_004be058 = (int)sVar1;
  uStack_8 = 0x416f6f;
  __chkesp();
  return;
}

