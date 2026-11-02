/* FUN_0046ed90 @ 0046ed90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046ed90(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [19];
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)(param_2 + 0x1e + param_4 * 0x20) = 0;
  *(ushort *)(param_2 + 0x1e + param_4 * 0x20) =
       *(ushort *)(param_2 + 0x1e + param_4 * 0x20) | 0x2200;
  return;
}

