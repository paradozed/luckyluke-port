/* FUN_0047c4e0 @ 0047c4e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047c4e0(short param_1,short param_2,short param_3)

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
  FUN_00483050((int)param_1,(int)param_2);
  FUN_004830a0((int)param_3);
  uStack_8 = 0x47c524;
  __chkesp();
  return;
}

