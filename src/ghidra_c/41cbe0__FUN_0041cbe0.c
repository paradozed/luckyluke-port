/* FUN_0041cbe0 @ 0041cbe0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041cbe0(undefined4 param_1,void *param_2)

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
    DAT_004f2c00 = sVar1 * 100;
    sVar1 = FUN_004074b0(param_2,3);
    DAT_004f2c04 = sVar1 * 100;
    sVar1 = FUN_004074b0(param_2,4);
    DAT_004f2c08 = sVar1 * 100;
    sVar1 = FUN_004074b0(param_2,5);
    DAT_004f2c0c = sVar1 * 100;
    sVar1 = FUN_004074b0(param_2,2);
    DAT_004f2c18 = sVar1 * 100;
    sVar1 = FUN_004074b0(param_2,3);
    DAT_004f2c1c = sVar1 * 100;
    sVar1 = FUN_004074b0(param_2,4);
    DAT_004f2c20 = sVar1 * 100;
    sVar1 = FUN_004074b0(param_2,5);
    DAT_004f2c24 = sVar1 * 100;
  }
  uStack_8 = 0x41ccc4;
  __chkesp();
  return;
}

