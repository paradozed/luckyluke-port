/* FUN_0047bf10 @ 0047bf10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047bf10(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 < DAT_004be3c0) {
    DAT_004be3c0 = param_1;
  }
  if (param_2 < DAT_004be3c0) {
    DAT_004be3c0 = param_2;
  }
  if (param_3 < DAT_004be3c0) {
    DAT_004be3c0 = param_3;
  }
  if (param_4 < DAT_004be3c0) {
    DAT_004be3c0 = param_4;
  }
  if (DAT_004be3c4 < param_1) {
    DAT_004be3c4 = param_1;
  }
  if (DAT_004be3c4 < param_2) {
    DAT_004be3c4 = param_2;
  }
  if (DAT_004be3c4 < param_3) {
    DAT_004be3c4 = param_3;
  }
  if (param_4 < DAT_004be3c0) {
    DAT_004be3c0 = param_4;
  }
  return;
}

