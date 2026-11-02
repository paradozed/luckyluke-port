/* FUN_0045cdd0 @ 0045cdd0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x0045ce4e) */

void __cdecl FUN_0045cdd0(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  local_1c = param_1 & 0xffff;
  if (local_1c != 0) {
    if ((local_1c == 0) || (2 < local_1c)) goto switchD_0045d0d0_default;
    if ((DAT_004f2750 & 0x4000) != 0) {
      DAT_004f2bfa = DAT_004f2bfa + 1 & 3;
      local_20 = (uint)DAT_004f2bfa;
      switch(local_20) {
      case 0:
        PTR_FUN_004bd5d8 = FUN_00453590;
        DAT_004e866c = 0;
        if (DAT_004f2458 != (int *)0x0) {
          local_18 = *(int *)(*DAT_004f2458 + 0x90);
          local_14 = *(undefined4 *)(*DAT_004f2458 + 0x94);
          local_10 = *(undefined4 *)(*DAT_004f2458 + 0x98);
          FUN_0045d260(&local_18,&DAT_004f2b7c);
          FUN_0045d200(&DAT_004f2b8c,&local_18);
          FUN_0045d200(&DAT_004f2b7c,&local_18);
          FUN_0045d200(&DAT_004f2b6c,&local_18);
        }
        DAT_004f2458[4] = DAT_004f2458[4] & 0xffffc1fe;
        break;
      case 1:
        PTR_FUN_004bd5d8 = FUN_00453590;
        DAT_004f2c50 = 0;
        DAT_004f2c54 = 0;
        DAT_004f2c58 = 0;
        DAT_004f2c44 = 0;
        DAT_004f2c42 = 0;
        DAT_004f2c40 = 0;
        DAT_004f2458[4] = DAT_004f2458[4] & 0xffffc1fe;
        break;
      case 2:
        PTR_FUN_004bd5d8 = FUN_004549d0;
        FUN_0045d1b0(&DAT_004f2c50,&DAT_004f2b6c);
        FUN_0045d2c0(&DAT_004f2c40,&DAT_004f2bbc);
        DAT_004f2458[4] = DAT_004f2458[4] | 0x3e01;
        break;
      case 3:
        PTR_FUN_004bd5d8 = FUN_004560a0;
        DAT_004e866c = 1;
        DAT_004f2458[4] = DAT_004f2458[4] & 0xffffc1fe;
      }
    }
  }
  FUN_00459540();
  FUN_00459540();
  FUN_00459540();
  FUN_00459540();
  FUN_00459540();
  FUN_00459540();
  FUN_00459540();
  local_24 = (uint)DAT_004f2bfa;
  switch(local_24) {
  case 0:
    FUN_004266b0();
    break;
  case 1:
    FUN_004266b0();
    break;
  case 2:
    FUN_004266b0();
    break;
  case 3:
    FUN_004266b0();
  }
switchD_0045d0d0_default:
  local_8 = 0x45d182;
  __chkesp();
  return;
}

