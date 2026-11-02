/* FUN_00457740 @ 00457740 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00457740(int param_1,int param_2,int *param_3)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_64 [17];
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_8;
  
  puVar4 = local_64;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = FUN_00457570(*(int *)(param_2 + 0x10),param_3);
  *(int *)(param_2 + 0x14) = local_8;
  *(short *)(param_2 + 0x20) =
       (short)**(undefined4 **)(local_8 + 8) - (short)**(undefined4 **)(local_8 + 4);
  *(short *)(param_2 + 0x22) =
       (short)*(undefined4 *)(*(int *)(local_8 + 8) + 4) -
       (short)*(undefined4 *)(*(int *)(local_8 + 4) + 4);
  *(short *)(param_2 + 0x24) =
       (short)*(undefined4 *)(*(int *)(local_8 + 8) + 8) -
       (short)*(undefined4 *)(*(int *)(local_8 + 4) + 8);
  *(undefined2 *)(param_2 + 0x26) = *(undefined2 *)(local_8 + 0xc);
  sVar1 = FUN_004836a0((int)*(short *)(param_2 + 0x24),(int)*(short *)(param_2 + 0x20));
  *(short *)(param_2 + 0x58) = sVar1 + 0x400;
  *(ushort *)(param_2 + 0x58) = *(ushort *)(param_2 + 0x58) & 0xfff;
  uVar2 = FUN_004836a0((int)*(short *)(param_2 + 0x22),(int)*(short *)(param_2 + 0x26));
  *(undefined2 *)(param_2 + 0x5a) = uVar2;
  *(undefined4 *)(param_2 + 0x28) = **(undefined4 **)(local_8 + 4);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(*(int *)(local_8 + 4) + 4);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(*(int *)(local_8 + 4) + 8);
  iVar3 = FUN_00457920(param_2,param_3,&local_20);
  *(short *)(param_2 + 0x48) = (short)iVar3;
  if ((*(short *)(param_2 + 0x48) < 0) || (*(short *)(param_2 + 0x26) < *(short *)(param_2 + 0x48)))
  {
    *(undefined2 *)(param_2 + 0x48) = 0;
    local_20 = *(int *)(param_2 + 0x28);
    local_1c = *(undefined4 *)(param_2 + 0x2c);
    local_18 = *(undefined4 *)(param_2 + 0x30);
  }
  FUN_00457ab0(param_1,local_20,param_3[1],local_18);
  *(uint *)(*(int *)(param_2 + 0x18) + 0x10) = *(uint *)(*(int *)(param_2 + 0x18) + 0x10) | 0x20;
  *(uint *)(*(int *)(param_2 + 0x18) + 0x10) =
       *(uint *)(*(int *)(param_2 + 0x18) + 0x10) & 0xfffffff7;
  *(uint *)(param_2 + 0x54) = *(uint *)(param_2 + 0x54) & 0xfffffffe;
  local_8 = 0x45790f;
  __chkesp();
  return;
}

