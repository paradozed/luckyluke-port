/* FUN_00417fb0 @ 00417fb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00417fb0(undefined4 *param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)(param_1 + 3) = param_3;
  param_1[1] = FUN_0047aae0;
  *(undefined1 *)(param_1 + 4) = 1;
  *param_1 = FUN_0047ab10;
  *(undefined1 *)((int)param_1 + 0x11) = 1;
  param_1[2] = param_2;
  *(ushort *)((int)param_1 + 0xe) = *(ushort *)((int)param_1 + 0xe) | 1;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 5) = 1;
  return;
}

