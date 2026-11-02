/* FUN_004a1610 @ 004a1610 */
/* decompiled from Lucky.exe (Game.run) */


HANDLE __cdecl FUN_004a1610(int param_1,uint *param_2,int *param_3,int *param_4)

{
  uint *puVar1;
  size_t sVar2;
  byte *pbVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int local_18;
  uint *local_14;
  HANDLE in_stack_fffffff0;
  HANDLE pvVar7;
  uint *local_8;
  
  local_14 = param_2;
  local_8 = (uint *)FUN_004a8060((byte *)param_2,0x5c);
  puVar1 = (uint *)FUN_004a8060((byte *)param_2,0x2f);
  if (puVar1 == (uint *)0x0) {
    if ((local_8 == (uint *)0x0) && (local_8 = FUN_004a7000(param_2,0x3a), local_8 == (uint *)0x0))
    {
      iVar6 = 0xe6;
      pcVar5 = "spawnve.c";
      uVar4 = 2;
      sVar2 = _strlen((char *)param_2);
      local_14 = (uint *)FUN_00494860(sVar2 + 3,uVar4,(int)pcVar5,iVar6);
      if (local_14 == (uint *)0x0) {
        return in_stack_fffffff0;
      }
      FUN_00497270(local_14,(uint *)&DAT_004bb4e0);
      FUN_00497280(local_14,param_2);
      local_8 = (uint *)((int)local_14 + 2);
    }
  }
  else if ((local_8 == (uint *)0x0) || (local_8 < puVar1)) {
    local_8 = puVar1;
  }
  pvVar7 = (HANDLE)0xffffffff;
  pbVar3 = FUN_004a8060((byte *)local_8,0x2e);
  if (pbVar3 == (byte *)0x0) {
    iVar6 = 0x117;
    pcVar5 = "spawnve.c";
    uVar4 = 2;
    sVar2 = _strlen((char *)local_14);
    puVar1 = (uint *)FUN_00494860(sVar2 + 5,uVar4,(int)pcVar5,iVar6);
    if (puVar1 == (uint *)0x0) {
      return (HANDLE)0xffffffff;
    }
    FUN_00497270(puVar1,local_14);
    sVar2 = _strlen((char *)local_14);
    for (local_18 = 3; -1 < local_18; local_18 = local_18 + -1) {
      FUN_00497270((uint *)((int)puVar1 + sVar2),(uint *)(&PTR_DAT_004c7700)[local_18]);
      iVar6 = FUN_004a8000((LPCSTR)puVar1,0);
      if (iVar6 != -1) {
        pvVar7 = FID_conflict__wcomexecmd(param_1,(LPCSTR)puVar1,param_3,param_4);
        break;
      }
    }
    FUN_004952a0(puVar1,2);
  }
  else {
    iVar6 = FUN_004a8000((LPCSTR)local_14,0);
    if (iVar6 != -1) {
      pvVar7 = FID_conflict__wcomexecmd(param_1,(LPCSTR)local_14,param_3,param_4);
    }
  }
  if (local_14 != param_2) {
    FUN_004952a0(local_14,2);
  }
  return pvVar7;
}

