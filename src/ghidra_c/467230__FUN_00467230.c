/* FUN_00467230 @ 00467230 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00467230(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  DAT_004f2458[4] = DAT_004f2458[4] | 0x20000;
  uVar1 = FUN_00467130(*DAT_004f2458);
  *(undefined2 *)(DAT_004f2458 + 0x29) = uVar1;
  DAT_004f2400 = FUN_00465fe0;
  FUN_00466510(0x1b,FUN_00466fa0);
  DAT_004f23f8 = FUN_00467170;
  FUN_00467170();
  uStack_8 = 0x4672b1;
  __chkesp();
  return;
}

