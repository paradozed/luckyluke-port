/* FUN_0041cae0 @ 0041cae0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041cae0(undefined4 param_1,void *param_2)

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
    DAT_004f2bf0 = (int)sVar1;
    if (2000 < DAT_004f2bf0) {
      DAT_004f2bf0 = 2000;
    }
    if (DAT_004f2bf0 < 0) {
      DAT_004f2bf0 = 0;
    }
  }
  uStack_8 = 0x41cb4f;
  __chkesp();
  return;
}

