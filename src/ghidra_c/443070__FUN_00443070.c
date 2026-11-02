/* FUN_00443070 @ 00443070 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00443070(int param_1,char *param_2)

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
  local_8 = *(undefined4 **)(param_1 + 0x210);
  while ((local_8 != (undefined4 *)0x0 && (iVar1 = _strcmp((char *)local_8[2],param_2), iVar1 != 0))
        ) {
    local_8 = (undefined4 *)*local_8;
  }
  local_8 = (undefined4 *)0x4430cf;
  __chkesp();
  return;
}

