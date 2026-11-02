/* FUN_00414f30 @ 00414f30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00414f30(void *param_1,void *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 extraout_var;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_4c [16];
  undefined4 *local_c;
  undefined4 local_8;
  
  puVar5 = local_4c;
  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  uVar1 = FUN_004074b0(param_2,5);
  uVar2 = FUN_004074b0(param_2,4);
  uVar3 = FUN_004074b0(param_2,3);
  local_8 = FUN_0046f7f0(CONCAT22(extraout_var,uVar3),uVar2,uVar1);
  local_c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar3 = FUN_004074b0(param_2,2);
  *(undefined2 *)(local_c + 3) = uVar3;
  *local_c = FUN_0046fc40;
  local_c[1] = FUN_0046fd90;
  *(undefined1 *)(local_c + 4) = 1;
  *(undefined1 *)((int)local_c + 0x11) = 1;
  local_c[2] = local_8;
  *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_c + 3) * 4) = local_c;
  FUN_00412c50(param_1,local_c);
  FUN_00412ee0(param_1,FUN_00470010);
  local_8 = 0x414ff9;
  __chkesp();
  return;
}

