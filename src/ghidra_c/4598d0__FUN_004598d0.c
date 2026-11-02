/* FUN_004598d0 @ 004598d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004598d0(uint param_1,int param_2)

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
  if ((local_8 != 0) && (local_8 != 1)) {
    if (local_8 == 2) {
      if (DAT_004e8701 != '\0') {
        FUN_00459800(param_2,(int *)&DAT_004bd820);
      }
    }
    else {
      FUN_00497610((byte *)"Error: File %s, Line %d");
    }
  }
  FUN_0045da10();
  FUN_00459540();
  FUN_004b1a50(DAT_0050ab24);
  FUN_00459540();
  FUN_00459540();
  local_8 = 0x4599b6;
  __chkesp();
  return;
}

