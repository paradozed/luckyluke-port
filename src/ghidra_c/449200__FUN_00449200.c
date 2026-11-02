/* FUN_00449200 @ 00449200 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00449200(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  short *local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(int *)(param_1 + 8);
  if ((((*DAT_004e8310 & 3) != 0) && (DAT_004e8582 == '\0')) && (DAT_004bd040 != DAT_004e85b0)) {
    DAT_004bd040 = DAT_004e85b0;
    FUN_004452f0();
    if (DAT_004bd6b0 != '\0') {
      for (local_c = *(short **)(local_8 + 0xc); local_c != (short *)0x0;
          local_c = *(short **)(local_c + 0x16)) {
        if ((char)local_c[0xd] != '\0') {
          FUN_00448a40(local_c);
        }
      }
    }
  }
  local_8 = 0x4492aa;
  __chkesp();
  return;
}

