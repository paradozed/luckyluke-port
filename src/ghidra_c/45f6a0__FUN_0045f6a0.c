/* FUN_0045f6a0 @ 0045f6a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045f6a0(void)

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
  UnregisterHotKey((HWND)0x0,0x1234);
  __chkesp();
  uStack_8 = 0x45f6db;
  __chkesp();
  return;
}

