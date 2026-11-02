/* FUN_0046d570 @ 0046d570 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046d570(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_0044ce10(5);
  local_8 = CONCAT31(local_8._1_3_,(char)uVar1);
  if (((uVar1 & 0xff) != (uint)DAT_004f22a0) && ((uVar1 & 0xff) == 4)) {
    FUN_0041f5e0(5,9,0,0x8fc,0x400,'\0');
  }
  if ((((DAT_004e8859 != '\0') && (DAT_004f2458 != (int *)0x0)) && (*DAT_004f2458 != 0)) &&
     (*(int *)(*DAT_004f2458 + 0x94) == 0)) {
    DAT_004e8858 = 1;
    FUN_0046d520();
  }
  DAT_004f22a0 = (undefined1)local_8;
  local_8 = 0x46d623;
  __chkesp();
  return;
}

