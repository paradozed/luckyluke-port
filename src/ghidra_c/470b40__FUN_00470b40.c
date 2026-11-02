/* FUN_00470b40 @ 00470b40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470b40(int param_1,ushort param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 != 0) {
    if ((uint)param_2 < **(int **)(param_1 + 0xc) - 1U) {
      FUN_004700c0(param_1,0,param_2);
    }
    else {
      uVar1 = *(undefined2 *)(*(int *)(param_1 + 0xc) + 0x10 + ((short)param_2 + -1) * 0x10);
      local_8 = CONCAT22(local_8._2_2_,uVar1);
      FUN_004700c0(param_1,uVar1,param_2 - 1);
    }
  }
  local_8 = 0x470bcb;
  __chkesp();
  return;
}

