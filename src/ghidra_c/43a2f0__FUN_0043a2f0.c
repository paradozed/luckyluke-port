/* FUN_0043a2f0 @ 0043a2f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043a2f0(float *param_1,float *param_2)

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
  param_1[3] = *param_2;
  param_1[7] = param_2[1];
  param_1[0xb] = param_2[2];
  uStack_8 = 0x43a358;
  __chkesp();
  return;
}

