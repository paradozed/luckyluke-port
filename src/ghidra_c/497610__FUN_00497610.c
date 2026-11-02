/* FUN_00497610 @ 00497610 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00497610(byte *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 == (byte *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4baec8,0x36,0,(byte *)"format != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  iVar2 = FUN_0049f740((undefined4 *)&DAT_004c7280);
  iVar3 = FUN_0049dba0((int *)&DAT_004c7280,param_1,(undefined4 *)&stack0x00000008);
  FUN_0049f8a0(iVar2,(int *)&DAT_004c7280);
  return iVar3;
}

