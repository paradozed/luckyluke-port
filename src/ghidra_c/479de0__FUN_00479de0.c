/* FUN_00479de0 @ 00479de0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00479de0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  byte *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((*(byte *)**(undefined4 **)(param_1 + 8) & 2) != 0) {
    local_8 = (byte *)**(undefined4 **)(param_1 + 8);
    FUN_0047f140(local_8);
    *(undefined1 *)(param_1 + 0x11) = 1;
    *(code **)(param_1 + 4) = FUN_0047aae0;
    *(undefined1 *)(param_1 + 0x10) = 1;
    FUN_004164e0(param_1,0);
  }
  local_8 = (byte *)0x479e5b;
  __chkesp();
  return;
}

