/* FUN_0044baa0 @ 0044baa0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0044baa0(char *param_1)

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
  DAT_004f2e08 = (void *)FUN_00494c40(0x20000,1);
  _memset(DAT_004f2e08,0,0x20000);
  FUN_00458ec0();
  DAT_004e8824 = (void *)FUN_004658d0(param_1);
  FUN_00458ec0();
  FUN_0044b320();
  FUN_0041ebe0();
  if (DAT_004e8824 != (void *)0x0) {
    FUN_00465890(DAT_004e8824);
    DAT_004e8824 = (void *)0x0;
  }
  if (DAT_004f2e08 != (void *)0xdddddddd) {
    FUN_00495280(DAT_004f2e08);
  }
  uStack_8 = 0x44bb5f;
  __chkesp();
  return;
}

