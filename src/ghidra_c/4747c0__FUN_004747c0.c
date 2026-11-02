/* FUN_004747c0 @ 004747c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004747c0(void)

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
  if (DAT_004f1800 == '\0') {
    DAT_004f1674 = FUN_00474540;
    FUN_00474540();
  }
  uStack_8 = 0x4747ff;
  __chkesp();
  return;
}

