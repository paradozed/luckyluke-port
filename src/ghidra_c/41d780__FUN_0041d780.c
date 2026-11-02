/* FUN_0041d780 @ 0041d780 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041d780(void *param_1,void *param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [16];
  undefined4 *local_c;
  int local_8;
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_004074b0(param_2,3);
  local_8 = FUN_0041d710(uVar1);
  local_c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)(local_c + 3) = uVar2;
  local_c[1] = FUN_0041d840;
  *(undefined1 *)(local_c + 4) = 1;
  *local_c = 0;
  *(undefined1 *)((int)local_c + 0x11) = 0;
  local_c[2] = local_8;
  *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_c + 3) * 4) = local_c;
  *(undefined1 *)(local_8 + 2) = 0;
  FUN_00412c50(param_1,local_c);
  FUN_00412ee0(param_1,FUN_0041d8c0);
  local_8 = 0x41d83a;
  __chkesp();
  return;
}

