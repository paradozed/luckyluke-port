/* FUN_0041d370 @ 0041d370 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041d370(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004e866c != '\x01') {
    sVar1 = FUN_004074b0(param_2,2);
    DAT_004f2bd8 = (uint)sVar1;
    sVar1 = FUN_004074b0(param_2,3);
    DAT_004f2bdc = (uint)sVar1;
    if (10000 < DAT_004f2bd8) {
      DAT_004f2bd8 = 10000;
    }
    if (DAT_004f2bd8 < 0x5dc) {
      DAT_004f2bd8 = 0x5dc;
    }
    if (500 < DAT_004f2bdc) {
      DAT_004f2bdc = 500;
    }
    if (DAT_004f2bdc < 0x32) {
      DAT_004f2bdc = 0x32;
    }
  }
  uStack_8 = 0x41d41e;
  __chkesp();
  return;
}

