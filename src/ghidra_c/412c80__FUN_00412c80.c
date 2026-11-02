/* FUN_00412c80 @ 00412c80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00412c80(void *param_1,void *param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_60 [16];
  undefined4 *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  puVar4 = local_60;
  for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_c = FUN_0046e8d0((int)sVar1);
  local_10 = *(undefined4 *)(*(int *)(local_c + 8) + 4);
  sVar1 = FUN_004074b0(param_2,2);
  local_14 = FUN_0046e8d0((int)sVar1);
  local_18 = *(undefined4 *)(*(int *)(local_14 + 8) + 4);
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    uVar2 = FUN_00486410((ushort)local_10,0x10);
    *(undefined4 *)(&DAT_004f13c4 + local_8 * 0x2c) = uVar2;
    FUN_0047f0f0(*(byte **)(&DAT_004f13c4 + local_8 * 0x2c));
    FUN_00485a70(*(byte **)(&DAT_004f13c4 + local_8 * 0x2c),local_c,(ushort)local_10,0,0,0,0,0x10);
    uVar2 = FUN_00486410((ushort)local_18,0x10);
    *(undefined4 *)(&DAT_004f13c0 + local_8 * 0x2c) = uVar2;
    FUN_0047f0f0(*(byte **)(&DAT_004f13c0 + local_8 * 0x2c));
    FUN_00485a70(*(byte **)(&DAT_004f13c0 + local_8 * 0x2c),local_14,(ushort)local_18,0,0,0,0,0x10);
    FUN_00411000(*(int *)(&DAT_004f13c0 + local_8 * 0x2c),(undefined4 *)&DAT_004bc490);
    *(undefined2 *)(&DAT_004f13c8 + local_8 * 0x2c) = 0;
    *(undefined2 *)(&DAT_004f13ca + local_8 * 0x2c) = 0;
    *(undefined4 *)(&DAT_004f13d0 + local_8 * 0x2c) = 0;
    *(undefined4 *)(&DAT_004f13d4 + local_8 * 0x2c) = 0;
    *(undefined4 *)(&DAT_004f13d8 + local_8 * 0x2c) = 0;
    *(undefined2 *)(&DAT_004f13e0 + local_8 * 0x2c) = 0;
    for (local_1c = 0; local_1c < 5; local_1c = local_1c + 1) {
      *(undefined2 *)(&DAT_004f13e2 + local_1c * 2 + local_8 * 0x2c) = 0;
    }
  }
  local_20 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  local_20[1] = FUN_00476060;
  *(undefined1 *)(local_20 + 4) = 1;
  *local_20 = FUN_00476620;
  *(undefined1 *)((int)local_20 + 0x11) = 1;
  local_20[2] = &DAT_004f13c0;
  DAT_004f16c4 = FUN_00476680;
  DAT_004f16c0 = FUN_00476940;
  FUN_00412c50(param_1,local_20);
  FUN_00412ee0(param_1,FUN_00476960);
  local_8 = 0x412ece;
  __chkesp();
  return;
}

