/* FUN_00439a90 @ 00439a90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439a90(undefined4 *param_1,SIZE_T param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    HeapAlloc((HANDLE)*param_1,8,param_2);
    __chkesp();
  }
  local_8 = 0x439ae0;
  __chkesp();
  return;
}

