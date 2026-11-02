/* FUN_00463560 @ 00463560 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463560(void)

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
  DAT_004e87c0 = DAT_004e87c0 - _DAT_004e87c4;
  if ((int)(short)DAT_004e87c0 < (int)(uint)DAT_004e87c6) {
    DAT_004e87c0 = DAT_004e87c6;
  }
  DAT_004e87d4 = DAT_004e87d4 - _DAT_004e87d8;
  if ((int)(short)DAT_004e87d4 < (int)(uint)DAT_004e87da) {
    DAT_004e87d4 = DAT_004e87da;
  }
  DAT_004f23f8 = FUN_00462ff0;
  FUN_00462ff0();
  uStack_8 = 0x463607;
  __chkesp();
  return;
}

