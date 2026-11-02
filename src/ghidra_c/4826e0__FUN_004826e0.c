/* FUN_004826e0 @ 004826e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004826e0(short *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00482820((undefined4 *)&DAT_00508840,param_1,param_2);
  *param_2 = *param_2 + DAT_00508854;
  param_2[1] = param_2[1] + DAT_00508858;
  param_2[2] = param_2[2] + DAT_0050885c;
  uStack_8 = 0x48274e;
  __chkesp();
  return;
}

