/* FUN_00478780 @ 00478780 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00478780(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = param_3 + param_2 * 0x20;
  *(undefined1 *)(iVar1 + 0xc) = 0x81;
  *(undefined1 *)(iVar1 + 0xd) = 0xec;
  *(undefined1 *)(iVar1 + 0x14) = 0x8f;
  *(undefined1 *)(iVar1 + 0x15) = 0xec;
  *(undefined1 *)(iVar1 + 0x1c) = 0x81;
  *(undefined1 *)(iVar1 + 0x1d) = 0xf6;
  return;
}

