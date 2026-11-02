/* FUN_00466510 @ 00466510 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00466510(ushort param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 uStack_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8844 = param_1;
  *(ushort *)(DAT_004f2458 + 0x31) = param_1;
  FUN_004663b0(DAT_004f2458,param_1,param_2);
  uStack_8 = 0x466568;
  __chkesp();
  return;
}

