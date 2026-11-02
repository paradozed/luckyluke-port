/* FUN_00439c30 @ 00439c30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439c30(PVOID param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  DWORD local_c;
  undefined4 *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (undefined4 *)FUN_00439b50(param_1,&local_c);
  if (local_8 != (undefined4 *)0x0) {
    HeapFree((HANDLE)*local_8,0,param_1);
    __chkesp();
  }
  local_8 = (undefined4 *)0x439c8b;
  __chkesp();
  return;
}

