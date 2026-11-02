/* FUN_00478400 @ 00478400 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00478400(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_00497360();
  _DAT_004e89dc = ((int)uVar3 * 0x3c) / 1000;
  DAT_004e89da = DAT_004e89dc;
  uStack_8 = 0x478448;
  __chkesp();
  return;
}

