/* FUN_004b2410 @ 004b2410 */
/* decompiled from Lucky.exe (Game.run) */


uint * __cdecl FUN_004b2410(uint *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  LPWSTR local_8;
  
  local_8 = (LPWSTR)0x0;
  if (DAT_004e8e98 == 0) {
    cVar1 = (char)*param_1;
    puVar4 = param_1;
    while (cVar1 != '\0') {
      cVar1 = (char)*puVar4;
      if (('`' < cVar1) && (cVar1 < '{')) {
        *(char *)puVar4 = cVar1 + -0x20;
      }
      puVar4 = (uint *)((int)puVar4 + 1);
      cVar1 = *(char *)puVar4;
    }
  }
  else {
    uVar2 = FUN_004a9740(DAT_004e8e98,0x200,(char *)param_1,-1,(LPWSTR)0x0,0,0,1);
    if (((uVar2 != 0) && (local_8 = (LPWSTR)FUN_00494840(uVar2), local_8 != (LPWSTR)0x0)) &&
       (iVar3 = FUN_004a9740(DAT_004e8e98,0x200,(char *)param_1,-1,local_8,uVar2,0,1), iVar3 != 0))
    {
      FUN_00497270(param_1,(uint *)local_8);
    }
    FUN_00495280(local_8);
  }
  return param_1;
}

