/* FUN_004056d0 @ 004056d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004056d0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined4 *puVar4;
  undefined4 local_25c [16];
  int local_21c;
  uint local_218;
  uint local_214;
  int local_210;
  char *local_20c;
  uint local_208 [64];
  undefined4 local_108;
  uint local_104 [63];
  undefined4 uStack_8;
  
  puVar4 = local_25c;
  for (iVar3 = 0x96; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  DAT_004be3bc = 1;
  FUN_00458ec0();
  FUN_00445040();
  FUN_00443ab0();
  FUN_00458ec0();
  (*DAT_004e8a84)();
  uVar2 = __chkesp();
  if ((uVar2 & 0xff) != 0) {
    FUN_00458ec0();
    wsprintfA((LPSTR)local_208,"%s.cmp",*(undefined4 *)(&DAT_004bce50 + (uint)DAT_004e8914 * 4));
    __chkesp();
    FUN_00458ec0();
    local_20c = (char *)FUN_00435000("win\\palettes.kxp","lucky");
    FUN_00458ec0();
    FUN_00432b10(local_20c,local_208);
    FUN_00458ec0();
    FUN_00435d90(local_20c);
  }
  FUN_00458ec0();
  FUN_00458ec0();
  cVar1 = FUN_004749b0();
  if (cVar1 != '\0') {
    DAT_004f17e8 = '\0';
  }
  if (DAT_004bc05c != '\0') {
    DAT_004e8914 = DAT_004bcec8;
    DAT_004f29ac = DAT_004e8598;
    DAT_004bc05c = '\0';
  }
  DAT_004f1e21 = 0;
  DAT_004f1620 = 0;
  if (DAT_004e8914 == 2) {
    DAT_004e898c = 0;
  }
  FUN_00458ec0();
  if (DAT_004e8914 == 1) {
    FUN_00473af0();
  }
  if (DAT_004f17e8 == '\0') {
    if (((DAT_004e8914 == 1) && (DAT_004e8916 == 0)) && (DAT_004bc084 != '\0')) {
      FUN_00458ec0();
      if (DAT_004e8588 != 0) {
        FUN_00404be0();
      }
      DAT_004e8916 = 1;
      DAT_004bc084 = '\0';
    }
    if (DAT_004e8914 == 0x1e) {
      FUN_00473af0();
      DAT_004e8914 = 1;
      DAT_004e898c = 0;
      if (DAT_004e8588 != 0) {
        FUN_00458ec0();
        FUN_0041ed10();
        FUN_00458ec0();
        FUN_00404be0();
        FUN_00458ec0();
        FUN_0041e610();
      }
    }
    FUN_00458ec0();
    if (DAT_004f160c == '\0') {
      DAT_004e8985 = FUN_00474c70();
    }
    else if (DAT_004f16c8 < 4) {
      FUN_004750b0();
    }
    else {
      if (DAT_004e8588 != 0) {
        FUN_0041ed10();
        FUN_00404be0();
        FUN_0041e610();
      }
      DAT_004f16c8 = 0;
      DAT_004e8914 = 1;
      FUN_00497270((uint *)&DAT_004f57a0,(uint *)PTR_s__Cinema_Option_Option_004bcddc);
      FUN_00474c50();
      local_214 = (uint)DAT_004f17ea;
      switch(local_214) {
      case 0:
        FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cc4);
        break;
      case 1:
        FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cc0);
        break;
      case 2:
        FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cbc);
        break;
      case 3:
        FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cb8);
        break;
      case 4:
        FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cb4);
        break;
      case 5:
        FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cb0);
        break;
      case 6:
        FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cac);
      }
      DAT_004e8984 = 0;
      DAT_004f160c = '\0';
    }
    if (((DAT_004e8914 != 3) && (DAT_004e8914 != 0xb)) && (DAT_004e8914 != 0x18)) {
      DAT_004f1788 = 0;
    }
    FUN_00458ec0();
    if (DAT_004e8588 != 0) {
      if (DAT_004e8985 == '\0') {
        if (DAT_004f160c == '\0') {
          FUN_00458ec0();
          FUN_00449670();
        }
      }
      else {
        FUN_00458ec0();
        FUN_00475330();
      }
    }
    FUN_0041e610();
    DAT_004e8310 = &DAT_004f79e0 + (DAT_004e8914 - 1) * 0x1c;
    FUN_00497270(local_104,(uint *)&DAT_004f57a0);
    FUN_00405330();
    FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3c68);
    FUN_00458ec0();
    FUN_0044baa0(&DAT_004f57a0);
    FUN_004052b0((char *)local_104);
    FUN_00497280(local_104,(uint *)&DAT_004b3c48);
    FUN_00458ec0();
    FUN_00458ec0();
    DAT_004e8820 = FUN_004658d0((char *)local_104);
    if ((DAT_004e8584 != 0) &&
       (uVar2 = FUN_00474e90(CONCAT22(extraout_var,DAT_004e8914)), (uVar2 & 0xff) != 0)) {
      DAT_004e8975 = 2;
    }
    if ((&DAT_004be174)[(uint)DAT_004e8975 * 8] == '\x02') {
      FUN_00472490((uint *)(&PTR_s_abilene_004be118)[DAT_004e8976]);
      DAT_004e8975 = 0;
    }
    else if ((DAT_004e8584 != 0) && ((&DAT_004be174)[(uint)DAT_004e8975 * 8] == '\x01')) {
      FUN_004728c0();
      DAT_004e8975 = 0;
    }
  }
  else if (((DAT_004e8914 != 3) && (DAT_004e8914 != 0xb)) && (DAT_004e8914 != 0x18)) {
    DAT_004f1788 = 0;
  }
  FUN_0047e150((uint)DAT_004e8914);
  DAT_004d1db3 = DAT_004e8914 == 1;
  FUN_00458ec0();
  local_108 = FUN_00405350();
  FUN_00458ec0();
  local_210 = FUN_00422460(local_108,0);
  if (local_210 == 0) {
    FUN_00458ec0();
  }
  FUN_00458ec0();
  FUN_00422730(&DAT_004d1da8,local_210,0,FUN_00407610);
  FUN_00422730(&DAT_004d1da8,local_210,2,FUN_00407610);
  FUN_0044a150();
  FUN_0044a210();
  FUN_00458ec0();
  FUN_00471800();
  FUN_00458ec0();
  FUN_004718e0(0x18);
  FUN_00458ec0();
  local_218 = (uint)DAT_004e8914;
  if (((local_218 == 4) || (local_218 == 0x16)) || (local_218 == 0x18)) {
    (*DAT_00508864)(0);
    __chkesp();
  }
  else {
    (*DAT_00508864)(1);
    __chkesp();
  }
  local_21c = DAT_004e8914 - 9;
  switch(DAT_004e8914) {
  case 9:
  case 0xd:
  case 0xf:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x18:
    (*DAT_004e8a6c)(0x80);
    __chkesp();
    break;
  default:
    (*DAT_004e8a6c)(0xff);
    __chkesp();
  }
  if (DAT_004e8914 == 0x11) {
    (*DAT_005089f4)(0);
    __chkesp();
    FUN_0047be40(0);
  }
  else if (DAT_004e8914 == 6) {
    (*DAT_005089f4)(1);
    __chkesp();
    FUN_0047be40(1);
  }
  else {
    (*DAT_005089f4)(0);
    __chkesp();
    FUN_0047be40(1);
  }
  FUN_00458ec0();
  FUN_004435d0((uint *)"Texture cache",0x4438e0,0,0x443b00,0);
  FUN_004435d0((uint *)"Font stuff",0x42c8c0,0,0x42c9b0,0);
  FUN_004435d0((uint *)"Fade control",0,0x440fb0,0,0);
  FUN_004435d0((uint *)"Editor",0,0x42f420,0,0);
  FUN_004435d0((uint *)"Menu highlight",0,0x404700,0,0);
  FUN_004435d0((uint *)"Flatshoe",0,0x42bff0,0,0);
  FUN_004435d0((uint *)"Keyboard hand",0x430020,0x4303c0,0x430080,0);
  FUN_004435d0((uint *)"String Queue",0,0x42ca90,0,0);
  if (((DAT_004e8914 == 9) || (DAT_004e8914 == 0x11)) || (DAT_004e8914 == 10)) {
    FUN_004435d0((uint *)"Compass",0x427420,0x427680,0,0);
  }
  if (DAT_004e8914 == 0xb) {
    FUN_004435d0((uint *)"Buttercut",0x442480,0,0x442510,0);
  }
  if (DAT_004e8914 == 1) {
    FUN_004435d0((uint *)"Keyboard info",0,0x4317d0,0,0);
  }
  FUN_004435d0((uint *)"Fade draw",0,0x441080,0,0);
  FUN_0041e800();
  uStack_8 = 0x406090;
  __chkesp();
  return;
}

