/* FUN_004279c0 @ 004279c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004279c0(undefined *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_294 [16];
  int local_254;
  int local_250;
  HANDLE local_24c;
  _WIN32_FIND_DATAA local_248;
  uint local_108 [64];
  undefined4 uStack_8;
  
  puVar2 = local_294;
  for (iVar1 = 0xa4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_250 = 0;
  local_254 = 1;
  DAT_004e8314 = 0;
  FUN_00458ec0();
  FUN_00497270(local_108,(uint *)&DAT_004e56d0);
  FUN_00497280(local_108,(uint *)"\\drivers\\*.w3x");
  FUN_00458ec0();
  DAT_004e2b68 = 0;
  DAT_004e8300 = 0;
  FindFirstFileA((LPCSTR)local_108,&local_248);
  local_24c = (HANDLE)__chkesp();
  if (local_24c != (HANDLE)0x0) {
    while (local_254 != 0) {
      local_250 = local_250 + 1;
      if (param_1 != (undefined *)0x0) {
        (*(code *)param_1)(&local_248);
        __chkesp();
      }
      FindNextFileA(local_24c,&local_248);
      local_254 = __chkesp();
    }
    FindClose(local_24c);
    __chkesp();
    if (DAT_004e8314 != 0) {
      (*(code *)param_1)(DAT_004e8314);
      __chkesp();
    }
    if (DAT_004e8300 != 0) {
      FUN_00497270((uint *)&DAT_004e2966,DAT_004f5dcc);
      FUN_00497270(&DAT_004e2944,(uint *)"windowed.w3x");
      DAT_004e2940 = 0x57696e64;
      puVar2 = &DAT_004e2940;
      puVar3 = &DAT_004e57d8 + (uint)DAT_004e2b68 * 0x8a;
      for (iVar1 = 0x8a; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      DAT_004e2b68 = DAT_004e2b68 + 1;
      local_250 = local_250 + 1;
    }
  }
  uStack_8 = 0x427bae;
  __chkesp();
  return;
}

