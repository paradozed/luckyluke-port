/* FUN_004562f0 @ 004562f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004562f0(int param_1,int param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [17];
  undefined4 uStack_8;
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  *(short *)(param_1 + 0x20) =
       (short)**(undefined4 **)(param_2 + 8) - (short)**(undefined4 **)(param_2 + 4);
  *(short *)(param_1 + 0x22) =
       (short)*(undefined4 *)(*(int *)(param_2 + 8) + 4) -
       (short)*(undefined4 *)(*(int *)(param_2 + 4) + 4);
  *(short *)(param_1 + 0x24) =
       (short)*(undefined4 *)(*(int *)(param_2 + 8) + 8) -
       (short)*(undefined4 *)(*(int *)(param_2 + 4) + 8);
  *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(param_1 + 0x48) = 0;
  sVar1 = FUN_004836a0((int)*(short *)(param_1 + 0x24),(int)*(short *)(param_1 + 0x20));
  *(short *)(param_1 + 0x58) = sVar1 + 0x400;
  *(ushort *)(param_1 + 0x58) = *(ushort *)(param_1 + 0x58) & 0xfff;
  uVar2 = FUN_004836a0((int)*(short *)(param_1 + 0x22),(int)*(short *)(param_1 + 0x26));
  *(undefined2 *)(param_1 + 0x5a) = uVar2;
  *(undefined4 *)(param_1 + 0x28) = **(undefined4 **)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(*(int *)(param_2 + 4) + 4);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(*(int *)(param_2 + 4) + 8);
  *(int *)(param_1 + 0x14) = param_2;
  uStack_8 = 0x456404;
  __chkesp();
  return;
}

