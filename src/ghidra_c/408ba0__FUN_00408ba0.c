/* FUN_00408ba0 @ 00408ba0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00408ba0(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_64 [16];
  undefined2 local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  puVar3 = local_64;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_18 = FUN_00407580(param_1);
  local_1c = **(int **)(local_18 + 8);
  sVar1 = FUN_004074b0(param_2,2);
  local_20 = sVar1 * 100;
  sVar1 = FUN_004074b0(param_2,3);
  local_24 = (undefined2)((sVar1 * DAT_004e89e4) / (int)(DAT_004be2e5 + 1));
  local_14 = *(undefined4 *)(local_1c + 0x90);
  local_10 = *(undefined4 *)(local_1c + 0x94);
  local_c = *(int *)(local_1c + 0x98);
  FUN_00408820(local_14,local_10,local_c,local_8,local_20,local_1c,
               CONCAT22((short)((uint)local_10 >> 0x10),local_24));
  local_8 = 0x408c69;
  __chkesp();
  return;
}

