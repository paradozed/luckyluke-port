/* FUN_00419930 @ 00419930 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00419930(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 local_54 [16];
  undefined2 *local_14;
  byte *local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = FUN_00407580(param_1);
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = (int)sVar1;
  *(short *)(*(int *)(local_c + 8) + 0x18) = sVar1;
  local_10 = (byte *)**(undefined4 **)(local_c + 8);
  if ((*local_10 & 2) != 0) {
    FUN_0047f140(local_10);
    *(undefined1 *)(local_c + 0x11) = 1;
    *(code **)(local_c + 4) = FUN_0047aae0;
    *(undefined1 *)(local_c + 0x10) = 1;
    FUN_004164e0(local_c,0);
  }
  local_14 = (undefined2 *)(DAT_004e8820 + *(int *)(DAT_004e8820 + 4 + local_8 * 4));
  if (*(int *)(local_10 + 0xc4) != 0) {
    sVar1 = FUN_00418fb0(local_14);
    *(short *)(*(int *)(local_10 + 0xc4) + 0x32) = sVar1 + -1;
  }
  uVar6 = 1;
  uVar5 = 1;
  uVar4 = 0;
  sVar1 = FUN_00418fb0(local_14);
  FUN_004850b0((int)local_10,(int)local_14,sVar1 + -1,uVar4,uVar5,uVar6);
  FUN_00418fe0((int)local_10,0);
  local_8 = 0x419a44;
  __chkesp();
  return;
}

