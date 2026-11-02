/* FUN_0041d240 @ 0041d240 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041d240(undefined4 param_1,void *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_48 [16];
  int local_8;
  
  puVar6 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  if ((DAT_004e866c != '\x01') &&
     (sVar1 = FUN_004074b0(param_2,2), *(int *)(&DAT_004f1e40 + sVar1 * 4) != 0)) {
    sVar1 = FUN_004074b0(param_2,2);
    local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
    if ((local_8 != DAT_004f2b68) &&
       (sVar1 = FUN_004074b0(param_2,2),
       *(int *)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8) != DAT_004f2458)) {
      DAT_004f2b6c = DAT_004f2b6c + DAT_004f2bec;
      DAT_004f2b7c = DAT_004f2b7c + DAT_004f2bec;
      DAT_004f2bec = 0;
    }
    DAT_004f2b68 = local_8;
    DAT_004f2b62 = FUN_004074b0(param_2,2);
    sVar1 = FUN_004074b0(param_2,7);
    uVar4 = (uint)sVar1;
    sVar1 = FUN_004074b0(param_2,6);
    iVar5 = (int)sVar1;
    sVar1 = FUN_004074b0(param_2,5);
    uVar2 = (uint)sVar1;
    sVar1 = FUN_004074b0(param_2,4);
    iVar3 = (int)sVar1;
    sVar1 = FUN_004074b0(param_2,3);
    FUN_00454d50(sVar1,iVar3,uVar2,iVar5,uVar4);
  }
  local_8 = 0x41d36b;
  __chkesp();
  return;
}

