/* FUN_0044bc50 @ 0044bc50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0044bc50(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((&DAT_004f2c80)[DAT_004e8604 * 3] == 0) {
    (&DAT_004f2c80)[DAT_004e8604 * 3] = param_1;
    (&DAT_004f2c84)[DAT_004e8604 * 3] = param_2;
    (&DAT_004f2c88)[DAT_004e8604 * 0xc] = 0;
    DAT_004e860c = DAT_004e860c + 1;
    DAT_004e8604 = DAT_004e8604 + 1;
    if (DAT_004e8604 == 0x20) {
      DAT_004e8604 = 0;
    }
  }
  return;
}

