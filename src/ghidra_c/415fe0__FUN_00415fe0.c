/* FUN_00415fe0 @ 00415fe0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415fe0(int param_1,void *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = FUN_004074b0(param_2,3);
  uVar5 = (undefined1)uVar2;
  uVar2 = FUN_004074b0(param_2,2);
  bVar1 = (byte)uVar2;
  iVar3 = FUN_00407580(param_1);
  FUN_00447550(*(int *)(iVar3 + 8),bVar1,uVar5);
  uStack_8 = 0x41602f;
  __chkesp();
  return;
}

