/* FUN_004862e0 @ 004862e0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Type propagation algorithm not settling */

void __cdecl FUN_004862e0(int param_1,int param_2,short param_3)

{
  int iVar1;
  undefined2 extraout_var;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  uint local_10;
  short local_c;
  short local_a;
  short local_8;
  short local_6;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  local_a = 0;
  _local_8 = 0;
  local_10 = CONCAT22(local_10._2_2_,*(ushort *)(param_2 + 4));
  if (*(char *)(param_1 + 1) == '\a') {
    DAT_004e8adc = 1;
  }
  FUN_00470c70((uint)*(ushort *)(param_2 + 4),(undefined1 *)&local_c,(undefined1 *)&local_a);
  FUN_00470e20(local_10 & 0xffff,(byte *)&local_8,(byte *)&local_6);
  _local_8 = CONCAT22(local_6 + -2,local_8 + -2);
  local_c = local_c + 1;
  local_a = local_a + 1;
  FUN_00486160(param_1,&local_c);
  FUN_00486270(param_1,CONCAT22(extraout_var,(undefined2)local_10));
  local_c = *(short *)(param_2 + 8);
  local_a = *(short *)(param_2 + 10);
  FUN_00485e70(*(short **)(param_1 + 0x18),(int *)(param_1 + 0xa4),&local_c,param_3);
  DAT_004e8adc = 0;
  _local_8 = 0x486402;
  __chkesp();
  return;
}

