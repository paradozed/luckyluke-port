/* FUN_0046ef20 @ 0046ef20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046ef20(int *param_1,uint param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(*(int *)(*(int *)(*param_1 + (param_2 & 0xffff) * 4) + 4) + 0x13) = param_3;
  return;
}

