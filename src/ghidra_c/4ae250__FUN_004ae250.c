/* FUN_004ae250 @ 004ae250 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004ae250(undefined4 param_1,int param_2,int param_3)

{
  tagMSG local_28;
  int local_c;
  undefined4 local_8;
  
  local_c = PeekMessageA(&local_28,(HWND)0x0,0x12,0x12,1);
  local_8 = FUN_004999a0(2,param_2,param_3,0,&DAT_004b8034);
  if (local_c != 0) {
    PostQuitMessage(local_28.wParam);
  }
  return local_8;
}

