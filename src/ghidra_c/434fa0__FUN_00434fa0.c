/* FUN_00434fa0 @ 00434fa0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00434fa0(void)

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
  DAT_004f5b74 = (HINSTANCE)FUN_00445840();
  DialogBoxParamA(DAT_004f5b74,(LPCSTR)0x6c,(HWND)0x0,FUN_00434d30,0);
  __chkesp();
  uStack_8 = 0x434fef;
  __chkesp();
  return;
}

