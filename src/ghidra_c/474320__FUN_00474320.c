/* FUN_00474320 @ 00474320 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00474320(undefined4 *param_1)

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
  if (*(char *)((int)param_1 + 0x11) != '\0') {
    (*(code *)*param_1)(param_1);
    __chkesp();
  }
  FUN_00473c50();
  param_1[1] = FUN_00473c50;
  DAT_004e89a3 = 0;
  DAT_004f1668 = 0;
  DAT_004e89a6 = 0;
  DAT_004e89a2 = 0;
  DAT_004f1758 = 0;
  DAT_004e89a5 = 0;
  DAT_004e89a4 = 0;
  DAT_004f1800 = 0;
  DAT_004e89a7 = 0;
  DAT_004f16a8 = 0;
  DAT_004e89a8 = 0;
  uStack_8 = 0x4743c9;
  __chkesp();
  return;
}

