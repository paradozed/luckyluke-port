/* FUN_0045f560 @ 0045f560 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045f560(void)

{
  HINSTANCE hmod;
  int iVar1;
  undefined4 *puVar2;
  DWORD dwThreadId;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8590 == 0) {
    dwThreadId = 0;
    hmod = (HINSTANCE)FUN_00445840();
    SetWindowsHookExA(2,FUN_0045f4e0,hmod,dwThreadId);
    DAT_004f272c = __chkesp();
    if (DAT_004f272c == 0) {
      FUN_00458ec0();
    }
    FUN_00458ec0();
  }
  else {
    FUN_00458ec0();
  }
  uStack_8 = 0x45f5e3;
  __chkesp();
  return;
}

