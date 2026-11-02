/* FUN_004223c0 @ 004223c0 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall
FUN_004223c0(void *this,int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_4c [16];
  int local_c;
  undefined4 *local_8;
  
  puVar1 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_8 = this;
  iVar2 = FUN_00422810(this,param_1);
  if (iVar2 != 0) {
    local_c = 0;
    while (iVar2 = FUN_00422920(local_8), local_c < iVar2) {
      puVar1 = (undefined4 *)FUN_004228e0(local_8,local_c);
      *puVar1 = 0;
      local_c = local_c + 1;
    }
    DAT_004d28a0 = param_2;
    DAT_004d28a4 = param_3;
    DAT_004d28a8 = param_4;
  }
  local_8 = (undefined4 *)0x422450;
  __chkesp();
  return;
}

