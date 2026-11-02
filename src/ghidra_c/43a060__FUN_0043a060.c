/* FUN_0043a060 @ 0043a060 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043a060(float *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_84 [16];
  float local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_84;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00439da0(param_1);
  FUN_00439e40(local_44);
  FUN_00439f80(local_44,(int)local_44,(int)param_1);
  FUN_00439ee0(param_1);
  FUN_00439f80(param_1,(int)local_44,(int)param_1);
  uStack_8 = 0x43a0e3;
  __chkesp();
  return;
}

