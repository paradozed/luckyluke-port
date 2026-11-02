/* FUN_00493510 @ 00493510 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00493510(byte param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8aee = param_1 | param_2 << 4;
  if (DAT_004e8aee == 0x11) {
    DAT_00508e30 = FUN_00493ce0;
  }
  else if (DAT_004e8aee == 0x21) {
    DAT_00508e30 = FUN_00493a60;
  }
  else if (DAT_004e8aee == 0x22) {
    DAT_00508e30 = FUN_004937c0;
  }
  else {
    DAT_00508e30 = FUN_00493ef0;
  }
  return;
}

