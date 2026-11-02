/* FUN_0045f5f0 @ 0045f5f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045f5f0(void)

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
  if (DAT_004f272c != (HHOOK)0x0) {
    UnhookWindowsHookEx(DAT_004f272c);
    __chkesp();
    DAT_004f272c = (HHOOK)0x0;
  }
  uStack_8 = 0x45f63d;
  __chkesp();
  return;
}

