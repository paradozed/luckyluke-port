/* FUN_00442ae0 @ 00442ae0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442ae0(LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  uint *local_10;
  int *local_c;
  undefined4 uStack_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = (uint *)FUN_00497d00(param_1,"rb");
  if (local_10 != (uint *)0x0) {
    local_c = (int *)FUN_00494c40(0x218,1);
    if (local_c == (int *)0x0) {
      FUN_00497b30((int *)local_10);
    }
    else {
      FUN_004988b0(local_10,0,2);
      iVar1 = FUN_00498dc0(local_10);
      local_c[0x81] = iVar1;
      FUN_004988b0(local_10,0,0);
      if (local_c[0x81] == 0) {
        FUN_00497b30((int *)local_10);
        if (local_c != (int *)0xdddddddd) {
          FUN_00495280(local_c);
        }
      }
      else {
        iVar1 = FUN_00442930(local_10,local_c[0x81],local_c + 0x83);
        local_c[0x82] = iVar1;
        _memset(local_c + 1,0,0x100);
        *local_c = (int)local_10;
        local_c[0x84] = 0;
        local_c[0x85] = 0;
      }
    }
  }
  uStack_8 = 0x442c1a;
  __chkesp();
  return;
}

