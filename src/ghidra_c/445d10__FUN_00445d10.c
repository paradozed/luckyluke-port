/* FUN_00445d10 @ 00445d10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00445d10(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(param_1 + 0x10) = *param_2;
  *(undefined1 *)(param_1 + 0x11) = param_2[1];
  *(undefined1 *)(param_1 + 0x12) = param_2[2];
  *(undefined1 *)(param_1 + 0x18) = param_2[3];
  *(undefined1 *)(param_1 + 0x19) = param_2[4];
  *(undefined1 *)(param_1 + 0x1a) = param_2[5];
  *(undefined1 *)(param_1 + 0x20) = param_2[6];
  *(undefined1 *)(param_1 + 0x21) = param_2[7];
  *(undefined1 *)(param_1 + 0x22) = param_2[8];
  *(undefined1 *)(param_1 + 0x28) = param_2[9];
  *(undefined1 *)(param_1 + 0x29) = param_2[10];
  *(undefined1 *)(param_1 + 0x2a) = param_2[0xb];
  return;
}

