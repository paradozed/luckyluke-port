/* FUN_00411750 @ 00411750 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00411750(void)

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
  FUN_00411200(local_20,&local_1c);
  *(undefined4 *)(DAT_004f2458 + 0x80) = local_1c;
  *(undefined4 *)(DAT_004f2458 + 0x84) = local_18;
  *(undefined4 *)(DAT_004f2458 + 0x88) = local_14;
  *(undefined4 *)(DAT_004f2458 + 0x8c) = local_10;
  *(undefined4 *)(DAT_004f2458 + 0x90) = local_c;
  *(undefined4 *)(DAT_004f2458 + 0x94) = local_8;
  local_8 = 0x4117f0;
  __chkesp();
  return;
}

