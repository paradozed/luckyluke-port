/* FUN_004430e0 @ 004430e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004430e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  uint local_10;
  int local_c;
  uint local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    FUN_00458ec0();
    local_8 = 0;
    while ((local_8 < (uint)param_1[0x82] && (iVar1 = FUN_00442df0(param_1,local_8), iVar1 != -1)))
    {
      FUN_00442fb0((byte *)(param_1 + 1));
      FUN_00442f10((int)param_1,0);
      local_c = FUN_00443070((int)param_1,(char *)(param_1 + 0x41));
      if (local_c != 0) {
        FUN_00442f10((int)param_1,1);
        local_10 = (uint)*(byte *)(local_c + 0x10);
        switch(local_10) {
        case 0:
          FUN_00499260((char *)(param_1 + 0x41),&DAT_004b7378);
          break;
        case 1:
          FUN_00499260((char *)(param_1 + 0x41),&DAT_004b4060);
          break;
        case 2:
          FUN_00499260((char *)(param_1 + 0x41),&DAT_004b7374);
          break;
        case 3:
          FUN_00497270(*(uint **)(local_c + 0xc),param_1 + 0x41);
          break;
        case 4:
          FUN_00499260((char *)(param_1 + 0x41),&DAT_004b7370);
          break;
        case 5:
          FUN_00499260((char *)(param_1 + 0x41),&DAT_004b7374);
        }
      }
      local_8 = local_8 + 1;
    }
  }
  local_8 = 0x443291;
  __chkesp();
  return;
}

