/* FUN_0048bce0 @ 0048bce0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0048bce0(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; local_8 = param_3, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = local_8 + -1, -1 < local_8) {
    FUN_0048b850(param_2,param_4,param_6,local_8);
  }
  local_8 = 0x48bd39;
  __chkesp();
  return;
}

