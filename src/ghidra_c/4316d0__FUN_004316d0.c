/* FUN_004316d0 @ 004316d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004316d0(void)

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
  FUN_00430d70();
  FUN_00430fa0();
  FUN_004311e0();
  uStack_8 = 0x431704;
  __chkesp();
  return;
}

