/* FUN_00450b00 @ 00450b00 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00450b00(void)

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
  FUN_00466510(9,FUN_00450ac0);
  FUN_0041f5e0(2,0xc,0,0x1194,0,'\0');
  DAT_004f23f8 = FUN_00450b60;
  FUN_00450b60();
  uStack_8 = 0x450b5a;
  __chkesp();
  return;
}

