/* FUN_00482fb0 @ 00482fb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00482fb0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1[2] == 0) {
    *param_2 = DAT_004be3dc * *param_1 + DAT_004e8aa8;
    *param_3 = DAT_004be3e0 * param_1[1] + DAT_004e8aac;
  }
  else {
    *param_2 = (DAT_004be3dc * *param_1) / param_1[2] + DAT_004e8aa8;
    *param_3 = (DAT_004be3e0 * param_1[1]) / param_1[2] + DAT_004e8aac;
  }
  return;
}

