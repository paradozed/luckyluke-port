/* FUN_0040f2b0 @ 0040f2b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040f2b0(undefined4 param_1,void *param_2)

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
  FUN_004074b0(param_2,2);
  uStack_8 = 0x40f2f1;
  __chkesp();
  return;
}

