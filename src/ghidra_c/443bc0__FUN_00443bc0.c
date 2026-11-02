/* FUN_00443bc0 @ 00443bc0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00443bc0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (undefined4 *)FUN_00494c40(0x18,1);
  if (local_8 != (undefined4 *)0x0) {
    uVar1 = FUN_00494c40(0x20000,1);
    local_8[1] = uVar1;
    if (local_8[1] == 0) {
      if (local_8 != (undefined4 *)0xdddddddd) {
        FUN_00495280(local_8);
      }
    }
    else {
      local_8[2] = 0;
      local_8[3] = 0;
      *local_8 = 0;
      if (DAT_004e8578 == (undefined4 *)0x0) {
        DAT_004e8578 = local_8;
        DAT_004e857c = local_8;
        local_8[4] = 0;
        local_8[5] = 0;
      }
      else {
        DAT_004e857c[4] = local_8;
        local_8[5] = DAT_004e857c;
        local_8[4] = 0;
        DAT_004e857c = local_8;
      }
    }
  }
  local_8 = (undefined4 *)0x443cb6;
  __chkesp();
  return;
}

