/* FUN_0046f780 @ 0046f780 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0046f780(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined1 param_9,
            undefined1 param_10)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  *(undefined4 *)(param_1 + 0x20) = param_5;
  *(undefined4 *)(param_1 + 0x24) = param_6;
  *(undefined4 *)(param_1 + 0x28) = param_7;
  *(undefined4 *)(param_1 + 0x10) = param_8;
  *(undefined1 *)(param_1 + 7) = param_9;
  *(undefined1 *)(param_1 + 6) = param_10;
  return;
}

