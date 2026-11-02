/* FUN_004266d0 @ 004266d0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004266d0(LPCSTR param_1,int param_2,int param_3,int param_4,char param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined1 local_c;
  int *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 1;
  _DAT_004f7ea0 = 0x4d42;
  DAT_004f7ea8 = 0;
  _DAT_004f7ea6 = 0;
  _DAT_004f7ec0 = 0x28;
  DAT_004f7ec4 = param_3;
  DAT_004f7ec8 = param_4;
  _DAT_004f7ecc = 1;
  _DAT_004f7ed0 = 0;
  _DAT_004f7ed8 = 0x640;
  _DAT_004f7edc = 0x3c0;
  _DAT_004f7ee0 = 0;
  _DAT_004f7ee4 = 0;
  if (param_5 == '\0') {
    DAT_004f7eaa = 0x436;
    _DAT_004f7ece = 8;
    _DAT_004f7ed4 = param_3 * param_4;
  }
  else {
    DAT_004f7eaa = 0x36;
    _DAT_004f7ece = 0x18;
    _DAT_004f7ed4 = param_3 * param_4 * 3;
  }
  _DAT_004f7ea2 = DAT_004f7eaa + _DAT_004f7ed4;
  local_8 = (int *)FUN_00497d00(param_1,"wb");
  if (local_8 != (int *)0x0) {
    if (param_5 == '\0') {
      local_c = FUN_004268b0(local_8,param_2);
    }
    if (param_5 == '\x01') {
      local_c = FUN_00426a80(local_8,param_2);
    }
    if (param_5 == '\x02') {
      local_c = FUN_00426bf0(local_8,param_2);
    }
    if (param_5 == '\x03') {
      local_c = FUN_00426eb0(local_8,param_2);
    }
    if (param_5 == '\x04') {
      local_c = FUN_00426d60(local_8,param_2);
    }
    FUN_00497b30(local_8);
  }
  local_8 = (int *)0x4268a3;
  __chkesp();
  return;
}

