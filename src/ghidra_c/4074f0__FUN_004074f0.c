/* FUN_004074f0 @ 004074f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004074f0(int param_1)

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
  FUN_0047c470((short *)(param_1 + 0x5c));
  uStack_8 = 0x407524;
  __chkesp();
  return;
}

