/* FUN_00466af0 @ 00466af0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00466af0(void)

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
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) & 0xffffe1ff;
  FUN_00466900();
  uStack_8 = 0x466b2e;
  __chkesp();
  return;
}

