/* FUN_00427420 @ 00427420 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00427420(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8914 == 9) {
    local_c = 9;
  }
  else {
    local_c = 0xd;
  }
  _memset(&DAT_004d28f0,0,0x28);
  DAT_004d28f6 = 0xff;
  DAT_004d28f5 = 0xff;
  DAT_004d28f4 = 0xff;
  _DAT_004d2906 = (undefined2)local_c;
  DAT_004d28fc = 0;
  DAT_004d28fd = 0;
  DAT_004d2904 = 0x50;
  DAT_004d2905 = 0;
  DAT_004d290c = 0;
  DAT_004d290d = 0x50;
  DAT_004d2914 = 0x50;
  DAT_004d2915 = 0x50;
  _memset(&DAT_004d28c0,0,0x28);
  DAT_004d28c6 = 0xff;
  DAT_004d28c5 = 0xff;
  DAT_004d28c4 = 0xff;
  _DAT_004d28d6 = (undefined2)local_c;
  DAT_004d28cc = 0x5a;
  DAT_004d28cd = 0;
  DAT_004d28d4 = 0x96;
  DAT_004d28d5 = 0;
  DAT_004d28dc = 0x5a;
  DAT_004d28dd = 0x46;
  DAT_004d28e4 = 0x96;
  DAT_004d28e5 = 0x46;
  DAT_004bc4f8 = 1;
  uStack_8 = 0x427550;
  __chkesp();
  return;
}

