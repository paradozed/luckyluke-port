/* FUN_004011c0 @ 004011c0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004011c0(int param_1)

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
  local_8 = param_1;
  FUN_004259d0((undefined1 *)(param_1 + 0xe8));
  *(undefined4 *)(local_8 + 0x50) = 0;
  *(undefined4 *)(local_8 + 0x54) = 0;
  *(undefined4 *)(local_8 + 0xe4) = 0;
  local_8 = 0x40121c;
  __chkesp();
  return;
}

