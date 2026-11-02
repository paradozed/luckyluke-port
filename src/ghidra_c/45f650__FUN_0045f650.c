/* FUN_0045f650 @ 0045f650 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045f650(void)

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
  RegisterHotKey((HWND)0x0,0x1234,0,0x1b);
  __chkesp();
  uStack_8 = 0x45f68f;
  __chkesp();
  return;
}

