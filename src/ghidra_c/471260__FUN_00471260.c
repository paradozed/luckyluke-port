/* FUN_00471260 @ 00471260 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00471260(undefined4 *param_1,ushort param_2)

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
  uVar1 = FUN_00439a90(DAT_004e85ec,(uint)param_2 << 2);
  *param_1 = uVar1;
  *(undefined2 *)(param_1 + 1) = 0;
  *(ushort *)((int)param_1 + 6) = param_2;
  uStack_8 = 0x4712b9;
  __chkesp();
  return;
}

