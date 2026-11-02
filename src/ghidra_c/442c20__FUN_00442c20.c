/* FUN_00442c20 @ 00442c20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442c20(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar1 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  if ((param_1 != 0) && (puVar1 = (undefined4 *)FUN_00494c40(0x14,1), puVar1 != (undefined4 *)0x0))
  {
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    *(undefined1 *)(puVar1 + 4) = param_4;
    if (*(int *)(param_1 + 0x210) == 0) {
      *(undefined4 **)(param_1 + 0x214) = puVar1;
      *(undefined4 **)(param_1 + 0x210) = puVar1;
      puVar1[1] = 0;
      *puVar1 = 0;
    }
    else {
      puVar1[1] = *(undefined4 *)(param_1 + 0x214);
      *puVar1 = 0;
      **(undefined4 **)(param_1 + 0x214) = puVar1;
      *(undefined4 **)(param_1 + 0x214) = puVar1;
    }
  }
  local_8 = 0x442cf9;
  __chkesp();
  return;
}

