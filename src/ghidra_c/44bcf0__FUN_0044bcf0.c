/* FUN_0044bcf0 @ 0044bcf0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044bcf0(void)

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
  DAT_004bd044 = 0;
  while ((&DAT_004f2c80)[DAT_004e8608 * 3] != 0) {
    (&DAT_004f2c88)[DAT_004e8608 * 0xc] = 1;
    (*(code *)(&DAT_004f2c80)[DAT_004e8608 * 3])((&DAT_004f2c84)[DAT_004e8608 * 3]);
    __chkesp();
    (&DAT_004f2c80)[DAT_004e8608 * 3] = 0;
    (&DAT_004f2c84)[DAT_004e8608 * 3] = 0;
    (&DAT_004f2c88)[DAT_004e8608 * 0xc] = 0;
    DAT_004e8608 = DAT_004e8608 + 1;
    if (DAT_004e8608 == 0x20) {
      DAT_004e8608 = 0;
    }
    DAT_004e860c = DAT_004e860c + -1;
  }
  DAT_004bd044 = 1;
  uStack_8 = 0x44bddc;
  __chkesp();
  return;
}

