/* FUN_00420080 @ 00420080 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00420080(void)

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
  if ((DAT_004bcfd0 != 0) && (DAT_004d2884 != '\0')) {
    DAT_004d1f1f = 0;
    DAT_004d1f1d = 0;
    FUN_00497610((byte *)"Stopping CD\n");
    FUN_00403c10();
  }
  uStack_8 = 0x4200db;
  __chkesp();
  return;
}

