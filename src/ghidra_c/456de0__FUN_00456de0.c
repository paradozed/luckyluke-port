/* FUN_00456de0 @ 00456de0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00456de0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = local_8 & 0xffff0000;
  while ((local_8 & 0xffff) < (uint)*(ushort *)(param_1 + 2)) {
    (*(code *)**(undefined4 **)(*param_1 + (local_8 & 0xffff) * 4))
              (*(undefined4 *)(*param_1 + (local_8 & 0xffff) * 4));
    __chkesp();
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  local_8 = local_8 & 0xffff0000;
  while ((local_8 & 0xffff) < (uint)*(ushort *)((int)param_1 + 10)) {
    (*(code *)**(undefined4 **)(param_1[1] + (local_8 & 0xffff) * 4))
              (*(undefined4 *)(param_1[1] + (local_8 & 0xffff) * 4));
    __chkesp();
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  FUN_00439c30((PVOID)*param_1);
  FUN_00439c30((PVOID)param_1[1]);
  FUN_00439c30(param_1);
  local_8 = 0x456eea;
  __chkesp();
  return;
}

