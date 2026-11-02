/* FUN_00499260 @ 00499260 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00499260(char *param_1,byte *param_2)

{
  code *pcVar1;
  int iVar2;
  char *local_24;
  size_t local_20;
  char *local_1c;
  undefined4 local_18;
  
  if ((param_1 == (char *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4bb018,0x42,0,(byte *)"string != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if ((param_2 == (byte *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4bb018,0x43,0,(byte *)"format != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  local_18 = 0x49;
  local_1c = param_1;
  local_24 = param_1;
  local_20 = _strlen(param_1);
  iVar2 = FUN_004a2710((int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  return iVar2;
}

