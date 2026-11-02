/* FUN_0041cdd0 @ 0041cdd0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041cdd0(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e866c != '\x01') {
    if (DAT_004f2c2c == 0) {
      DAT_004f2c2c = 1;
    }
    local_8 = CONCAT22(local_8._2_2_,DAT_004f2c2c);
    DAT_004f2c2c = FUN_004074b0(param_2,2);
    if (((local_8 & 0xffff) == 1) && (DAT_004f2c2c == 2)) {
      DAT_004f2b74 = DAT_004f2b74 + DAT_004f2be8 * 2;
      _DAT_004f2c34 = 0x800;
      DAT_004f2c30 = 0xffffffff;
    }
    else if (((local_8 & 0xffff) == 2) && (DAT_004f2c2c == 1)) {
      DAT_004f2b74 = DAT_004f2b74 + DAT_004f2be8 * -2;
      _DAT_004f2c34 = 0;
      DAT_004f2c30 = 1;
    }
  }
  local_8 = 0x41cec1;
  __chkesp();
  return;
}

