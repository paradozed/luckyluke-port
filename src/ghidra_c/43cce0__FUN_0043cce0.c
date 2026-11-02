/* FUN_0043cce0 @ 0043cce0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043cce0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  undefined4 *local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    if (*(int *)(param_1 + 0x58) == 0) {
      uVar1 = FUN_00494c40(4,1);
      *(undefined4 *)(param_1 + 0x5c) = uVar1;
      if (*(int *)(param_1 + 0x5c) != 0) {
        *(undefined4 *)(param_1 + 0x58) = 1;
        **(int **)(param_1 + 0x5c) = param_2;
      }
    }
    else {
      local_c = *(int *)(param_1 + 0x58) + 1;
      local_8 = (undefined4 *)FUN_00494c40(local_c * 4,1);
      if (local_8 != (undefined4 *)0x0) {
        FUN_00497690(local_8,*(undefined4 **)(param_1 + 0x5c),local_c * 4 - 4);
        local_8[local_c + -1] = param_2;
        if (*(int *)(param_1 + 0x5c) != -0x22222223) {
          FUN_00495280(*(void **)(param_1 + 0x5c));
        }
        *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
        *(undefined4 **)(param_1 + 0x5c) = local_8;
      }
    }
  }
  local_8 = (undefined4 *)0x43cdea;
  __chkesp();
  return;
}

