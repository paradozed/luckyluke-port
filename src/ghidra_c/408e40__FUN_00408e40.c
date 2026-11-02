/* FUN_00408e40 @ 00408e40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00408e40(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_58 [16];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_18 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_14 = *(undefined4 *)(local_18 + 0x90);
  local_10 = *(undefined4 *)(local_18 + 0x94);
  local_c = *(undefined4 *)(local_18 + 0x98);
  uStack_8 = 0x408eb0;
  __chkesp();
  return;
}

