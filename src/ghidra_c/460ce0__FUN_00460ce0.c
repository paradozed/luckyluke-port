/* FUN_00460ce0 @ 00460ce0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00460ce0(void)

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
  FUN_0045f940(0xf,FUN_00460c60);
  DAT_004f2598 = FUN_00460d30;
  FUN_00460d30();
  uStack_8 = 0x460d23;
  __chkesp();
  return;
}

