/* FUN_00496d90 @ 00496d90 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00496d90(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  
  uVar1 = FUN_004956b0((int)DAT_0050a2b4,2);
  if (uVar1 < (uint)((int)DAT_0050a2b0 + (4 - (int)DAT_0050a2b4))) {
    iVar5 = 0x68;
    pcVar4 = "onexit.c";
    uVar1 = 2;
    iVar2 = FUN_004956b0((int)DAT_0050a2b4,2);
    piVar3 = __realloc_dbg(DAT_0050a2b4,iVar2 + 0x10,uVar1,(int)pcVar4,iVar5);
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    DAT_0050a2b0 = piVar3 + ((int)DAT_0050a2b0 - (int)DAT_0050a2b4 >> 2);
    DAT_0050a2b4 = piVar3;
  }
  *DAT_0050a2b0 = param_1;
  DAT_0050a2b0 = DAT_0050a2b0 + 1;
  return param_1;
}

