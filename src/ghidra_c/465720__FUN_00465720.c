/* FUN_00465720 @ 00465720 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00465720(LPCSTR param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  uint *local_10;
  char *local_c;
  uint local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = (uint *)FUN_00497d00(param_1,"rb");
  if (local_10 != (uint *)0x0) {
    FUN_004988b0(local_10,0,2);
    local_8 = FUN_00498dc0(local_10);
    FUN_004988b0(local_10,0,0);
    local_c = (char *)FUN_00494840(local_8);
    if (local_c == (char *)0x0) {
      FUN_00497b30((int *)local_10);
    }
    else {
      uVar1 = FUN_004989e0(local_c,1,local_8,(int *)local_10);
      if (uVar1 == local_8) {
        FUN_00497b30((int *)local_10);
      }
      else {
        FUN_00495280(local_c);
        FUN_00497b30((int *)local_10);
      }
    }
  }
  local_8 = 0x465800;
  __chkesp();
  return;
}

