/* FUN_0042a0e0 @ 0042a0e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042a0e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (int *)FUN_00497d00("win\\backinfo.dat","wb");
  if (local_8 != (int *)0x0) {
    for (local_c = 0; local_c < 0x1f; local_c = local_c + 1) {
      FUN_004983f0(*(uint *)(&DAT_004f79e0 + local_c * 0x1c),local_8);
      FUN_004983f0(*(uint *)(&DAT_004f79f0 + local_c * 0x1c),local_8);
      FUN_004983f0(*(uint *)(&DAT_004f79f4 + local_c * 0x1c),local_8);
      FUN_004983f0(*(uint *)(&DAT_004f79f8 + local_c * 0x1c),local_8);
      FUN_004983f0(*(uint *)(&DAT_004f79e4 + local_c * 0x1c),local_8);
      FUN_004983f0(*(uint *)(&DAT_004f79e8 + local_c * 0x1c),local_8);
      FUN_004983f0(*(uint *)(&DAT_004f79ec + local_c * 0x1c),local_8);
    }
    FUN_00497b30(local_8);
  }
  local_8 = (int *)0x42a201;
  __chkesp();
  return;
}

