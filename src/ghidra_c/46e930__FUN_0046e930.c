/* FUN_0046e930 @ 0046e930 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e930(int *param_1,uint param_2,undefined2 param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined4 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = *(int *)(*param_1 + (uint)*(ushort *)(param_1 + 1) * 4);
  *(short *)(param_1 + 1) = (short)param_1[1] + 1;
  local_c = FUN_0046e8d0(param_2 & 0xffff);
  uVar5 = 0;
  uVar4 = 1;
  uVar1 = FUN_0046e9d0(local_c);
  FUN_0046e7d0(*(undefined2 **)(local_8 + 4),local_c,CONCAT22(extraout_var,param_3),0,
               (ushort)(byte)((char)uVar1 - 1),uVar4,uVar5);
  local_8 = 0x46e9cb;
  __chkesp();
  return;
}

