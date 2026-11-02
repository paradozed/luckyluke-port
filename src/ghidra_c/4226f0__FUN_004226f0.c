/* FUN_004226f0 @ 004226f0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004226f0(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_7c [29];
  void *local_8;
  
  puVar3 = local_7c;
  for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = param_1;
  piVar1 = (int *)FUN_004228e0(param_1,0);
  FUN_004220e0(*piVar1);
  local_8 = (void *)0x42272b;
  __chkesp();
  return;
}

