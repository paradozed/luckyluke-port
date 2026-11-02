/* FUN_0040d8b0 @ 0040d8b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040d8b0(int *param_1,int *param_2)

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
  if ((*param_2 <= param_1[3]) && (*param_1 <= param_2[3])) {
    FUN_004975e0(param_2[4] - param_1[1]);
  }
  uStack_8 = 0x40d942;
  __chkesp();
  return;
}

