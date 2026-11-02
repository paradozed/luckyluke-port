/* FUN_004678c0 @ 004678c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004678c0(void)

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
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) & 0xfffbffff;
  *(int *)(DAT_004f2458 + 0xb4) = (int)DAT_004bddf8;
  DAT_004f2400 = FUN_00465c20;
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) & 0xffffffdf;
  FUN_00466510(0xf,FUN_00467620);
  DAT_004f23f8 = FUN_00467660;
  FUN_00467660();
  uStack_8 = 0x46794b;
  __chkesp();
  return;
}

