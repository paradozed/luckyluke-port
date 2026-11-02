/* FUN_00415a60 @ 00415a60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415a60(void *param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [16];
  undefined4 *local_c;
  undefined4 local_8;
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_8 = FUN_00446390(sVar1);
  DAT_004bd6b0 = 1;
  local_c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)(local_c + 3) = uVar2;
  *local_c = FUN_004490f0;
  local_c[1] = FUN_00449200;
  *(undefined1 *)(local_c + 4) = 1;
  *(undefined1 *)((int)local_c + 0x11) = 1;
  local_c[2] = local_8;
  FUN_00412c50(param_1,local_c);
  FUN_00412ee0(param_1,0);
  local_8 = 0x415b04;
  __chkesp();
  return;
}

