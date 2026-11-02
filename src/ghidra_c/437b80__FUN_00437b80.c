/* FUN_00437b80 @ 00437b80 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00437b80(void)

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
  FUN_00437fa0();
  DAT_004e84d4 = (undefined4 *)FUN_00494c40(8,1);
  if (DAT_004e84d4 == (undefined4 *)0x0) {
    FUN_004383a0();
    FUN_00437ad0();
  }
  else {
    DAT_004e84d4[1] = 0;
    *DAT_004e84d4 = 0;
    iVar1 = FUN_00496e40(0x437ad0);
    if (iVar1 == 0) {
      DAT_004e84c8 = 1;
    }
    else {
      FUN_004383a0();
      FUN_00437ad0();
    }
  }
  uStack_8 = 0x437c22;
  __chkesp();
  return;
}

