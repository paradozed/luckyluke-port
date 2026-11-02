/* FUN_0046a6e0 @ 0046a6e0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0046a6e0(int *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  undefined4 *puVar4;
  undefined4 local_48 [17];
  
  puVar4 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (*param_1 == *param_3) {
    *param_2 = *param_3 * (DAT_004be2e5 + 1);
    uVar1 = CONCAT31((int3)((uint)param_2 >> 8),1);
  }
  else {
    if (*param_1 < *param_3) {
      *param_2 = 0;
      for (uVar3 = 0; uVar3 <= DAT_004be2e5; uVar3 = uVar3 + 1) {
        *param_1 = *param_1 + param_3[1];
        if (*param_3 <= *param_1) {
          *param_1 = *param_3;
        }
        *param_2 = *param_2 + *param_1;
      }
    }
    uVar1 = *param_1;
    if (*param_3 < (int)uVar1) {
      *param_2 = 0;
      for (uVar3 = 0; uVar1 = (uint)uVar3, uVar1 <= DAT_004be2e5; uVar3 = uVar3 + 1) {
        *param_1 = *param_1 - param_3[1];
        if (*param_1 <= *param_3) {
          *param_1 = *param_3;
        }
        *param_2 = *param_2 + *param_1;
      }
    }
    uVar1 = uVar1 & 0xffffff00;
  }
  return uVar1;
}

