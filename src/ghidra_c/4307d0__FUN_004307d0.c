/* FUN_004307d0 @ 004307d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004307d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  char *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8914 == 1) {
    local_c = (uint)DAT_004f17ea;
    switch(local_c) {
    case 0:
      local_8 = (char *)FUN_00435000("win\\graphics\\keyinf_e.kxp","lucky");
      break;
    case 1:
      local_8 = (char *)FUN_00435000("win\\graphics\\keyinf_f.kxp","lucky");
      break;
    case 2:
      local_8 = (char *)FUN_00435000("win\\graphics\\keyinf_g.kxp","lucky");
      break;
    case 3:
      local_8 = (char *)FUN_00435000("win\\graphics\\keyinf_s.kxp","lucky");
      break;
    case 4:
      local_8 = (char *)FUN_00435000("win\\graphics\\keyinf_i.kxp","lucky");
      break;
    case 5:
      local_8 = (char *)FUN_00435000("win\\graphics\\keyinf_d.kxp","lucky");
      break;
    case 6:
      local_8 = (char *)FUN_00435000("win\\graphics\\keyinf_b.kxp","lucky");
    }
    FUN_00432510(local_8,(uint *)"default.pcx",0xd,0,0x50);
    FUN_00432510(local_8,(uint *)"validate.pcx",0xd,0x32,0x28);
    FUN_00432510(local_8,(uint *)"return.pcx",0xd,0x82,0);
    FUN_00432510(local_8,(uint *)"space.pcx",0xd,0xb4,0x28);
    FUN_00432510(local_8,(uint *)"switch.pcx",0xd,0x78,0x50);
    FUN_00435d90(local_8);
    local_8 = (char *)FUN_00435000("win\\graphics\\keys.kxp","lucky");
    FUN_00432510(local_8,(uint *)"plank1.pcx",0xd,0,0x88);
    FUN_00432510(local_8,(uint *)"plank2.pcx",0xd,0,0xb0);
    FUN_00432510(local_8,(uint *)"plank3.pcx",0xd,0,0xd8);
    FUN_00432510(local_8,(uint *)"enter.pcx",0xd,0x32,0);
    FUN_00432510(local_8,(uint *)"backsp.pcx",0xd,0x46,0);
    FUN_00435d90(local_8);
  }
  local_8 = (char *)0x4309eb;
  __chkesp();
  return;
}

