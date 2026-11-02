/* FUN_0043c390 @ 0043c390 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043c390(int *param_1,int param_2)

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
  if (param_1 != (int *)0x0) {
    iVar1 = FUN_00494c40(param_2 * 0xc,1);
    param_1[4] = iVar1;
    if (param_1[4] != 0) {
      iVar1 = FUN_00494c40(param_2 * 0xc,1);
      param_1[3] = iVar1;
      if (param_1[3] != 0) {
        iVar1 = FUN_00494c40(param_2 * 0xc,1);
        param_1[2] = iVar1;
        if (param_1[2] != 0) {
          *param_1 = param_2;
        }
      }
    }
  }
  uStack_8 = 0x43c438;
  __chkesp();
  return;
}

