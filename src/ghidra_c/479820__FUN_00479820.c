/* FUN_00479820 @ 00479820 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00479820(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004bc738 = 1;
  if ((*(char *)(DAT_004e89f0 + 2 + param_1 * 0x20) == '\0') &&
     (*(char *)(DAT_004e89f0 + 3 + param_1 * 0x20) == '\0')) {
    FUN_00478510(param_1);
    FUN_004796e0(param_1);
  }
  uStack_8 = 0x479893;
  __chkesp();
  return;
}

