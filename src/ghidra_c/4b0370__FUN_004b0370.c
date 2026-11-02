/* FUN_004b0370 @ 004b0370 */
/* decompiled from Lucky.exe (Game.run) */


bool __fastcall FUN_004b0370(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x14))
                    (param_2,&stack0x00000014,param_1,&stack0x00000004,0x1000000,0);
  if (iVar1 != 0) {
    FUN_004b0969((uint *)s_goW95CopyScreen___IDirectDrawSur_004c8668,iVar1);
  }
  return iVar1 == 0;
}

