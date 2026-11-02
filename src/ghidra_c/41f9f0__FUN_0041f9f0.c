/* FUN_0041f9f0 @ 0041f9f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041f9f0(char param_1,short param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  ushort local_c;
  undefined2 uStack_a;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004bcfd0 != 0) && (param_1 != '\0')) {
    local_8 = *(int *)(&DAT_004d2390 + (uint)(byte)(param_1 - 1U) * 0x10);
    _local_c = CONCAT22(uStack_a,*(ushort *)(&DAT_004d2396 + (uint)(byte)(param_1 - 1U) * 0x10));
    FUN_004933d0(local_8,(uint)*(ushort *)(&DAT_004d2396 + (uint)(byte)(param_1 - 1U) * 0x10) +
                         (int)param_2);
  }
  local_8 = 0x41fa7c;
  __chkesp();
  return;
}

