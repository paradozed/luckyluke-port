/* FUN_00420cd0 @ 00420cd0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00420cd0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1;
  FUN_00420eb0(param_1);
  local_8 = 0x420d02;
  __chkesp();
  return;
}

