/* FUN_004399f0 @ 004399f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004399f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    if (param_1 == DAT_004e84e8) {
      DAT_004e84e8 = (undefined4 *)param_1[1];
    }
    else {
      for (local_8 = DAT_004e84e8; (undefined4 *)local_8[1] != param_1;
          local_8 = (undefined4 *)local_8[1]) {
      }
      local_8[1] = *(undefined4 *)(local_8[1] + 4);
    }
    HeapDestroy((HANDLE)*param_1);
    __chkesp();
    FUN_00495280(param_1);
  }
  local_8 = (undefined4 *)0x439a86;
  __chkesp();
  return;
}

