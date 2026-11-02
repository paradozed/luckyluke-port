/* FUN_00413780 @ 00413780 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00413780(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  uint local_1c;
  uint local_18;
  undefined4 *local_14;
  char *local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_14 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  local_14[1] = 0;
  *(undefined1 *)(local_14 + 4) = 0;
  *local_14 = 0;
  *(undefined1 *)((int)local_14 + 0x11) = 0;
  DAT_004f1765 = 1;
  FUN_004771a0();
  local_c = CONCAT22(local_c._2_2_,DAT_004f17ea);
  if (((DAT_004f17ea == 4) || (DAT_004f17ea == 5)) || (DAT_004f17ea == 6)) {
    local_c = (uint)local_c._2_2_ << 0x10;
  }
  local_18 = (uint)DAT_004f17ea;
  switch(local_18) {
  case 0:
    local_10 = (char *)FUN_00435000("win\\graphics\\menu_e.kxp","lucky");
    break;
  case 1:
    local_10 = (char *)FUN_00435000("win\\graphics\\menu_f.kxp","lucky");
    break;
  case 2:
    local_10 = (char *)FUN_00435000("win\\graphics\\menu_d.kxp","lucky");
    break;
  case 3:
    local_10 = (char *)FUN_00435000("win\\graphics\\menu_s.kxp","lucky");
    break;
  case 4:
    local_10 = (char *)FUN_00435000("win\\graphics\\menu_i.kxp","lucky");
    break;
  case 5:
    local_10 = (char *)FUN_00435000("win\\graphics\\menu_u.kxp","lucky");
    break;
  case 6:
    local_10 = (char *)FUN_00435000("win\\graphics\\menu_b.kxp","lucky");
  }
  _DAT_004f16f8 = FUN_00432d90(local_10,(uint *)"exity.pcx");
  DAT_004f16fc = FUN_00432d90(local_10,(uint *)"exitn.pcx");
  _DAT_004f1750 = FUN_00432d90(local_10,(uint *)"contc.pcx");
  _DAT_004f1754 = FUN_00432d90(local_10,(uint *)"contq.pcx");
  _DAT_004f13a8 = FUN_00432d90(local_10,(uint *)"backy.pcx");
  _DAT_004f13ac = FUN_00432d90(local_10,(uint *)"backn.pcx");
  DAT_004f1700 = FUN_00432d90(local_10,(uint *)"pause.pcx");
  DAT_004f1760 = FUN_00432d90(local_10,(uint *)"quit.pcx");
  _DAT_004f72d0 = FUN_00432d90(local_10,(uint *)"rety.pcx");
  DAT_004f72d4 = FUN_00432d90(local_10,(uint *)"retn.pcx");
  FUN_00435d90(local_10);
  local_1c = (uint)DAT_004f17ea;
  switch(local_1c) {
  case 0:
    DAT_004f1764 = 0;
    break;
  case 1:
    DAT_004f1764 = 2;
    break;
  case 2:
    DAT_004f1764 = 4;
    break;
  case 3:
    DAT_004f1764 = 6;
    break;
  case 4:
    DAT_004f1764 = 0;
    break;
  case 5:
    DAT_004f1764 = 0;
    break;
  case 6:
    DAT_004f1764 = 0;
  }
  FUN_00412c50(param_1,local_14);
  FUN_00412ee0(param_1,FUN_004778e0);
  uStack_8 = 0x413a38;
  __chkesp();
  return;
}

