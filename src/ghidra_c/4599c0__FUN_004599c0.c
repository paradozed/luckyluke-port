/* FUN_004599c0 @ 004599c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004599c0(uint param_1,int param_2)

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
  local_8 = param_1 & 0xffff;
  if (local_8 < 2) {
    if (DAT_004e8701 != '\0') {
      if (DAT_004f2744 == 0xa000) {
        FUN_00459800(param_2,(int *)&DAT_004bda18);
      }
      if (DAT_004f2744 == 0x5000) {
        FUN_00459800(param_2,(int *)&DAT_004bda60);
      }
    }
  }
  else if (local_8 != 2) {
    FUN_00497610((byte *)"Error: File %s, Line %d");
  }
  local_8 = 0x459a6d;
  __chkesp();
  return;
}

