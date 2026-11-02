/* FUN_004269f0 @ 004269f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004269f0(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  uint local_c;
  char local_8;
  undefined1 local_7 [3];
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  _local_8 = 0;
  local_c = local_c & 0xffff0000;
  while ((local_c & 0xffff) < 0x100) {
    _local_8 = CONCAT31(CONCAT21(CONCAT11(local_7[2],(undefined1)local_c),(undefined1)local_c),
                        (undefined1)local_c);
    uVar1 = FUN_00497d20(&local_8,4,1,param_1);
    if (uVar1 != 1) break;
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  _local_8 = 0x426a71;
  __chkesp();
  return;
}

