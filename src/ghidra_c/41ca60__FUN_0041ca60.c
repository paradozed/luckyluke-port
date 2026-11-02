/* FUN_0041ca60 @ 0041ca60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041ca60(undefined4 param_1,void *param_2)

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
  if (DAT_004e866c != '\x01') {
    DAT_004f2bbc = FUN_004074b0(param_2,2);
    if (800 < DAT_004f2bbc) {
      DAT_004f2bbc = 800;
    }
    if (DAT_004f2bbc < -800) {
      DAT_004f2bbc = -800;
    }
  }
  uStack_8 = 0x41cad3;
  __chkesp();
  return;
}

