/* FUN_00461920 @ 00461920 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00461920(void)

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
  FUN_0041f5e0(2,0xe,0,10000,0x400,'\0');
  FUN_0045f940(5,FUN_004618f0);
  DAT_004f2598 = FUN_00461990;
  FUN_00461990();
  uStack_8 = 0x46197d;
  __chkesp();
  return;
}

