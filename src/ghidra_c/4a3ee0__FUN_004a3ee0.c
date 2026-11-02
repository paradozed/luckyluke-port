/* FUN_004a3ee0 @ 004a3ee0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004a3ee0(void)

{
  size_t sVar1;
  int iVar2;
  int *local_10;
  int local_c;
  uint *local_8;
  
  if (DAT_0050a2ac == 0) {
    FUN_004a9710();
  }
  local_c = 0;
  for (local_8 = DAT_004e8cc0; (char)*local_8 != '\0'; local_8 = (uint *)((int)local_8 + sVar1 + 1))
  {
    if ((char)*local_8 != '=') {
      local_c = local_c + 1;
    }
    sVar1 = _strlen((char *)local_8);
  }
  local_10 = (int *)FUN_00494860(local_c * 4 + 4,2,0x4bb51c,0x6d);
  DAT_004e8c8c = local_10;
  if (local_10 == (int *)0x0) {
    __amsg_exit(9);
  }
  for (local_8 = DAT_004e8cc0; (char)*local_8 != '\0'; local_8 = (uint *)((int)local_8 + sVar1 + 1))
  {
    sVar1 = _strlen((char *)local_8);
    if ((char)*local_8 != '=') {
      iVar2 = FUN_00494860(sVar1 + 1,2,0x4bb51c,0x79);
      *local_10 = iVar2;
      if (*local_10 == 0) {
        __amsg_exit(9);
      }
      FUN_00497270((uint *)*local_10,local_8);
      local_10 = local_10 + 1;
    }
  }
  FUN_004952a0(DAT_004e8cc0,2);
  DAT_004e8cc0 = (uint *)0x0;
  *local_10 = 0;
  DAT_0050a2a8 = 1;
  return;
}

