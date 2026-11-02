/* FUN_0043cfe0 @ 0043cfe0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043cfe0(void)

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
  FUN_0043a060((float *)&DAT_004f5b20);
  _DAT_004f5b2c = DAT_004bcc88;
  _DAT_004f5b3c = DAT_004bcc8c;
  _DAT_004f5b4c = DAT_004bcc90;
  FUN_0043a1c0((float *)&DAT_004f5b20);
  uStack_8 = 0x43d055;
  __chkesp();
  return;
}

