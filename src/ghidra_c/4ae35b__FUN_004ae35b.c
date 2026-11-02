/* FUN_004ae35b @ 004ae35b */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __fastcall FUN_004ae35b(int param_1)

{
  int *piVar1;
  
  FUN_004ae2ce();
  piVar1 = FUN_004afe20(param_1,DAT_0050ab24);
  if (piVar1 != (int *)0x0) {
    FUN_004ae418(0x56,1,FUN_004ae3fb);
    FUN_004ae418(0x56,3,FUN_004ae406);
    DAT_0050a2f0 = piVar1;
    DAT_0050a2f4 = piVar1;
    _DAT_0050a2f8 = piVar1;
    DAT_0050a2fc = piVar1;
    FUN_004ae3fb();
  }
  return piVar1 != (int *)0x0;
}

