/* FUN_004289e0 @ 004289e0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004289e0(void)

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
  FUN_00458ec0();
  DAT_004e8584 = 0;
  DAT_004e8588 = 1;
  _DAT_004bcec8 = 1;
  DAT_004be3c8 = 0x280;
  DAT_004be3cc = 0x1e0;
  DAT_004e858c = 0;
  DAT_004e8590 = 0;
  DAT_004e8594 = 0;
  _DAT_004e8598 = 0;
  DAT_004e859c = 0;
  DAT_004bcfcc = 1;
  DAT_004e85a0 = 0;
  DAT_004e85a8 = 0;
  DAT_004bcfd0 = 1;
  _DAT_004bcfd8 = 0x1e;
  _DAT_004bcfdc = 100;
  DAT_004bcfe0 = 0x50;
  DAT_004bcfe4 = 0x50;
  FUN_00458ec0();
  FUN_00443350("win\\config.txt");
  DAT_004f17ea = DAT_004e85ac;
  FUN_00432fe0((uint)DAT_004e85ac);
  FUN_00458ec0();
  FUN_00428600();
  FUN_004279c0(FUN_00427bc0);
  uStack_8 = 0x428b1d;
  __chkesp();
  return;
}

