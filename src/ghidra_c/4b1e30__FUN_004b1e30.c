/* FUN_004b1e30 @ 004b1e30 */
/* decompiled from Lucky.exe (Game.run) */


bool __cdecl FUN_004b1e30(HINSTANCE param_1)

{
  ATOM AVar1;
  WNDCLASSA local_28;
  
  local_28.style = 0xb;
  local_28.lpfnWndProc = (WNDPROC)&LAB_004b1eb0;
  local_28.cbClsExtra = 0;
  local_28.cbWndExtra = 0;
  local_28.hInstance = param_1;
  local_28.hIcon = LoadIconA((HINSTANCE)0x0,&DAT_00007f00);
  local_28.hCursor = LoadCursorA((HINSTANCE)0x0,&DAT_00007f00);
  local_28.hbrBackground = GetStockObject(4);
  local_28.lpszMenuName = (LPCSTR)0x0;
  local_28.lpszClassName = s_LUCKY_004d1c64;
  AVar1 = RegisterClassA(&local_28);
  return AVar1 != 0;
}

