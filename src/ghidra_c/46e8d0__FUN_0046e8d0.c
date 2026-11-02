/* FUN_0046e8d0 @ 0046e8d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e8d0(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = DAT_004e8820 + *(int *)(DAT_004e8820 + 4 + param_1 * 4);
  bVar1 = FUN_004852c0(local_8);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00485290(local_8);
  }
  local_8 = 0x46e92a;
  __chkesp();
  return;
}

