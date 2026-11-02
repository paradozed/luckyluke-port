/* FUN_004b02fd @ 004b02fd */
/* decompiled from Lucky.exe (Game.run) */


bool __fastcall FUN_004b02fd(int *param_1)

{
  undefined4 local_6c [20];
  undefined4 local_1c;
  int local_8;
  
  local_6c[0] = 100;
  local_1c = 0;
  local_8 = (**(code **)(*param_1 + 0x14))(param_1,0,0,0,0x1000400,local_6c);
  if (local_8 != 0) {
    FUN_004b0969((uint *)s_goW95ClearScreen___IDirectDrawSu_004c8638,local_8);
  }
  return local_8 == 0;
}

