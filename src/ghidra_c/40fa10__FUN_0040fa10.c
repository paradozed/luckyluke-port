/* FUN_0040fa10 @ 0040fa10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040fa10(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_5c [16];
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = FUN_00407580(param_1);
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  local_14 = **(int **)(local_c + 8);
  local_10 = **(int **)(local_8 + 8);
  local_1c = *(undefined4 *)(local_14 + 0x94);
  local_18 = *(undefined4 *)(local_10 + 0x94);
  (*DAT_004e8a2c)(200,400,"Positions: %d",local_18);
  __chkesp();
  local_8 = 0x40fab5;
  __chkesp();
  return;
}

