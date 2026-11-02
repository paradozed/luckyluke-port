/* FUN_0046e220 @ 0046e220 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e220(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_64 [16];
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  short *local_14;
  short *local_10;
  short local_c;
  undefined4 local_8;
  
  puVar3 = local_64;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = *(short *)(DAT_004d1e78 + param_1 * 4);
  local_8 = CONCAT22(local_8._2_2_,sVar1);
  local_c = *(short *)(DAT_004d1e78 + param_2 * 4);
  if (sVar1 != local_c) {
    local_10 = (short *)(DAT_004d1e7c + sVar1 * 0x14);
    local_14 = (short *)(DAT_004d1e7c + local_c * 0x14);
    local_20 = (uint)(ushort)local_10[7];
    local_24 = (uint)(ushort)local_14[7];
    local_18 = (int)*local_14;
    local_1c = (int)local_14[1];
    FUN_0046e0f0(local_10,local_20,local_24,local_18,local_1c);
  }
  local_8 = 0x46e2dd;
  __chkesp();
  return;
}

