/* FUN_0043c440 @ 0043c440 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043c440(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 != 0) {
    uVar1 = FUN_00494c40(param_2 * 0x54,1);
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    if (*(int *)(param_1 + 0x14) != 0) {
      *(int *)(param_1 + 4) = param_2;
    }
  }
  uStack_8 = 0x43c4a1;
  __chkesp();
  return;
}

