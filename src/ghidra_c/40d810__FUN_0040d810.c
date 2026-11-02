/* FUN_0040d810 @ 0040d810 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0040d810(int *param_1,int *param_2)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [16];
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (param_1[3] < *param_2) {
    uVar1 = (uint)param_2 & 0xffff0000;
  }
  else if (param_2[3] < *param_1) {
    uVar1 = (uint)param_2 & 0xffff0000;
  }
  else if (param_1[4] < param_2[1]) {
    uVar1 = (uint)param_2 & 0xffff0000;
  }
  else if (param_2[4] < param_1[1]) {
    uVar1 = (uint)param_2 & 0xffff0000;
  }
  else if (param_1[5] < param_2[2]) {
    uVar1 = (uint)param_2 & 0xffff0000;
  }
  else {
    uVar2 = (ushort)((uint)param_2 >> 0x10);
    if (param_2[5] < param_1[2]) {
      uVar1 = (uint)uVar2 << 0x10;
    }
    else {
      uVar1 = CONCAT22(uVar2,1);
    }
  }
  return uVar1;
}

