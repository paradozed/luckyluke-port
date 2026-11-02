/* FUN_00437590 @ 00437590 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00437590(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  char *local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (char *)FUN_00435000("win\\graphics\\presskey.kxp","lucky");
  local_20 = (uint)DAT_004f17ea;
  switch(local_20) {
  case 0:
    local_c = (void *)FUN_00431fe0(local_8,(uint *)"pak_e.pcx");
    break;
  case 1:
    local_c = (void *)FUN_00431fe0(local_8,(uint *)"pak_f.pcx");
    break;
  case 2:
    local_c = (void *)FUN_00431fe0(local_8,(uint *)"pak_g.pcx");
    break;
  case 3:
    local_c = (void *)FUN_00431fe0(local_8,(uint *)"pak_s.pcx");
    break;
  case 4:
    local_c = (void *)FUN_00431fe0(local_8,(uint *)"pak_i.pcx");
    break;
  case 5:
    local_c = (void *)FUN_00431fe0(local_8,(uint *)"pak_d.pcx");
    break;
  case 6:
    local_c = (void *)FUN_00431fe0(local_8,(uint *)"pak_b.pcx");
  }
  FUN_00435d90(local_8);
  local_1c = param_3 * 0x200 + param_2;
  local_18 = 0;
  for (local_14 = 0; local_14 < DAT_004e848c; local_14 = local_14 + 1) {
    for (local_10 = 0; local_10 < DAT_004e8488; local_10 = local_10 + 1) {
      if (*(short *)((int)local_c + local_18 * 2) != 0) {
        *(undefined2 *)(param_1 + local_1c * 2) = *(undefined2 *)((int)local_c + local_18 * 2);
      }
      local_18 = local_18 + 1;
      local_1c = local_1c + 1;
    }
    local_1c = local_1c + (0x200 - DAT_004e8488);
  }
  if (local_c != (void *)0xdddddddd) {
    FUN_00495280(local_c);
  }
  local_8 = (char *)0x43773f;
  __chkesp();
  return;
}

