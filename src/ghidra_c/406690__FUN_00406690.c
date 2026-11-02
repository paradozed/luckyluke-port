/* FUN_00406690 @ 00406690 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00406690(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d8 [52];
  undefined4 uStack_8;
  
  puVar2 = local_d8;
  for (iVar1 = 0x35; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  EnumDisplaySettingsA((LPCSTR)0x0,0xffffffff,(DEVMODEA *)(local_d8 + 0x10));
  __chkesp();
  uStack_8 = 0x4066e7;
  __chkesp();
  return;
}

