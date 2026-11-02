/* FUN_00415340 @ 00415340 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415340(void *param_1,void *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_00507f38 == (undefined1 *)0x0) {
    DAT_00507f38 = (undefined1 *)FUN_00494c40(0xc,1);
    *DAT_00507f38 = 0;
    DAT_00507f38[1] = 0;
    DAT_00507f38[2] = 4;
    DAT_00507f38[3] = 0;
    *(undefined2 *)(DAT_00507f38 + 4) = 0x400;
    *(undefined2 *)(DAT_00507f38 + 6) = 0;
    *(undefined2 *)(DAT_00507f38 + 8) = 0;
    *(undefined2 *)(DAT_00507f38 + 10) = 0;
    DAT_005081a0 = 0;
    local_8 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
    uVar1 = FUN_004074b0(param_2,2);
    *(undefined2 *)(local_8 + 3) = uVar1;
    *local_8 = FUN_00415190;
    *(undefined1 *)((int)local_8 + 0x11) = 1;
    *(undefined1 *)(local_8 + 4) = 0;
    local_8[2] = 0;
    FUN_00412c50(param_1,local_8);
    FUN_00412ee0(param_1,FUN_00415280);
  }
  local_8 = (undefined4 *)0x41543b;
  __chkesp();
  return;
}

