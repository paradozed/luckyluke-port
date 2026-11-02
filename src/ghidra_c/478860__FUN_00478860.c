/* FUN_00478860 @ 00478860 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00478860(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = param_3 + param_2 * 0x28;
  *(char *)(iVar1 + 0xc) = *(char *)(iVar1 + 0xc) + '\x01';
  *(char *)(iVar1 + 0x1c) = *(char *)(iVar1 + 0x1c) + '\x01';
  return;
}

