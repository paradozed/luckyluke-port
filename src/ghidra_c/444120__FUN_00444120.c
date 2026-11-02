/* FUN_00444120 @ 00444120 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_00444120(short *param_1,short *param_2)

{
  uint uVar1;
  uint3 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [16];
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if ((int)*param_2 < (int)*param_1 + (int)param_1[2]) {
    if ((int)param_2[1] < (int)param_1[1] + (int)param_1[3]) {
      if ((int)*param_1 < (int)*param_2 + (int)param_2[2]) {
        uVar2 = (uint3)((uint)param_1 >> 8);
        if ((int)param_1[1] < (int)param_2[1] + (int)param_2[3]) {
          uVar1 = CONCAT31(uVar2,1);
        }
        else {
          uVar1 = (uint)uVar2 << 8;
        }
      }
      else {
        uVar1 = (uint)(uint3)(int3)(char)((ushort)*param_1 >> 8) << 8;
      }
    }
    else {
      uVar1 = (int)param_1[1] + (int)param_1[3] & 0xffffff00;
    }
  }
  else {
    uVar1 = (int)*param_1 + (int)param_1[2] & 0xffffff00;
  }
  return uVar1;
}

