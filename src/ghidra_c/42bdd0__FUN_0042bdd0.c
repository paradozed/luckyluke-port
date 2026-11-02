/* FUN_0042bdd0 @ 0042bdd0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042bdd0(undefined4 *param_1,undefined4 *param_2,uint param_3,LPCSTR param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  va_list local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8318 = 1;
  local_c = &stack0x00000014;
  wvsprintfA(&DAT_004f7660,param_4,local_c);
  __chkesp();
  local_c = (va_list)0x0;
  FUN_00497690(param_1,param_2,param_3);
  DAT_004e8318 = 0;
  local_8 = 0x42be4c;
  __chkesp();
  return;
}

