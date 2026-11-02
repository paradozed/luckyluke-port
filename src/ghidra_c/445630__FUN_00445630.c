/* FUN_00445630 @ 00445630 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00445630(HINSTANCE param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_6c [16];
  WNDCLASSA local_2c;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  CreateSolidBrush(0);
  local_2c.hbrBackground = (HBRUSH)__chkesp();
  LoadCursorA((HINSTANCE)0x0,&DAT_00007f00);
  local_2c.hCursor = (HCURSOR)__chkesp();
  local_2c.hIcon = (HICON)0x0;
  local_2c.hInstance = param_1;
  local_2c.lpfnWndProc = FUN_00445570;
  local_2c.lpszClassName = "Lucky Luke";
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.style = 3;
  RegisterClassA(&local_2c);
  uVar1 = __chkesp();
  if ((uVar1 & 0xffff) != 0) {
    DAT_004e85f4 = param_1;
    CreateWindowExA(0,"Lucky Luke","",0xc40000,0,0,10,10,(HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0);
    DAT_004e85f0 = __chkesp();
  }
  local_2c.lpszClassName = (LPCSTR)0x44572d;
  __chkesp();
  return;
}

