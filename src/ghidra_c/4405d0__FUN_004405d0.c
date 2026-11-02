/* FUN_004405d0 @ 004405d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004405d0(PVOID param_1)

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
  if (param_1 != (PVOID)0x0) {
    FUN_00439c30(param_1);
  }
  uStack_8 = 0x440607;
  __chkesp();
  return;
}

