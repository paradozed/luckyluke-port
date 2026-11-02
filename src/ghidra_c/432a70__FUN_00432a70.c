/* FUN_00432a70 @ 00432a70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00432a70(char *param_1,uint *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_14 = (uint)*(ushort *)(DAT_004d1e78 + param_3 * 4);
  local_8 = (uint)*(ushort *)(DAT_004d1e7c + 0xe + local_14 * 0x14);
  local_c = (int)*(short *)(DAT_004d1e7c + local_14 * 0x14) << 2;
  local_10 = (int)*(short *)(DAT_004d1e7c + 2 + local_14 * 0x14);
  FUN_00432510(param_1,param_2,local_8,local_c,local_10);
  local_8 = 0x432b03;
  __chkesp();
  return;
}

