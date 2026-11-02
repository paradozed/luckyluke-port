/* FUN_00463730 @ 00463730 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463730(void)

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
  DAT_004f23b8 = 0;
  DAT_004e87ac = DAT_004e87ac - _DAT_004e87b0;
  if ((int)(short)DAT_004e87ac < (int)(uint)DAT_004e87b2) {
    DAT_004e87ac = DAT_004e87b2;
  }
  DAT_004e87e8 = DAT_004e87e8 - _DAT_004e87ec;
  if ((int)(short)DAT_004e87e8 < (int)(uint)DAT_004e87ee) {
    DAT_004e87e8 = DAT_004e87ee;
  }
  DAT_004e87fc = DAT_004e87fc - _DAT_004e8800;
  if ((int)(short)DAT_004e87fc < (int)(uint)DAT_004e8802) {
    DAT_004e87fc = DAT_004e8802;
  }
  DAT_004f23f8 = FUN_00462ff0;
  FUN_00462ff0();
  uStack_8 = 0x46380e;
  __chkesp();
  return;
}

