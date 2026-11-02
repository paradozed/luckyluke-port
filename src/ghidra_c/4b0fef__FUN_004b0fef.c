/* FUN_004b0fef @ 004b0fef */
/* decompiled from Lucky.exe (Game.run) */


bool __fastcall FUN_004b0fef(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x6c))(param_1);
  if (iVar1 != 0) {
    FUN_004b0969((uint *)s_goW95RestoreScreen___IDirectDraw_004c8bfc,iVar1);
  }
  return iVar1 == 0;
}

