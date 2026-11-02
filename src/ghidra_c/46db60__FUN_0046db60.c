/* FUN_0046db60 @ 0046db60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046db60(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int *local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (int *)FUN_0046da50(param_1);
  local_8 = FUN_0046d930(param_1);
  if (local_8 != 0) {
    if (local_c[6] != -0x22222223) {
      FUN_00495280((void *)local_c[6]);
    }
    FUN_0046df80(local_c,DAT_004f2288);
  }
  local_8 = 0x46dbda;
  __chkesp();
  return;
}

