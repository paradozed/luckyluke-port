/* FUN_0040bac0 @ 0040bac0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl
FUN_0040bac0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8)

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
  if (param_3 < param_5) {
    uVar1 = param_5 & 0xffffff00;
  }
  else {
    uVar2 = (uint3)((uint)param_5 >> 8);
    if (param_7 < param_1) {
      uVar1 = (uint)uVar2 << 8;
    }
    else if (param_4 < param_6) {
      uVar1 = (uint)uVar2 << 8;
    }
    else {
      uVar2 = (uint3)((uint)param_8 >> 8);
      if (param_8 < param_2) {
        uVar1 = (uint)uVar2 << 8;
      }
      else {
        uVar1 = CONCAT31(uVar2,1);
      }
    }
  }
  return uVar1;
}

