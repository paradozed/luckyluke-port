/* FUN_0040f6e0 @ 0040f6e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040f6e0(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_004074b0(param_2,2);
  DAT_004d1db4 = (undefined1)uVar1;
  uStack_8 = 0x40f718;
  __chkesp();
  return;
}

