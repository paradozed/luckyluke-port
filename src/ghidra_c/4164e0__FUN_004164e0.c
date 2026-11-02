/* FUN_004164e0 @ 004164e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004164e0(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  void *local_c;
  void *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (void *)FUN_004226a0(&DAT_004d1da8,DAT_004d1d88);
  local_8 = (void *)FUN_00421420(local_c,(uint)*(ushort *)(param_1 + 0xc));
  FUN_00417250(local_8,1,param_2 & 0xff);
  local_8 = (void *)0x416540;
  __chkesp();
  return;
}

