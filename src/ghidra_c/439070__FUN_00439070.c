/* FUN_00439070 @ 00439070 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439070(uint param_1,int param_2)

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
  local_8 = FUN_00438fa0(param_1,param_2);
  FUN_00439470(param_2);
  if (local_8 == 0) {
    FUN_004394e0(param_2);
  }
  local_8 = 0x4390d9;
  __chkesp();
  return;
}

