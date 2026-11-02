/* FUN_004126d0 @ 004126d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004126d0(void *param_1,void *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_004074b0(param_2,4);
  uVar2 = FUN_004074b0(param_2,3);
  DAT_004f1578 = FUN_00475910(2,uVar2,uVar1);
  local_8 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar1 = FUN_004074b0(param_2,2);
  *(undefined2 *)(local_8 + 3) = uVar1;
  local_8[1] = FUN_00475ba0;
  *(undefined1 *)(local_8 + 4) = 1;
  *local_8 = FUN_00475b80;
  *(undefined1 *)((int)local_8 + 0x11) = 1;
  local_8[2] = DAT_004f1578;
  FUN_00412c50(param_1,local_8);
  FUN_00412ee0(param_1,FUN_004759f0);
  local_8 = (undefined4 *)0x412782;
  __chkesp();
  return;
}

