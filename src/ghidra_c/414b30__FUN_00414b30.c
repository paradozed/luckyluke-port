/* FUN_00414b30 @ 00414b30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00414b30(void *param_1,void *param_2)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  undefined4 *local_c;
  undefined4 local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_004074b0(param_2,3);
  local_8 = FUN_0046e400(CONCAT22(extraout_var,uVar1));
  local_c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar1 = FUN_004074b0(param_2,2);
  *(undefined2 *)(local_c + 3) = uVar1;
  *local_c = FUN_0046ee10;
  *(undefined1 *)(local_c + 4) = 0;
  *(undefined1 *)((int)local_c + 0x11) = 1;
  local_c[2] = local_8;
  FUN_00412c50(param_1,local_c);
  FUN_00412ee0(param_1,FUN_0046e710);
  DAT_004f555c = local_8;
  local_8 = 0x414bcf;
  __chkesp();
  return;
}

