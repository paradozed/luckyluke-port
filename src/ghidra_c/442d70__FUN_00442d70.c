/* FUN_00442d70 @ 00442d70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442d70(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = *(undefined4 **)(param_2 + 0x210);
      (local_8 != (undefined4 *)0x0 && (local_8[3] != param_3)); local_8 = (undefined4 *)*local_8) {
  }
  if (local_8 != (undefined4 *)0x0) {
    FUN_00498130(param_1,(byte *)"%s = %d");
  }
  local_8 = (undefined4 *)0x442de9;
  __chkesp();
  return;
}

