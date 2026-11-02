/* FUN_00475910 @ 00475910 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00475910(uint param_1,undefined2 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  undefined1 *local_c;
  int local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = (undefined1 *)FUN_00439af0(8);
  *local_c = (undefined1)param_1;
  uVar1 = FUN_00439af0((param_1 & 0xffff) << 5);
  *(undefined4 *)(local_c + 4) = uVar1;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    *(undefined2 *)(*(int *)(local_c + 4) + 0x14 + local_8 * 0x20) = param_2;
    *(undefined2 *)(*(int *)(local_c + 4) + 0x18 + local_8 * 0x20) = 0;
    *(undefined2 *)(*(int *)(local_c + 4) + 0x16 + local_8 * 0x20) = 0;
    *(undefined2 *)(*(int *)(local_c + 4) + 0x12 + local_8 * 0x20) = param_3;
    *(undefined1 *)(*(int *)(local_c + 4) + 0x1a + local_8 * 0x20) = 0;
  }
  local_8 = 0x4759e3;
  __chkesp();
  return;
}

