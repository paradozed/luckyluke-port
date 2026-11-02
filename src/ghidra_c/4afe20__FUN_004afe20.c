/* FUN_004afe20 @ 004afe20 */
/* decompiled from Lucky.exe (Game.run) */


int * __fastcall FUN_004afe20(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_EDI;
  int local_c;
  int *local_8;
  
  if (param_1 == 0) {
    local_c = 0x6400;
  }
  else {
    local_c = param_1 * 0x19;
  }
  local_8 = (int *)FUN_004b1d40(param_2,local_c + 0x18,unaff_EDI);
  if (local_8 == (int *)0x0) {
    OutputDebugStringA(s_ERROR_>_goNewStack___goAllocMem_r_004c8454);
    do {
      iVar1 = FUN_004ae250(s_r______void___0__004c84a4,0x4c8478,0x1d);
    } while (iVar1 != 0);
  }
  if (local_8 != (int *)0x0) {
    local_8[1] = 0;
    *(undefined1 *)(local_8 + 4) = 0;
    *local_8 = (int)(local_8 + 6);
    local_8[2] = local_c;
    local_8[3] = local_c;
    local_8 = local_8 + 6;
  }
  return local_8;
}

