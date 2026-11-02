/* FUN_00462e40 @ 00462e40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00462e40(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_7c [16];
  int *local_3c;
  int *local_38;
  int local_34 [6];
  int local_1c [5];
  undefined4 uStack_8;
  
  puVar2 = local_7c;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_38 = *(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_3c = *(int **)(*(int *)(DAT_004f2458 + 0xa0) + 8);
  FUN_00464fc0(local_3c,param_2 & 0xffff,local_1c);
  FUN_00465130(local_38,param_1 & 0xffff,local_34);
  FUN_0040d810(local_1c,local_34);
  uStack_8 = 0x462ed8;
  __chkesp();
  return;
}

