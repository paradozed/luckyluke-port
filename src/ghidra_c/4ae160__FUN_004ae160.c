/* FUN_004ae160 @ 004ae160 */
/* decompiled from Lucky.exe (Game.run) */


int __fastcall FUN_004ae160(char *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FID_conflict___open(param_1,*(uint *)(&DAT_004c7ec8 + param_2 * 4) | 0x8000,
                              *(undefined4 *)(&DAT_004c7ed8 + param_2 * 4));
  return iVar1 + 1;
}

