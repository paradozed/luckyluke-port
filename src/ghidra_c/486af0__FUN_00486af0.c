/* FUN_00486af0 @ 00486af0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00486af0(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_78 [16];
  short local_38 [2];
  undefined2 local_34;
  undefined4 uStack_8;
  
  puVar2 = local_78;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_34 = param_3;
  FUN_00486820(param_2,local_38);
  FUN_004869e0(param_2,(int)local_38,(undefined2 *)(param_1 + 0x5c));
  uStack_8 = 0x486b44;
  __chkesp();
  return;
}

