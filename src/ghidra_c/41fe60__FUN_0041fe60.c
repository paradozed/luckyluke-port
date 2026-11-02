/* FUN_0041fe60 @ 0041fe60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041fe60(undefined1 param_1)

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
  DAT_004d1f1e = param_1;
  FUN_004936a0();
  uStack_8 = 0x41fe9e;
  __chkesp();
  return;
}

