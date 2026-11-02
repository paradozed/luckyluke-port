/* FUN_00433c90 @ 00433c90 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00433c90(HWND param_1)

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
  SetWindowTextA(param_1,DAT_004f5d8c);
  __chkesp();
  SendDlgItemMessageA(param_1,0x413,0x14a,0xffffffff,0x4b4dfc);
  __chkesp();
  SendDlgItemMessageA(param_1,0x413,0x14a,0xffffffff,0x4b4df0);
  __chkesp();
  SendDlgItemMessageA(param_1,0x413,0x14a,0xffffffff,0x4b4de8);
  __chkesp();
  SendDlgItemMessageA(param_1,0x413,0x14a,0xffffffff,0x4b4de0);
  __chkesp();
  SendDlgItemMessageA(param_1,0x413,0x14a,0xffffffff,0x4b4dd4);
  __chkesp();
  SendDlgItemMessageA(param_1,0x413,0x14a,0xffffffff,0x4b4dc8);
  __chkesp();
  SendDlgItemMessageA(param_1,0x413,0x14a,0xffffffff,0x4b4dbc);
  __chkesp();
  SendDlgItemMessageA(param_1,0x413,0x14e,_DAT_004e85ac,0);
  __chkesp();
  uStack_8 = 0x433def;
  __chkesp();
  return;
}

