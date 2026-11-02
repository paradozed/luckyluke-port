/* FUN_0045f4e0 @ 0045f4e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045f4e0(int param_1,WPARAM param_2,LPARAM param_3)

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
  if (param_2 != 0x1b) {
    if (param_1 == 0) {
      CallNextHookEx(DAT_004f272c,0,param_2,param_3);
      __chkesp();
    }
    else {
      CallNextHookEx(DAT_004f272c,param_1,param_2,param_3);
      __chkesp();
    }
  }
  uStack_8 = 0x45f55a;
  __chkesp();
  return;
}

