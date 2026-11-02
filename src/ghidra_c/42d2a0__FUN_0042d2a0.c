/* FUN_0042d2a0 @ 0042d2a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042d2a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 *local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_0047e5b0(param_1,0x2d,&local_c,&local_8);
  DAT_004e8358 = local_c[1];
  DAT_004e835c = local_c[2];
  DAT_004e8368 = *local_c;
  DAT_004e836c = local_c[3];
  FUN_0047e5b0(param_1,0x46,&local_c,&local_8);
  DAT_004e8360 = local_c[1];
  DAT_004e8364 = local_c[2];
  DAT_004e8370 = *local_c;
  DAT_004e8374 = local_c[3];
  local_8 = 0x42d34c;
  __chkesp();
  return;
}

