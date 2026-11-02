/* FUN_0043a360 @ 0043a360 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043a360(float *param_1,float param_2,float param_3,float param_4)

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
  FUN_0043a060(param_1);
  param_1[3] = param_2;
  param_1[7] = param_3;
  param_1[0xb] = param_4;
  uStack_8 = 0x43a3b8;
  __chkesp();
  return;
}

