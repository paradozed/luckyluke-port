/* FUN_00439b50 @ 00439b50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439b50(PVOID param_1,DWORD *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  _PROCESS_HEAP_ENTRY local_24;
  undefined4 *local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = DAT_004e84e8;
  do {
    if (local_8 == (undefined4 *)0x0) {
      *param_2 = 0xffffffff;
LAB_00439bc9:
      local_8 = (undefined4 *)0x439bd6;
      __chkesp();
      return;
    }
    local_24.lpData = (PVOID)0x0;
    while( true ) {
      HeapWalk((HANDLE)*local_8,&local_24);
      iVar1 = __chkesp();
      if (iVar1 == 0) break;
      if (local_24.lpData == param_1) {
        *param_2 = local_24.cbData;
        goto LAB_00439bc9;
      }
    }
    local_8 = (undefined4 *)local_8[1];
  } while( true );
}

