/* FUN_00485c00 @ 00485c00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00485c00(int param_1,undefined2 *param_2,char param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  undefined4 local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = *(int *)(param_1 + 0xcc);
  if (param_2 == (undefined2 *)0x0) {
    param_2 = *(undefined2 **)(*(int *)(param_1 + 0xcc) + 0x28);
  }
  if (param_3 == '\0') {
    uVar1 = *param_2;
  }
  else {
    uVar1 = *(undefined2 *)
             (*(int *)(param_2 + 4) + 4 + (uint)*(ushort *)(*(int *)(param_1 + 0xcc) + 0xe) * 0xc);
  }
  local_8 = CONCAT22(local_8._2_2_,uVar1);
  if (*(char *)(param_2 + 2) == '\0') {
    FUN_00485300((ushort *)(*(int *)(param_1 + 0xcc) + 0x2c),uVar1);
  }
  else {
    FUN_004862e0(param_1,*(int *)(param_2 + 4) + (uint)*(ushort *)(local_c + 4) * 0xc,
                 (short)*(undefined4 *)(local_c + 0x14));
  }
  FUN_00485a00(param_1);
  FUN_00439c30(*(PVOID *)(param_1 + 0xcc));
  *(undefined4 *)(param_1 + 0xcc) = 0;
  local_8 = 0x485cfb;
  __chkesp();
  return;
}

