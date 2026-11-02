/* FUN_004589e0 @ 004589e0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004589e0(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((*param_1 < *param_2) || (param_2[3] < param_1[3])) {
    uVar1 = (uint)param_2 & 0xffffff00;
  }
  else if ((param_1[2] < param_2[2]) || (param_2[5] < param_1[5])) {
    uVar1 = (uint)param_2 & 0xffffff00;
  }
  else if ((param_1[4] < param_2[1]) || (param_2[4] < param_1[1])) {
    uVar1 = (uint)param_2 & 0xffffff00;
  }
  else {
    uVar1 = CONCAT31((int3)((uint)param_2 >> 8),1);
  }
  return uVar1;
}

