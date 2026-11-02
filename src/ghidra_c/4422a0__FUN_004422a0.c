/* FUN_004422a0 @ 004422a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004422a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  char *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (char *)FUN_00435000("win\\graphics\\keys.kxp","lucky");
  if (DAT_004e8750 == 0) {
    FUN_00432a70(local_8,(uint *)"key_v.pcx",0x6d);
    FUN_00432a70(local_8,(uint *)"key_v.pcx",0x120);
    FUN_00432a70(local_8,(uint *)"key_b.pcx",0x6b);
    FUN_00432a70(local_8,(uint *)"key_g.pcx",0x71);
    FUN_00432a70(local_8,(uint *)"key_g.pcx",0x11e);
    FUN_00432a70(local_8,(uint *)"key_c.pcx",0x11f);
    FUN_00432a70(local_8,(uint *)"key_c.pcx",0x6f);
    FUN_00432a70(local_8,(uint *)"key_f.pcx",0x69);
  }
  else {
    FUN_00432a70(local_8,(uint *)"key_down.pcx",0x6d);
    FUN_00432a70(local_8,(uint *)"key_down.pcx",0x120);
    FUN_00432a70(local_8,(uint *)"key_rite.pcx",0x6b);
    FUN_00432a70(local_8,(uint *)"key_up.pcx",0x71);
    FUN_00432a70(local_8,(uint *)"key_up.pcx",0x11e);
    FUN_00432a70(local_8,(uint *)"key_left.pcx",0x11f);
    FUN_00432a70(local_8,(uint *)"key_left.pcx",0x6f);
    FUN_00432a70(local_8,(uint *)"key_f.pcx",0x69);
  }
  FUN_00435d90(local_8);
  (*DAT_004e8a24)(0xb,*(undefined4 *)(DAT_004f58a4 + 0x2c));
  __chkesp();
  (*DAT_004e8a24)(0xc,*(undefined4 *)(DAT_004f58a4 + 0x30));
  __chkesp();
  local_8 = (char *)0x442476;
  __chkesp();
  return;
}

