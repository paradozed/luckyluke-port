/* FUN_0041cd50 @ 0041cd50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041cd50(undefined4 param_1,void *param_2)

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
    DAT_004f2be0 = (uint)sVar1;
    if (200 < DAT_004f2be0) {
      DAT_004f2be0 = 200;
    }
    if (DAT_004f2be0 < 10) {
      DAT_004f2be0 = 10;
    }
  }
  uStack_8 = 0x41cdbf;
  __chkesp();
  return;
}

