/* FUN_00439af0 @ 00439af0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439af0(SIZE_T param_1)

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
  if (DAT_004e84e4 != (undefined4 *)0x0) {
    HeapAlloc((HANDLE)*DAT_004e84e4,8,param_1);
    __chkesp();
  }
  local_8 = 0x439b46;
  __chkesp();
  return;
}

