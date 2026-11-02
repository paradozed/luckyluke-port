/* FUN_0040dd00 @ 0040dd00 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0040dd00(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_20 = **(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_1c = *(undefined4 *)(DAT_004f2458 + 0x80);
  local_18 = *(undefined4 *)(DAT_004f2458 + 0x84);
  local_14 = *(undefined4 *)(DAT_004f2458 + 0x88);
  local_10 = *(undefined4 *)(DAT_004f2458 + 0x8c);
  local_c = *(undefined4 *)(DAT_004f2458 + 0x90);
  local_8 = *(undefined4 *)(DAT_004f2458 + 0x94);
  FUN_0040e410(local_20,&local_1c);
  local_8 = 0x40dda0;
  __chkesp();
  return;
}

