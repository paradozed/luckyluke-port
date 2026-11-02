/* FUN_0046dd60 @ 0046dd60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046dd60(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_0046d930(param_1[3]);
  if (local_8 != 0) {
    if (param_1[6] != -0x22222223) {
      FUN_00495280((void *)param_1[6]);
    }
    FUN_0046df80(param_1,DAT_004f2288);
  }
  local_8 = 0x46ddcb;
  __chkesp();
  return;
}

