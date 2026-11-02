/* FUN_00418460 @ 00418460 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418460(void *param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_5c [16];
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  puVar4 = local_5c;
  for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_8 = CONCAT22(local_8._2_2_,sVar1);
  local_c = FUN_0046e8d0((int)sVar1);
  local_10 = *(undefined4 *)(*(int *)(local_c + 8) + 4);
  sVar1 = FUN_004074b0(param_2,4);
  local_14 = FUN_004867c0((ushort)local_10,sVar1);
  local_18 = (undefined4 *)FUN_00417f30(local_14);
  local_1c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar2 = FUN_004074b0(param_2,2);
  FUN_00417fb0(local_1c,local_18,uVar2);
  *(undefined1 *)((int)local_1c + 0x11) = 0;
  *(undefined1 *)((int)local_1c + 0x12) = 1;
  *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_1c + 3) * 4) = local_1c;
  FUN_00412c50(param_1,local_1c);
  FUN_00412ee0(param_1,FUN_00417d40);
  FUN_0047f0f0((byte *)*local_18);
  uVar2 = FUN_004074b0(param_2,4);
  FUN_004856f0((byte *)*local_18,local_c,0,0,CONCAT22(extraout_var,uVar2));
  local_8 = 0x418572;
  __chkesp();
  return;
}

