/* FUN_0046bb80 @ 0046bb80 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046bb80(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_14 = *(undefined4 *)(*DAT_004f2458 + 0x90);
  local_10 = *(int *)(*DAT_004f2458 + 0x94);
  local_c = *(undefined4 *)(*DAT_004f2458 + 0x98);
  FUN_0046a6e0(DAT_004f2458 + 0x2d,DAT_004f2458 + 0x2e,(int *)&DAT_004be0b0);
  local_10 = local_10 + DAT_004f2458[0x2e];
  FUN_00467730(*DAT_004f2458,local_14,local_10,local_c);
  if (((DAT_004f29ac == '\0') && (**(char **)(*(int *)(*DAT_004f2458 + 0xe4) + 0x14) == '\x04')) &&
     (iVar2 = FUN_00457510(*(int *)(*DAT_004f2458 + 0xe4)), iVar2 <= local_10)) {
    uVar1 = FUN_0041ff20();
    if (((uVar1 & 0xff) == 1) && ((DAT_004f2458[4] & 0x100U) == 0)) {
      FUN_0041f5e0(2,6,100,0xfff,0x400,'\0');
      FUN_0041f5e0(3,8,500,5000,0x800,'\0');
    }
  }
  else if ((DAT_004f2458[4] & 0x20U) != 0) {
    DAT_004f23f8 = FUN_0046b2a0;
    FUN_0046b2a0();
  }
  uStack_8 = 0x46bce6;
  __chkesp();
  return;
}

