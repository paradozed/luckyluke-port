/* FUN_00439cd0 @ 00439cd0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439cd0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  _PROCESS_HEAP_ENTRY local_20;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while( true ) {
    HeapWalk((HANDLE)*param_1,&local_20);
    iVar1 = __chkesp();
    if (iVar1 == 0) break;
    HeapFree((HANDLE)*param_1,0,local_20.lpData);
    __chkesp();
  }
  local_20.u.Region.lpLastBlock = (LPVOID)0x439d2f;
  __chkesp();
  return;
}

