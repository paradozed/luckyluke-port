/* FUN_004374d0 @ 004374d0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004374d0(void)

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
  if (DAT_004e84b4 == (int *)0x0) {
    uVar3 = FUN_00497360();
    if (3000 < (int)uVar3 - _DAT_004e84bc) {
      DAT_004bcb80 = 0;
    }
  }
  else {
    FUN_00436ff0((int)DAT_004e84b4);
    DAT_004e84b4[4] = DAT_004e84b4[4] + -1;
    if (((uint)(DAT_004e84b4[4] + *DAT_004e84b4) < 0x118) &&
       (DAT_004e84b4[4] = 0x244, DAT_004e84b8 != '\0')) {
      DAT_004bcb80 = 0;
    }
  }
  uStack_8 = 0x437583;
  __chkesp();
  return;
}

