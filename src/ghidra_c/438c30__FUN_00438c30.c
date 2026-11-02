/* FUN_00438c30 @ 00438c30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00438c30(int param_1)

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
  FUN_004389f0(param_1);
  FUN_00439540(DAT_004e84e0);
  uStack_8 = 0x438c7c;
  __chkesp();
  return;
}

