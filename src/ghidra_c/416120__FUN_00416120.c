/* FUN_00416120 @ 00416120 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00416120(void *param_1)

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
  FUN_00412ee0(param_1,FUN_00416040);
  FUN_00471260(DAT_004f1e24,0xfa);
  FUN_00452fa0();
  DAT_004bd69c = 0x137;
  DAT_005081a0 = 0;
  DAT_004e8580 = 0;
  uStack_8 = 0x416182;
  __chkesp();
  return;
}

