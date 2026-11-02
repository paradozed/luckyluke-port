/* FUN_004ae1b0 @ 004ae1b0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004ae1b0(int param_1)

{
  int iVar1;
  int iVar2;
  uint local_c;
  
  iVar1 = param_1 + -0x40c;
  for (local_c = 0; local_c < 0xff; local_c = local_c + 1) {
    if ((*(int *)(iVar1 + local_c * 4) != 0) &&
       (iVar2 = FUN_004b1ae0(*(int *)(iVar1 + local_c * 4)), iVar2 == 0)) {
      do {
        iVar2 = FUN_004ae250(s_goFreeMem_t_>FontDef_i___004c7f14,0x4c7ee8,0x1c);
      } while (iVar2 != 0);
    }
  }
  FUN_004b1ae0(iVar1);
  return;
}

