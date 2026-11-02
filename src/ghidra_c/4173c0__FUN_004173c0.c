/* FUN_004173c0 @ 004173c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004173c0(undefined4 param_1,void *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar5 = local_44;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  uVar1 = FUN_004074b0(param_2,4);
  uVar2 = FUN_004074b0(param_2,3);
  uVar3 = FUN_004074b0(param_2,2);
  FUN_0041fa80((char)uVar3,uVar2,uVar1);
  uStack_8 = 0x41740e;
  __chkesp();
  return;
}

