/* FUN_00439000 @ 00439000 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439000(uint param_1)

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
  local_8 = FUN_00438ce0(param_1);
  FUN_00439470(DAT_004e84d0);
  if (local_8 == 0) {
    FUN_004394e0(DAT_004e84d0);
  }
  local_8 = 0x43906a;
  __chkesp();
  return;
}

