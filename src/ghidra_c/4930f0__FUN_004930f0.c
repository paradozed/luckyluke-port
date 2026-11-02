/* FUN_004930f0 @ 004930f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004930f0(LPCSTR param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  char *local_18;
  uint local_14;
  uint *local_10;
  char *local_c;
  int *local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (int *)FUN_00494840(0x34);
  if (local_8 == (int *)0x0) goto LAB_00493293;
  if ((param_2 & 4) == 0) {
    local_c = param_1;
  }
  else {
    local_10 = (uint *)FUN_00497d00(param_1,"rb");
    if (local_10 == (uint *)0x0) {
      FUN_00495280(local_8);
      goto LAB_00493293;
    }
    FUN_004988b0(local_10,0,2);
    local_14 = FUN_00498dc0(local_10);
    FUN_004988b0(local_10,0,0);
    local_c = (char *)FUN_00494840(local_14);
    if (local_c == (char *)0x0) {
      FUN_00497b30((int *)local_10);
      FUN_00495280(local_8);
      goto LAB_00493293;
    }
    FUN_004989e0(local_c,1,local_14,(int *)local_10);
    FUN_00497b30((int *)local_10);
  }
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) != 0) {
      local_8[1] = param_3;
      iVar1 = FUN_00494840(local_8[1]);
      *local_8 = iVar1;
      if (*local_8 == 0) {
        FUN_00495280(local_8);
        goto LAB_00493293;
      }
      FUN_00497690((undefined4 *)*local_8,(undefined4 *)local_c,local_8[1]);
    }
  }
  else {
    local_18 = local_c;
    FUN_00492610((int)local_c,local_8);
  }
  if ((param_2 & 4) != 0) {
    FUN_00495280(local_c);
  }
LAB_00493293:
  local_8 = (int *)0x4932a0;
  __chkesp();
  return;
}

