/* FUN_0040f720 @ 0040f720 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040f720(undefined4 param_1,void *param_2)

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
  _DAT_004e85d8 = sVar1 * 1000;
  sVar1 = FUN_004074b0(param_2,3);
  _DAT_004e85dc = sVar1 * 1000;
  sVar1 = FUN_004074b0(param_2,4);
  _DAT_004e85e0 = sVar1 * 1000;
  uStack_8 = 0x40f793;
  __chkesp();
  return;
}

