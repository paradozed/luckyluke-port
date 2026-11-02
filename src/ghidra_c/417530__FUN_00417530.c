/* FUN_00417530 @ 00417530 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00417530(undefined4 param_1,void *param_2)

{
  undefined1 uVar1;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  undefined2 uVar2;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = FUN_004074b0(param_2,3);
  uVar1 = (undefined1)uVar2;
  uVar2 = FUN_004074b0(param_2,2);
  FUN_0041fcd0((char)uVar2,uVar1);
  uStack_8 = 0x417573;
  __chkesp();
  return;
}

