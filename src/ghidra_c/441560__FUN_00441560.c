/* FUN_00441560 @ 00441560 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00441560(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8c [16];
  uint local_4c;
  uint local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  uint local_28 [8];
  char *local_8;
  
  puVar2 = local_8c;
  for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (char *)FUN_00435000("abilene\\abilene.kxp","lucky");
  if ((DAT_004e8914 == 2) || (DAT_004e8914 == 3)) {
    FUN_00432510(local_8,(uint *)"back.pcx",0,0,0);
  }
  if (DAT_004e8914 == 2) {
    FUN_00432510(local_8,(uint *)"coin1.pcx",10,0x60,0x51);
    FUN_00432510(local_8,(uint *)"coin2.pcx",10,0x90,0x4d);
    FUN_00432510(local_8,(uint *)"coin3.pcx",10,100,0x7f);
    FUN_00432510(local_8,(uint *)"coin4.pcx",10,0xa6,0x24);
    FUN_00432510(local_8,(uint *)"coin5.pcx",0xb,0x84,0x6b);
    FUN_00432510(local_8,(uint *)"coin6.pcx",9,0x78,0x95);
    FUN_00432510(local_8,(uint *)"coin7.pcx",0xb,0xdc,0xdc);
    FUN_00432510(local_8,(uint *)"coin8.pcx",0xb,200,0x9e);
    FUN_00432510(local_8,(uint *)"coin9.pcx",0xb,0xcc,0x3c);
    FUN_00432510(local_8,(uint *)"coin10.pcx",0xd,0x40,0xc6);
    FUN_00432510(local_8,(uint *)"coin11.pcx",7,0xf8,200);
  }
  FUN_0044a240("win\\mouse.pcx",0xf,0,0);
  FUN_00435d90(local_8);
  if ((((DAT_004f17ea == 4) || (DAT_004f17ea == 5)) || (DAT_004f17ea == 6)) && (DAT_004e8914 == 1))
  {
    local_48 = (uint)DAT_004f17ea;
    if (local_48 == 4) {
      local_8 = (char *)FUN_00435000("win\\graphics\\lang_i.kxp","lucky");
    }
    else if (local_48 == 5) {
      local_8 = (char *)FUN_00435000("win\\graphics\\lang_u.kxp","lucky");
    }
    else if (local_48 == 6) {
      local_8 = (char *)FUN_00435000("win\\graphics\\lang_b.kxp","lucky");
    }
    FUN_00432a70(local_8,(uint *)"back.pcx",0x79);
    FUN_00432a70(local_8,(uint *)"shoot.pcx",0x6a);
    FUN_00432a70(local_8,(uint *)"shoot.pcx",0xfb);
    FUN_00432a70(local_8,(uint *)"sfx.pcx",0x77);
    FUN_00432a70(local_8,(uint *)"scorebar.pcx",0x68);
    FUN_00432a70(local_8,(uint *)"scorebar.pcx",0xfc);
    FUN_00432a70(local_8,(uint *)"password.pcx",0x7c);
    FUN_00432a70(local_8,(uint *)"options.pcx",0x7a);
    FUN_00432a70(local_8,(uint *)"jump.pcx",0x6c);
    FUN_00432a70(local_8,(uint *)"jump.pcx",0xfa);
    FUN_00432a70(local_8,(uint *)"game.pcx",0x76);
    FUN_00432a70(local_8,(uint *)"dynamite.pcx",0x6e);
    FUN_00432a70(local_8,(uint *)"dynamite.pcx",0xf9);
    FUN_00432a70(local_8,(uint *)"control.pcx",0x7d);
    FUN_00432a70(local_8,(uint *)"configc.pcx",0xf7);
    FUN_00432a70(local_8,(uint *)"configb.pcx",0xf6);
    FUN_00432a70(local_8,(uint *)"configa.pcx",0xf5);
    FUN_00432a70(local_8,(uint *)"stereo.pcx",0x11d);
    FUN_00432a70(local_8,(uint *)"run.pcx",0x70);
    FUN_00432a70(local_8,(uint *)"run.pcx",0xf8);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 1) {
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
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    local_4c = (uint)DAT_004f17ea;
    switch(local_4c) {
    case 0:
      FUN_00432a70(local_8,(uint *)"control.pcx",0x7d);
      FUN_00432a70(local_8,(uint *)"configea.pcx",0x72);
      FUN_00432a70(local_8,(uint *)"configea.pcx",0xf5);
      FUN_00432a70(local_8,(uint *)"configeb.pcx",0xf6);
      FUN_00432a70(local_8,(uint *)"configec.pcx",0xf7);
      FUN_00432a70(local_8,(uint *)"password.pcx",0x7c);
      break;
    case 1:
      FUN_00432a70(local_8,(uint *)"manette.pcx",0x7d);
      FUN_00432a70(local_8,(uint *)"motde.pcx",0x7c);
      FUN_00432a70(local_8,(uint *)"configea.pcx",0x72);
      FUN_00432a70(local_8,(uint *)"configea.pcx",0xf5);
      FUN_00432a70(local_8,(uint *)"configeb.pcx",0xf6);
      FUN_00432a70(local_8,(uint *)"configec.pcx",0xf7);
      break;
    case 2:
      FUN_00432a70(local_8,(uint *)"option.pcx",0x7a);
      FUN_00432a70(local_8,(uint *)"control.pcx",0x7d);
      FUN_00432a70(local_8,(uint *)"score.pcx",0xfc);
      FUN_00432a70(local_8,(uint *)"passwort.pcx",0x7c);
      break;
    case 3:
      FUN_00432a70(local_8,(uint *)"contra.pcx",0x7c);
      FUN_00432a70(local_8,(uint *)"configsa.pcx",0xf5);
      FUN_00432a70(local_8,(uint *)"configsb.pcx",0xf6);
      FUN_00432a70(local_8,(uint *)"configsc.pcx",0xf7);
      FUN_00432a70(local_8,(uint *)"opciones.pcx",0x7a);
      break;
    case 4:
      FUN_00432a70(local_8,(uint *)"password.pcx",0x7c);
      FUN_00432a70(local_8,(uint *)"control.pcx",0x7d);
    }
    FUN_00432510(local_8,(uint *)"default.pcx",0xd,0,0x50);
    FUN_00432510(local_8,(uint *)"wood.pcx",0,0x80,0xf7);
    FUN_00432a70(local_8,(uint *)"wanted.pcx",0xc);
    FUN_00432510(local_8,(uint *)"moon.pcx",6,0x4f,0);
    FUN_00435d90(local_8);
    local_44 = "_en.pcx";
    local_40 = "_fr.pcx";
    local_3c = "_ge.pcx";
    local_38 = "_sp.pcx";
    local_34 = "_it.pcx";
    local_30 = "_du.pcx";
    local_2c = "_br.pcx";
    local_8 = (char *)FUN_00435000("win\\graphics\\handed.kxp","lucky");
    FUN_00497080((undefined1 *)local_28,0x4b6fbc);
    FUN_00432510(local_8,local_28,0xe,0,0);
    FUN_00497080((undefined1 *)local_28,0x4b6fb4);
    FUN_00432510(local_8,local_28,0xe,0,100);
    FUN_00432510(local_8,(uint *)"cross.pcx",0xe,0,0xca);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 9) {
    local_8 = (char *)FUN_00435000("win\\graphics\\compass.kxp","lucky");
    FUN_00432510(local_8,(uint *)"ring.pcx",9,0,0);
    FUN_00432510(local_8,(uint *)"arrow.pcx",9,0x50,0);
    FUN_00435d90(local_8);
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    FUN_00432510(local_8,(uint *)"pearl.pcx",6,0x10,0xf0);
    FUN_00435d90(local_8);
  }
  if ((DAT_004e8914 == 0x11) || (DAT_004e8914 == 10)) {
    local_8 = (char *)FUN_00435000("win\\graphics\\compass.kxp","lucky");
    FUN_00432510(local_8,(uint *)"ring.pcx",0xd,0,0);
    FUN_00432510(local_8,(uint *)"arrow.pcx",0xd,0x50,0);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 10) {
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    FUN_00432510(local_8,(uint *)"rope.pcx",4,0x78,1);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 5) {
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    FUN_00432a70(local_8,(uint *)"wheel1.pcx",0x5e);
    FUN_00432a70(local_8,(uint *)"wheel2.pcx",0x119);
    FUN_00432a70(local_8,(uint *)"wheel3.pcx",0x11a);
    FUN_00432a70(local_8,(uint *)"wheel4.pcx",0x11b);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 0xf) {
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    FUN_00432a70(local_8,(uint *)"indhead.pcx",0x22);
    FUN_00432a70(local_8,(uint *)"indbody.pcx",0x23);
    FUN_00432a70(local_8,(uint *)"manhead.pcx",0x21);
    FUN_00432a70(local_8,(uint *)"gingbody.pcx",0x1f);
    FUN_00432a70(local_8,(uint *)"cardbody.pcx",0x27);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 0x19) {
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    FUN_00432510(local_8,(uint *)"wanted.pcx",3,100,1);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 0x12) {
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    FUN_00432510(local_8,(uint *)"waaroug.pcx",4,0xe8,0x24);
    FUN_00432510(local_8,(uint *)"waacvert.pcx",5,0x14,0xc5);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 7) {
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    FUN_00432510(local_8,(uint *)"t2wheel1.pcx",0xb,0xe0,0xb3);
    FUN_00432510(local_8,(uint *)"t2wheel2.pcx",0xc,0xb0,0x49);
    FUN_00432510(local_8,(uint *)"t2wheel3.pcx",0xc,0xa8,0x71);
    FUN_00432510(local_8,(uint *)"t2wheel4.pcx",0xc,0xa0,0x99);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 8) {
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    FUN_00432510(local_8,(uint *)"smokebit.pcx",2,0x78,0x51);
    FUN_00435d90(local_8);
  }
  if (DAT_004e8914 == 2) {
    local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
    FUN_00432510(local_8,(uint *)0x4b6e70,0xc,0x20,0x76);
    FUN_00435d90(local_8);
  }
  FUN_004307d0();
  local_8 = (char *)0x442282;
  __chkesp();
  return;
}

