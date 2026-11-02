/* FUN_00451950 @ 00451950 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00451950(short *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((*(short *)(&DAT_004bd0e8 + ((int)*param_1 + (int)DAT_004e864a) * 8) == DAT_004e866a) ||
     (*(short *)(DAT_004e89f0 + DAT_004e866a * 0x20) == 0)) {
    *param_1 = *param_1 + DAT_004e864a;
  }
  else {
    *param_1 = *param_1 + *(short *)(&DAT_004bd0ea + *param_1 * 8);
  }
  return;
}

