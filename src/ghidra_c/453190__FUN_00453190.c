/* FUN_00453190 @ 00453190 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00453190(int *param_1,short *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004f2bd4 != DAT_004f2bd8) {
    if (DAT_004f2bd4 < DAT_004f2bd8) {
      DAT_004f2bd4 = DAT_004f2bd4 + DAT_004f2bdc;
      if (DAT_004f2bd8 < DAT_004f2bd4) {
        DAT_004f2bd4 = DAT_004f2bd8;
      }
    }
    else if ((DAT_004f2bd8 < DAT_004f2bd4) &&
            (DAT_004f2bd4 = DAT_004f2bd4 - DAT_004f2bdc, DAT_004f2bd4 < DAT_004f2bd8)) {
      DAT_004f2bd4 = DAT_004f2bd8;
    }
  }
  if ((((DAT_004f2c00 != DAT_004f2c18) || (DAT_004f2c00 != DAT_004f2c1c)) ||
      (DAT_004f2c0c != DAT_004f2c20)) || (DAT_004f2c0c != DAT_004f2c24)) {
    if (DAT_004f2c00 < DAT_004f2c18) {
      DAT_004f2c00 = DAT_004f2c00 + _DAT_004f2c28;
      if (DAT_004f2c18 < DAT_004f2c00) {
        DAT_004f2c00 = DAT_004f2c18;
      }
    }
    else if ((DAT_004f2c18 < DAT_004f2c00) &&
            (DAT_004f2c00 = DAT_004f2c00 - _DAT_004f2c28, DAT_004f2c00 < DAT_004f2c18)) {
      DAT_004f2c00 = DAT_004f2c18;
    }
    if (DAT_004f2c04 < DAT_004f2c1c) {
      DAT_004f2c04 = DAT_004f2c04 + _DAT_004f2c28;
      if (DAT_004f2c1c < DAT_004f2c04) {
        DAT_004f2c04 = DAT_004f2c1c;
      }
    }
    else if ((DAT_004f2c1c < DAT_004f2c04) &&
            (DAT_004f2c04 = DAT_004f2c04 - _DAT_004f2c28, DAT_004f2c04 < DAT_004f2c1c)) {
      DAT_004f2c04 = DAT_004f2c1c;
    }
    if (DAT_004f2c08 < DAT_004f2c20) {
      DAT_004f2c08 = DAT_004f2c08 + _DAT_004f2c28;
      if (DAT_004f2c20 < DAT_004f2c08) {
        DAT_004f2c08 = DAT_004f2c20;
      }
    }
    else if ((DAT_004f2c20 < DAT_004f2c08) &&
            (DAT_004f2c08 = DAT_004f2c08 - _DAT_004f2c28, DAT_004f2c08 < DAT_004f2c20)) {
      DAT_004f2c08 = DAT_004f2c20;
    }
    if (DAT_004f2c0c < DAT_004f2c24) {
      DAT_004f2c0c = DAT_004f2c0c + _DAT_004f2c28;
      if (DAT_004f2c24 < DAT_004f2c0c) {
        DAT_004f2c0c = DAT_004f2c24;
      }
    }
    else if ((DAT_004f2c24 < DAT_004f2c0c) &&
            (DAT_004f2c0c = DAT_004f2c0c - _DAT_004f2c28, DAT_004f2c0c < DAT_004f2c24)) {
      DAT_004f2c0c = DAT_004f2c24;
    }
  }
  if (DAT_004e866c == '\0') {
    if (DAT_004f2c04 < *param_1) {
      *param_1 = DAT_004f2c04;
    }
    if (*param_1 < DAT_004f2c00) {
      *param_1 = DAT_004f2c00;
    }
    if (DAT_004f2c0c < param_1[1]) {
      param_1[1] = DAT_004f2c0c;
    }
    if (param_1[1] < DAT_004f2c08) {
      param_1[1] = DAT_004f2c08;
    }
    if (DAT_004f2c14 < param_1[2]) {
      param_1[2] = DAT_004f2c14;
    }
    if (param_1[2] < DAT_004f2c10) {
      param_1[2] = DAT_004f2c10;
    }
  }
  DAT_004e8688 = *param_2;
  DAT_004e868a = param_2[1];
  DAT_004e868c = param_2[2];
  FUN_00453540(&DAT_004bd6a0,param_1);
  if (DAT_004f2bf8 != 0xb) {
    FUN_00451500(param_1,param_2,DAT_004f2bd4);
  }
  uStack_8 = 0x45353a;
  __chkesp();
  return;
}

