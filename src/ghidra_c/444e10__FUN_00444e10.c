/* FUN_00444e10 @ 00444e10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00444e10(int *param_1,char param_2)

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
  if ((param_1 != (int *)0x0) && (param_2 != (char)param_1[1])) {
    FUN_00444790(param_1);
    FUN_00444aa0(param_1,param_2);
  }
  uStack_8 = 0x444e75;
  __chkesp();
  return;
}

