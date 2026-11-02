/* FUN_004519e0 @ 004519e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004519e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  short local_c [2];
  undefined4 uStack_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00451950(&DAT_004e8644);
  FUN_00451860(DAT_004e8644,'\x01');
  local_c[0] = DAT_004e8644;
  FUN_004518e0(local_c);
  FUN_00451860(local_c[0],'\x01');
  FUN_004518e0(local_c);
  FUN_00451860(local_c[0],'\0');
  FUN_004518e0(local_c);
  FUN_00451860(local_c[0],'\0');
  if (DAT_004e866a == 0x28c) {
    DAT_004e8644 = DAT_004bd5d2 + 0x9e;
    DAT_004e864a = 0xffff;
  }
  uStack_8 = 0x451aa9;
  __chkesp();
  return;
}

