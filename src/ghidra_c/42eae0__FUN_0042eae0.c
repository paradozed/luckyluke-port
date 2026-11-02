/* FUN_0042eae0 @ 0042eae0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042eae0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  int local_10;
  undefined1 local_c;
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (*DAT_004f58a8 != 0x536f6674) {
    (*DAT_004e8a6c)(0x80);
    uVar1 = __chkesp();
    local_c = (undefined1)uVar1;
    local_10 = DAT_004e85b8 + -2;
    switch(DAT_004e85b8) {
    case 2:
      local_8 = FUN_0042cb20((uint *)"FONDTOIT",0);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0xf,8,8,8,0xff);
        FUN_0047e320(local_8,0xe,8,8,8,0xff);
        FUN_0047e320(local_8,0xd,8,8,8,0xff);
        FUN_0047e320(local_8,0xc,8,8,8,0xff);
        FUN_0047e320(local_8,0xb,8,8,8,0xff);
      }
      break;
    case 6:
      local_8 = FUN_0042cb20((uint *)"JOLTRAIN3DK",0);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0xa1,0xff,0xff,0xff,0xff);
      }
      local_8 = FUN_0042cb20((uint *)"LUKTRAIN3DK",0);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x9e,0xf0,0xac,0x50,0xff);
        FUN_0047e320(local_8,0xa0,0xf0,0xac,0x50,0xff);
      }
      break;
    case 10:
      local_8 = FUN_0042cb20((uint *)"GABLOC03",0);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x28,8,8,8,0xff);
        FUN_0047e320(local_8,0x29,8,8,8,0xff);
        FUN_0047e320(local_8,0x31,8,8,8,0xff);
        FUN_0047e320(local_8,0x3e,8,8,8,0xff);
        FUN_0047e320(local_8,0x3f,8,8,8,0xff);
        FUN_0047e320(local_8,0x40,8,8,8,0xff);
        FUN_0047e320(local_8,0x41,8,8,8,0xff);
      }
      local_8 = FUN_0042cb20((uint *)"GABLOC030",0);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x29,8,8,8,0xff);
        FUN_0047e320(local_8,0x31,8,8,8,0xff);
        FUN_0047e320(local_8,0x3b,8,8,8,0xff);
        FUN_0047e320(local_8,0x3c,8,8,8,0xff);
        FUN_0047e320(local_8,0x3d,8,8,8,0xff);
        FUN_0047e320(local_8,0x3e,8,8,8,0xff);
      }
      local_8 = FUN_0042cb20((uint *)"GABLOC030",3);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x28,8,8,8,0xff);
        FUN_0047e320(local_8,0x29,8,8,8,0xff);
        FUN_0047e320(local_8,0x31,8,8,8,0xff);
        FUN_0047e320(local_8,0x3e,8,8,8,0xff);
        FUN_0047e320(local_8,0x3f,8,8,8,0xff);
        FUN_0047e320(local_8,0x40,8,8,8,0xff);
        FUN_0047e320(local_8,0x41,8,8,8,0xff);
      }
      local_8 = FUN_0042cb20((uint *)"GABLOC030",4);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x28,8,8,8,0xff);
        FUN_0047e320(local_8,0x29,8,8,8,0xff);
        FUN_0047e320(local_8,0x31,8,8,8,0xff);
        FUN_0047e320(local_8,0x3e,8,8,8,0xff);
        FUN_0047e320(local_8,0x3f,8,8,8,0xff);
        FUN_0047e320(local_8,0x40,8,8,8,0xff);
        FUN_0047e320(local_8,0x41,8,8,8,0xff);
      }
      local_8 = FUN_0042cb20((uint *)"GABLOC030",2);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x28,8,8,8,0xff);
        FUN_0047e320(local_8,0x29,8,8,8,0xff);
        FUN_0047e320(local_8,0x31,8,8,8,0xff);
        FUN_0047e320(local_8,0x3e,8,8,8,0xff);
        FUN_0047e320(local_8,0x3f,8,8,8,0xff);
        FUN_0047e320(local_8,0x40,8,8,8,0xff);
        FUN_0047e320(local_8,0x41,8,8,8,0xff);
      }
      local_8 = FUN_0042cb20((uint *)"GABLOC03",2);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x28,8,8,8,0xff);
        FUN_0047e320(local_8,0x29,8,8,8,0xff);
        FUN_0047e320(local_8,0x31,8,8,8,0xff);
        FUN_0047e320(local_8,0x3e,8,8,8,0xff);
        FUN_0047e320(local_8,0x3f,8,8,8,0xff);
        FUN_0047e320(local_8,0x40,8,8,8,0xff);
        FUN_0047e320(local_8,0x41,8,8,8,0xff);
      }
      local_8 = FUN_0042cb20((uint *)"GABLOC03",3);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x28,8,8,8,0xff);
        FUN_0047e320(local_8,0x29,8,8,8,0xff);
        FUN_0047e320(local_8,0x31,8,8,8,0xff);
        FUN_0047e320(local_8,0x3e,8,8,8,0xff);
        FUN_0047e320(local_8,0x3f,8,8,8,0xff);
        FUN_0047e320(local_8,0x40,8,8,8,0xff);
        FUN_0047e320(local_8,0x41,8,8,8,0xff);
      }
      local_8 = FUN_0042cb20((uint *)"GABLOC03",4);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x28,8,8,8,0xff);
        FUN_0047e320(local_8,0x29,8,8,8,0xff);
        FUN_0047e320(local_8,0x31,8,8,8,0xff);
        FUN_0047e320(local_8,0x3e,8,8,8,0xff);
        FUN_0047e320(local_8,0x3f,8,8,8,0xff);
        FUN_0047e320(local_8,0x40,8,8,8,0xff);
        FUN_0047e320(local_8,0x41,8,8,8,0xff);
      }
      break;
    case 0x19:
      local_8 = FUN_0042cb20((uint *)"FLAT13DK",0);
      if (local_8 != 0) {
        FUN_0047e320(local_8,0x6e,0x90,0x70,0x9f,0xff);
        FUN_0047e320(local_8,0x6a,0x90,0x70,0x9f,0xff);
        FUN_0047e320(local_8,0x69,0x90,0x70,0x9f,0xff);
        FUN_0047e320(local_8,0x68,0x90,0x70,0x9f,0xff);
        FUN_0047e320(local_8,0x65,0x90,0x70,0x9f,0xff);
        FUN_0047e320(local_8,0x5d,0x90,0x70,0x9f,0xff);
        FUN_0047e320(local_8,0x56,0x90,0x70,0x9f,0xff);
      }
    }
    (*DAT_004e8a6c)(local_c);
    __chkesp();
  }
  local_8 = 0x42f3e6;
  __chkesp();
  return;
}

